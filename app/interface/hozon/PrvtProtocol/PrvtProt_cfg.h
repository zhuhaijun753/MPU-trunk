/******************************************************
�ļ�����	PrvtProt_cfg.h

������	��ҵ˽��Э�飨�㽭���ڣ�	

Data			  Vasion			author
2019/04/16		   V1.0			    liujian
*******************************************************/
#ifndef		_PRVTPROT_CFG_H
#define		_PRVTPROT_CFG_H
/*******************************************************
description�� include the header file
*******************************************************/

/*******************************************************
description�� macro definitions
*******************************************************/
/**********�꿪�ض���*********/
#define PP_THREAD   1//�����Ƿ񵥶������߳� 1-�� 0-����
#define PP_SOCKPROXY   1//�����Ƿ�ʹ��socket����(�Ƿ�������ģ�鴴��socket��·) 1-�� 0-����
/**********�곣������*********/
#define PP_HEART_BEAT_TIME (10)//��������

#define PP_HB_WAIT_TIMEOUT 	(5*1000)//�����ȴ���ʱʱ��
#define PP_XCALL_WAIT_TIMEOUT 	(5*1000)//�ȴ���ʱʱ��
#define	PP_INVALID		0xFFFFFFFF

/***********�꺯��***********/


/*******************************************************
description�� struct definitions
*******************************************************/
typedef struct
{
    unsigned int date;
    double time;
    double longitude;
    unsigned int is_east;
    double latitude;
    unsigned int is_north;
    double direction;
    double knots;       // 1kn = 1 mile/h = 1.852 km/h
    double kms;         // 1km/h = 0.5399kn
    double height;
    double hdop;
    double vdop;
}PrvtProtcfg_gpsData_t;
/*******************************************************
description�� typedef definitions
*******************************************************/
/******enum definitions******/

/******union definitions*****/

/*******************************************************
description�� variable External declaration
*******************************************************/

/*******************************************************
description�� function External declaration
*******************************************************/
extern int PrvtProtCfg_rcvMsg(unsigned char* buf,int buflen);
extern int PrvtProtCfg_ecallTriggerEvent(void);
extern int PrvtProtCfg_gpsStatus(void);
extern long PrvtProtCfg_engineSt(void);
extern long PrvtProtCfg_totalOdoMr(void);
extern long PrvtProtCfg_vehicleSOC(void);
extern void PrvtProtCfg_gpsData(PrvtProtcfg_gpsData_t *gpsDt);
#endif 