#ifndef __UDEF_CFG_API_H__
#define __UDEF_CFG_API_H__

#include "init.h"


typedef enum 
{
    /* GB32960 Configuration */
    CFG_ITEM_GB32960_VIN = 0,
    CFG_ITEM_GB32960_URL,
    CFG_ITEM_GB32960_PORT,
    CFG_ITEM_GB32960_INTERVAL,
    CFG_ITEM_GB32960_REGINTV,
    CFG_ITEM_GB32960_TIMEOUT,
    CFG_ITEM_GB32960_REGSEQ,
    /* HOZON TSP */
	CFG_ITEM_HOZON_TSP_RMTCFG,
	CFG_ITEM_HOZON_TSP_TBOXID,
	CFG_ITEM_HOZON_TSP_MCUSW,
	CFG_ITEM_HOZON_TSP_MPUSW,
	CFG_ITEM_HOZON_TSP_TBOXSN,
	CFG_ITEM_HOZON_TSP_DIAGDATE,
	CFG_ITEM_HOZON_TSP_DIAGFLAG,
	CFG_ITEM_HOZON_TSP_RMTAPPOINT,
	CFG_ITEM_HOZON_TSP_RMTACAPPOINT,
	CFG_ITEM_HOZON_TSP_CERT_VALID,//证书有效性
	CFG_ITEM_HOZON_TSP_CERT_EN,//启用证书
	CFG_ITEM_HOZON_TSP_CERT,//证书
	CFG_ITEM_HOZON_TSP_FORBIDEN, //禁止启动
	CFG_ITEM_HOZON_MILEAGE,   //TBOX本地里程
	CFG_ITEM_HOZON_ACTEMP,    //空调温度
    USER_CFG_ITEM_ID_MAX,
}USER_CFG_PARA_ITEM_ID;

int udef_cfg_init(INIT_PHASE phase);
int cfg_set_user_para(USER_CFG_PARA_ITEM_ID id, void *data, unsigned int len);
int cfg_get_user_para(USER_CFG_PARA_ITEM_ID id, void *data, unsigned int *len);
int clbt_cfg_dump_para(void);
#endif
