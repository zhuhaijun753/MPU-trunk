
#include "tbox_ivi_api.h"

extern ivi_callrequest callrequest; 



int tbox_ivi_get_call_type(void) //获取通话的类型
{

	if(callrequest.ecall == 1)
	{
		return 0;  // ecall
	}
	else if (callrequest.bcall == 1)
	{
		return 1;  // bcall
	}
	else
	{
		return 2;  //icall
	}
	return 3;
}
int tbox_ivi_get_call_action(void) //获取通话的类型
{

	if(callrequest.action == 1)
	{
		return 1;  // 打电话
	}
	else if (callrequest.action == 2)
	{
		return 2;  // 挂电话
	}
	return 0;
}

