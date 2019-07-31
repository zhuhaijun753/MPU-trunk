/******************************************************
�ļ�����	PrvtProt_VehiSt.c

������	��ҵ˽��Э�飨�㽭���ڣ�	
Data			Vasion			author
2018/1/10		V1.0			liujian
*******************************************************/

/*******************************************************
description�� include the header file
*******************************************************/
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include  <errno.h>
#include <sys/times.h>
#include <sys/time.h>
#include "timer.h"
#include <sys/prctl.h>

#include <sys/types.h>
#include <sysexits.h>	/* for EX_* exit codes */
#include <assert.h>	/* for assert(3) */
#include "constr_TYPE.h"
#include "asn_codecs.h"
#include "asn_application.h"
#include "asn_internal.h"	/* for _ASN_DEFAULT_STACK_MAX */
#include "XcallReqinfo.h"
#include "Bodyinfo.h"
#include "per_encoder.h"
#include "per_decoder.h"

#include "init.h"
#include "log.h"
#include "list.h"
#include "../../support/protocol.h"
#include "../sockproxy/sockproxy_txdata.h"
#include "gb32960_api.h"
#include "hozon_SP_api.h"
#include "hozon_PP_api.h"
#include "shell_api.h"
#include "PrvtProt_shell.h"
#include "PrvtProt_queue.h"
#include "PrvtProt_EcDc.h"
#include "PrvtProt_cfg.h"
#include "PrvtProt.h"
#include "remoteControl/PPrmtCtrl_cfg.h"
#include "PrvtProt_SigParse.h"
#include "PrvtProt_VehiSt.h"

/*******************************************************
description�� global variable definitions
*******************************************************/

/*******************************************************
description�� static variable definitions
*******************************************************/
typedef struct
{
	PrvtProt_pack_Header_t	Header;
	PrvtProt_DisptrBody_t	DisBody;
}__attribute__((packed))  PrvtProt_VS_pack_t; /**/

typedef struct
{
	PrvtProt_VS_pack_t 		pack;
	PrvtProt_VSSt_t	 		state;
}__attribute__((packed))  PrvtProt_VS_t; /*�ṹ��*/

static PrvtProt_pack_t 		PP_VS_Pack;
static PrvtProt_VS_t		PP_rmtVS;
static PrvtProt_App_VS_t	PP_VS_appdata;

static PrvtProt_TxInform_t VS_TxInform;
/*******************************************************
description�� function declaration
*******************************************************/
/*Global function declaration*/

/*Static function declaration*/
static int PP_VS_do_checksock(PrvtProt_task_t *task);
static int PP_VS_do_rcvMsg(PrvtProt_task_t *task);
static void PP_VS_RxMsgHandle(PrvtProt_task_t *task,PrvtProt_pack_t* rxPack,int len);
static int PP_VS_do_wait(PrvtProt_task_t *task);
static int PP_VS_do_VehiStMainfunction(PrvtProt_task_t *task);
static int PP_VS_VehiStatusResp(PrvtProt_task_t *task,PrvtProt_VS_t *rmtVS);

static void PP_VS_send_cb(void * para);

/******************************************************
description�� function code
******************************************************/
/******************************************************
*��������PP_VS_init

*��  �Σ�void

*����ֵ��void

*��  ������ʼ��

*��  ע��
******************************************************/
void PP_VS_init(void)
{
	memset(&PP_rmtVS,0 , sizeof(PrvtProt_VS_t));
	memcpy(PP_rmtVS.pack.Header.sign,"**",2);
	PP_rmtVS.pack.Header.ver.Byte = 0x30;
	PP_rmtVS.pack.Header.commtype.Byte = 0xe1;
	PP_rmtVS.pack.Header.opera = 0x02;
	PP_rmtVS.pack.Header.tboxid = 27;
	memcpy(PP_rmtVS.pack.DisBody.aID,"130",strlen("130"));
	PP_rmtVS.pack.DisBody.eventId = PP_INIT_EVENTID;
	PP_rmtVS.pack.DisBody.appDataProVer = 256;
	PP_rmtVS.pack.DisBody.testFlag = 1;
	PP_rmtVS.state.req = PP_VS_NOREQ;
	memset(&VS_TxInform,0,sizeof(PrvtProt_TxInform_t));
}

/******************************************************
*��������PP_VS_mainfunction

*��  �Σ�void

*����ֵ��void

*��  ������������

*��  ע��
******************************************************/
int PP_VS_mainfunction(void *task)
{
	int res;
	res = 		PP_VS_do_checksock((PrvtProt_task_t*)task) ||
				PP_VS_do_rcvMsg((PrvtProt_task_t*)task) ||
				PP_VS_do_wait((PrvtProt_task_t*)task) ||
				PP_VS_do_VehiStMainfunction((PrvtProt_task_t*)task);
	return res;
}

/******************************************************
*��������PP_VS_do_checksock

*��  �Σ�void

*����ֵ��void

*��  �������socket����

*��  ע��
******************************************************/
static int PP_VS_do_checksock(PrvtProt_task_t *task)
{
	if(1 == sockproxy_socketState())//socket open
	{

		return 0;
	}
	return -1;
}

/******************************************************
*��������PP_VS_do_rcvMsg

*��  �Σ�void

*����ֵ��void

*��  �����������ݺ���

*��  ע��
******************************************************/
static int PP_VS_do_rcvMsg(PrvtProt_task_t *task)
{	
	int rlen = 0;
	PrvtProt_pack_t rcv_pack;
	memset(&rcv_pack,0 , sizeof(PrvtProt_pack_t));
	if ((rlen = RdPP_queue(PP_REMOTE_VS,rcv_pack.Header.sign,sizeof(PrvtProt_pack_t))) <= 0)
    {
		return 0;
	}
	
	log_i(LOG_HOZON, "receive vehi status message");
	protocol_dump(LOG_HOZON, "PRVT_PROT", rcv_pack.Header.sign, rlen, 0);
	if((rcv_pack.Header.sign[0] != 0x2A) || (rcv_pack.Header.sign[1] != 0x2A) || \
			(rlen <= 18))//�ж�����֡ͷ����������ݳ��Ȳ���
	{
		return 0;
	}
	
	if(rlen > (18 + PP_MSG_DATA_LEN))//�������ݳ��ȳ�������buffer����
	{
		return 0;
	}
	PP_VS_RxMsgHandle(task,&rcv_pack,rlen);

	return 0;
}

/******************************************************
*��������PP_VS_RxMsgHandle

*��  �Σ�void

*����ֵ��void

*��  �����������ݴ���

*��  ע��
******************************************************/
static void PP_VS_RxMsgHandle(PrvtProt_task_t *task,PrvtProt_pack_t* rxPack,int len)
{
	int aid;
	if(PP_OPERATETYPE_NGTP != rxPack->Header.opera)
	{
		log_e(LOG_HOZON, "unknow package");
		return;
	}

	PrvtProt_DisptrBody_t MsgDataBody;
	PrvtProt_App_VS_t Appdata;
	PrvtPro_decodeMsgData(rxPack->msgdata,(len - 18),&MsgDataBody,&Appdata);
	aid = (MsgDataBody.aID[0] - 0x30)*100 +  (MsgDataBody.aID[1] - 0x30)*10 + \
			  (MsgDataBody.aID[2] - 0x30);
	if(PP_AID_VS != aid)
	{
		log_e(LOG_HOZON, "aid unmatch");
		return;
	}

	switch(MsgDataBody.mID)
	{
		case PP_MID_VS_REQ://�յ�tsp��ѯ����
		{
			PP_rmtVS.state.req = Appdata.VSReq.vehStatusReqType;
			PP_rmtVS.pack.DisBody.eventId = MsgDataBody.eventId;
		}
		break;
		default:
		break;
	}
}

/******************************************************
*��������PP_xcall_do_wait

*��  �Σ�void

*����ֵ��void

*��  ��������Ƿ����¼��ȴ�Ӧ��

*��  ע��
******************************************************/
static int PP_VS_do_wait(PrvtProt_task_t *task)
{
	return 0;
}

/******************************************************
*��������PP_xcall_do_checkXcall

*��  �Σ�

*����ֵ��

*��  �������ecall������

*��  ע��
******************************************************/
static int PP_VS_do_VehiStMainfunction(PrvtProt_task_t *task)
{

	if(1 != sockproxy_socketState())//socket not open
	{
		return 0;
		PP_rmtVS.state.req = PP_VS_NOREQ;
	}

	switch(PP_rmtVS.state.req)
	{
		case PP_VS_NOREQ:
		break;
		case PP_VS_BASICSTATUS:
		{
			PP_VS_appdata.VSResp.ExtSt.validFlg = 0;//
			if(0 == PP_VS_VehiStatusResp(task,&PP_rmtVS))
			{
				memset(&VS_TxInform,0,sizeof(PrvtProt_TxInform_t));
				VS_TxInform.aid = PP_AID_VS;
				VS_TxInform.mid = PP_MID_VS_RESP;
				VS_TxInform.pakgtype = PP_TXPAKG_SIGTIME;
				VS_TxInform.eventtime = tm_get_time();

				SP_data_write(PP_VS_Pack.Header.sign,PP_VS_Pack.totallen,PP_VS_send_cb,&VS_TxInform);
				protocol_dump(LOG_HOZON, "PP_VS_BASICSTATUS", PP_VS_Pack.Header.sign,PP_VS_Pack.totallen,1);
			}
			PP_rmtVS.state.req = PP_VS_NOREQ;
		}
		break;
		case PP_VS_EXTSTATUS:
		{
			PP_VS_appdata.VSResp.ExtSt.validFlg = 1;//report extended Vehicle Status
			if(0 == PP_VS_VehiStatusResp(task,&PP_rmtVS))
			{
				memset(&VS_TxInform,0,sizeof(PrvtProt_TxInform_t));
				VS_TxInform.aid = PP_AID_VS;
				VS_TxInform.mid = PP_MID_VS_RESP;
				VS_TxInform.pakgtype = PP_TXPAKG_SIGTIME;
				VS_TxInform.eventtime = tm_get_time();

				SP_data_write(PP_VS_Pack.Header.sign,PP_VS_Pack.totallen,PP_VS_send_cb,&VS_TxInform);
				protocol_dump(LOG_HOZON, "PP_VS_EXTSTATUS", PP_VS_Pack.Header.sign,PP_VS_Pack.totallen,1);
			}
			PP_rmtVS.state.req = PP_VS_NOREQ;
		}
		break;
		default:
		break;
	}

	return 0;
}

/******************************************************
*��������PP_VS_VehiStatusResp

*��  �Σ�

*����ֵ��

*��  ����remote vehi status response

*��  ע��
******************************************************/
static int PP_VS_VehiStatusResp(PrvtProt_task_t *task,PrvtProt_VS_t *rmtVS)
{
	int msgdatalen;
	int res = 0;
	/*header*/
	rmtVS->pack.Header.ver.Byte = task->version;
	rmtVS->pack.Header.nonce  = PrvtPro_BSEndianReverse((uint32_t)task->nonce);
	rmtVS->pack.Header.tboxid = PrvtPro_BSEndianReverse((uint32_t)task->tboxid);
	memcpy(&PP_VS_Pack, &rmtVS->pack.Header, sizeof(PrvtProt_pack_Header_t));
	/*body*/
	rmtVS->pack.DisBody.mID = PP_MID_VS_RESP;
	//rmtVS->pack.DisBody.eventId = PP_AID_RMTCTRL + PP_MID_RMTCTRL_RESP;
	rmtVS->pack.DisBody.eventTime = PrvtPro_getTimestamp();
	rmtVS->pack.DisBody.expTime   = PrvtPro_getTimestamp();
	rmtVS->pack.DisBody.ulMsgCnt++;	/* OPTIONAL */

	/*appdata*/
	PrvtProtcfg_gpsData_t gpsDt;
	PP_VS_appdata.VSResp.statusTime = PrvtPro_getTimestamp();//0��ʾ����ִ��

	PP_VS_appdata.VSResp.gpsPos.gpsSt = PrvtProtCfg_gpsStatus();//gps״̬ 0-��Ч��1-��Ч;
	PP_VS_appdata.VSResp.gpsPos.gpsTimestamp = PrvtPro_getTimestamp();//gpsʱ���:ϵͳʱ��(ͨ��gpsУʱ)

	PrvtProtCfg_gpsData(&gpsDt);

	if(PP_VS_appdata.VSResp.gpsPos.gpsSt == 1)
	{
		if(gpsDt.is_north)
		{
			PP_VS_appdata.VSResp.gpsPos.latitude = (long)(gpsDt.latitude*10000);//γ�� x 1000000,��GPS�ź���Чʱ��ֵΪ0
		}
		else
		{
			PP_VS_appdata.VSResp.gpsPos.latitude = (long)(gpsDt.latitude*10000*(-1));//γ�� x 1000000,��GPS�ź���Чʱ��ֵΪ0
		}

		if(gpsDt.is_east)
		{
			PP_VS_appdata.VSResp.gpsPos.longitude = (long)(gpsDt.longitude*10000);//���� x 1000000,��GPS�ź���Чʱ��ֵΪ0
		}
		else
		{
			PP_VS_appdata.VSResp.gpsPos.longitude = (long)(gpsDt.longitude*10000*(-1));//���� x 1000000,��GPS�ź���Чʱ��ֵΪ0
		}
		log_i(LOG_HOZON, "PP_appData.latitude = %lf",PP_VS_appdata.VSResp.gpsPos.latitude);
		log_i(LOG_HOZON, "PP_appData.longitude = %lf",PP_VS_appdata.VSResp.gpsPos.longitude);
	}
	else
	{
		PP_VS_appdata.VSResp.gpsPos.latitude  = 0;
		PP_VS_appdata.VSResp.gpsPos.longitude = 0;
	}
	PP_VS_appdata.VSResp.gpsPos.altitude = (long)(gpsDt.height);//�߶ȣ�m��
	if(PP_VS_appdata.VSResp.gpsPos.altitude > 10000)
	{
		PP_VS_appdata.VSResp.gpsPos.altitude = 10000;
	}
	PP_VS_appdata.VSResp.gpsPos.heading = (long)(gpsDt.direction);//��ͷ����Ƕȣ�0Ϊ��������
	PP_VS_appdata.VSResp.gpsPos.gpsSpeed = (long)(gpsDt.kms*10);//�ٶ� x 10����λkm/h
	PP_VS_appdata.VSResp.gpsPos.hdop = (long)(gpsDt.hdop*10);//ˮƽ�������� x 10
	if(PP_VS_appdata.VSResp.gpsPos.hdop > 1000)
	{
		PP_VS_appdata.VSResp.gpsPos.hdop = 1000;
	}

	PP_VS_appdata.VSResp.basicSt.driverDoor 		= 1	/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.driverLock 		= PP_rmtCtrl_cfg_doorlockSt();
	PP_VS_appdata.VSResp.basicSt.passengerDoor 		= 1	/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.passengerLock 		= PP_rmtCtrl_cfg_doorlockSt();
	PP_VS_appdata.VSResp.basicSt.rearLeftDoor 		= 1	/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.rearLeftLock 		= PP_rmtCtrl_cfg_doorlockSt();
	PP_VS_appdata.VSResp.basicSt.rearRightDoor 		= 1	/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.rearRightLock 		= PP_rmtCtrl_cfg_doorlockSt();
	PP_VS_appdata.VSResp.basicSt.bootStatus 		= gb_data_reardoorSt()	/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.bootStatusLock 	= gb_data_reardoorlockSt();
	PP_VS_appdata.VSResp.basicSt.driverWindow 		= 1	/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.passengerWindow 	= 1	/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.rearLeftWindow 	= 1	/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.rearRightWinow 	= 1	/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.sunroofStatus 		= PP_rmtCtrl_cfg_sunroofSt()	/* OPTIONAL */;
	if(PP_rmtCtrl_cfg_RmtStartSt() == 0)
	{
		PP_VS_appdata.VSResp.basicSt.engineStatus = 0;
	}
	else
	{
		PP_VS_appdata.VSResp.basicSt.engineStatus = 1;
	}
	PP_VS_appdata.VSResp.basicSt.accStatus 			= PP_rmtCtrl_cfg_ACOnOffSt();
	PP_VS_appdata.VSResp.basicSt.accTemp 			= gb_data_ACTemperature()	/* OPTIONAL */;//16-32
	if(PP_VS_appdata.VSResp.basicSt.accTemp < PP_VS_LOW_TEMP)
	{
		PP_VS_appdata.VSResp.basicSt.accTemp = PP_VS_LOW_TEMP;
	}
	else if(PP_VS_appdata.VSResp.basicSt.accTemp > PP_VS_HIGH_TEMP)
	{
		PP_VS_appdata.VSResp.basicSt.accTemp = PP_VS_HIGH_TEMP;
	}
	else
	{}
	PP_VS_appdata.VSResp.basicSt.accMode 			= gb_data_ACMode()	/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.accBlowVolume		= gb_data_BlowerGears()/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.innerTemp 			= gb_data_InnerTemp();
	PP_VS_appdata.VSResp.basicSt.outTemp 			= gb_data_outTemp();
	PP_VS_appdata.VSResp.basicSt.sideLightStatus	= gb_data_PostionLampSt();
	PP_VS_appdata.VSResp.basicSt.dippedBeamStatus	= gb_data_NearLampSt();
	PP_VS_appdata.VSResp.basicSt.mainBeamStatus		= gb_data_HighbeamLampSt();
	PP_VS_appdata.VSResp.basicSt.hazardLightStus	= gb_data_TwinFlashLampSt();//双闪灯
	PP_VS_appdata.VSResp.basicSt.frtRightTyrePre	= gb_data_frontRightTyrePre()/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.frtRightTyreTemp	= gb_data_frontRightTyreTemp()/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.frontLeftTyrePre	= gb_data_frontLeftTyrePre()/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.frontLeftTyreTemp	= gb_data_frontLeftTyreTemp()	/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.rearRightTyrePre	= gb_data_rearRightTyrePre()/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.rearRightTyreTemp	= gb_data_rearRightTyreTemp()	/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.rearLeftTyrePre	= gb_data_rearLeftTyrePre()/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.rearLeftTyreTemp	= gb_data_rearLeftTyreTemp()/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.batterySOCExact	= gb_data_vehicleSOC() * 100;
	PP_VS_appdata.VSResp.basicSt.chargeRemainTim	= gb_data_ACChargeRemainTime()/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.availableOdomtr	= gb_data_ResidualOdometer();//续航里程
	PP_VS_appdata.VSResp.basicSt.engineRunningTime	= 1/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.bookingChargeSt	= GetPP_ChargeCtrl_appointSt();
	PP_VS_appdata.VSResp.basicSt.bookingChargeHour	= GetPP_ChargeCtrl_appointHour()	/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.bookingChargeMin	= GetPP_ChargeCtrl_appointMin()/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.chargeMode			= PrvtProtCfg_chargeSt()/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.chargeStatus 		= gb_data_chargestauus();
	PP_VS_appdata.VSResp.basicSt.powerMode			= gb_data_powermode();
	PP_VS_appdata.VSResp.basicSt.speed				= gb_data_vehicleSpeed();
	PP_VS_appdata.VSResp.basicSt.totalOdometer		= gb_data_vehicleOdograph();
	PP_VS_appdata.VSResp.basicSt.batteryVoltage		= gb_data_batteryVoltage();
	PP_VS_appdata.VSResp.basicSt.batteryCurrent		= gb_data_batteryCurrent();
	PP_VS_appdata.VSResp.basicSt.batterySOCPrc		= gb_data_vehicleSOC();
	PP_VS_appdata.VSResp.basicSt.dcStatus			= 1;
	PP_VS_appdata.VSResp.basicSt.gearPosition		= gb_data_gearPosition();
	PP_VS_appdata.VSResp.basicSt.insulationRstance	= gb_data_insulationResistance();
	PP_VS_appdata.VSResp.basicSt.acceleratePedalprc	= gb_data_acceleratePedalPrc();
	PP_VS_appdata.VSResp.basicSt.deceleratePedalprc	= gb_data_deceleratePedalPrc();
	PP_VS_appdata.VSResp.basicSt.canBusActive		= gb_data_CanbusActiveSt();
	PP_VS_appdata.VSResp.basicSt.bonnetStatus		= 1;
	PP_VS_appdata.VSResp.basicSt.lockStatus			= PP_rmtCtrl_cfg_doorlockSt();
	PP_VS_appdata.VSResp.basicSt.gsmStatus			= gb32960_networkSt();
	PP_VS_appdata.VSResp.basicSt.wheelTyreMotrSt	= 1	/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.vehicleAlarmSt		= 1;
	PP_VS_appdata.VSResp.basicSt.currentJourneyID	= 1;
	PP_VS_appdata.VSResp.basicSt.journeyOdom		= PP_rmtCtrl_cfg_vehicleOdograph(); /*里程*/
	PP_VS_appdata.VSResp.basicSt.frtLeftSeatHeatLel	= PP_rmtCtrl_cfg_DrivHeatingSt()	/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.frtRightSeatHeatLel = PP_rmtCtrl_cfg_PassHeatingSt()/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.airCleanerSt		= PrvtProt_SignParse_pm25valid()/* OPTIONAL */;
	PP_VS_appdata.VSResp.basicSt.srsStatus 			= PrvtProtCfg_CrashOutputSt();

	uint8_t i;
	if(PP_VS_appdata.VSResp.ExtSt.validFlg == 1)//上报故障报警
	{
		log_i(LOG_HOZON, "read warn status\n");
		PP_VS_appdata.VSResp.ExtSt.alertSize = 0;//
		for(i = 0;i < GB32960_API_FAULTNUM;i++)
		{
			if(gb_fault.warn[i])
			{
				PP_VS_appdata.VSResp.ExtSt.alertIds[PP_VS_appdata.VSResp.ExtSt.alertSize] = i;
				log_i(LOG_HOZON, "PP_VS_appdata.VSResp.ExtSt.alertIds[%d] = %d\n",PP_VS_appdata.VSResp.ExtSt.alertSize,i);
				PP_VS_appdata.VSResp.ExtSt.alertSize++;
			}
		}
	}

	if(0 != PrvtPro_msgPackageEncoding(ECDC_RMTVS_RESP,PP_VS_Pack.msgdata,&msgdatalen,\
									   &rmtVS->pack.DisBody,&PP_VS_appdata))//���ݱ������Ƿ����
	{
		log_e(LOG_HOZON, "uper error");
		return -1;
	}

	PP_VS_Pack.totallen = 18 + msgdatalen;
	PP_VS_Pack.Header.msglen = PrvtPro_BSEndianReverse((long)(18 + msgdatalen));

	return res;
}

/******************************************************
*��������PP_VS_SetVSReq

*��  �Σ�

*����ֵ��

*��  ��������ecall ����

*��  ע��
******************************************************/
void PP_VS_SetVSReq(unsigned char req)
{
	PP_rmtVS.state.req = req;
	PP_rmtVS.pack.DisBody.eventId = 130+2;
}

/******************************************************
*��������PP_VS_send_cb

*��  �Σ�

*����ֵ��

*��  ����

*��  ע��
******************************************************/
static void PP_VS_send_cb(void * para)
{
	PrvtProt_TxInform_t *TxInform_ptr = (PrvtProt_TxInform_t*)para;
	log_i(LOG_HOZON, "aid = %d",TxInform_ptr->aid);
	log_i(LOG_HOZON, "mid = %d",TxInform_ptr->mid);
	log_i(LOG_HOZON, "pakgtype = %d",TxInform_ptr->pakgtype);
	log_i(LOG_HOZON, "eventtime = %d",TxInform_ptr->eventtime);
	log_i(LOG_HOZON, "successflg = %d",TxInform_ptr->successflg);
	log_i(LOG_HOZON, "failresion = %d",TxInform_ptr->failresion);
	log_i(LOG_HOZON, "txfailtime = %d",TxInform_ptr->txfailtime);
}
