/******************************************************
�ļ�����	PrvtProt_EcDc.h

������	��ҵ˽��Э�飨�㽭���ڣ�	

Data			  Vasion			author
2019/4/29		V1.0			liujian
*******************************************************/
#ifndef		_PRVTPROT_ECDC_H
#define		_PRVTPROT_ECDC_H
/*******************************************************
description�� include the header file
*******************************************************/


/*******************************************************
description�� macro definitions
*******************************************************/
/**********�꿪�ض���*********/

/**********�곣������*********/
#define PP_ECDC_DATA_LEN 	512//����

#define PP_ENCODE_DISBODY 	0x01//����dispatcher header
#define PP_ENCODE_APPDATA 	0x02//����app data

//AID����
#define PP_AID_XCALL 	170//Xcall

//MID����
#define PP_MID_XCALL_REQ 	1//Xcall request
#define PP_MID_XCALL_RESP 	2//Xcall response

/***********�꺯��***********/

/*******************************************************
description�� struct definitions
*******************************************************/

/*******************************************************
description�� typedef definitions
*******************************************************/
/******enum definitions******/

/*****struct definitions*****/

/******union definitions*****/

/*******************************************************
description�� variable External declaration
*******************************************************/

/*******************************************************
description�� function External declaration
*******************************************************/
extern int PrvtPro_msgPackageEncoding(uint8_t type,uint8_t *msgData,long *msgDataLen, \
							  void *disptrBody, void *appchoice);
extern void PrvtPro_decodeMsgData(uint8_t *LeMessageData,int LeMessageDataLen, \
								  void *MsgData,int isdecodeAppdata);
#endif 