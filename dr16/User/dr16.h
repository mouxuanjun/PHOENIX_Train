#ifndef __dr16_H__
#define __dr16_H__

#include "main.h"  //int16_t

typedef struct  //typedef���ڽ����е��������ʹ���һ���µ�����;
{               //struct���û��Զ������������,���Խ���ͬ�������������һ��
	int16_t ch0;
	int16_t ch1;
	int16_t ch2;
	int16_t ch3;
	uint8_t s1;
	uint8_t s2;
}rc_info_t; //remote controller

void RemoteDataProcess(rc_info_t *rc,uint8_t rx_data[18]);
#endif
