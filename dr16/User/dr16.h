#ifndef __dr16_H__
#define __dr16_H__

#include "main.h"  //int16_t

typedef struct  //typedef���ڽ����е��������ʹ���һ���µ�����;
{               //struct���û��Զ������������,���Խ���ͬ�������������һ��
	struct
	{
		int16_t ch0;
		int16_t ch1;
		int16_t ch2;
		int16_t ch3;
		uint8_t s1;
		uint8_t s2;
	}remote;
	
}RC_Ctrl_t;

void Get_DR16_Data(uint8_t *Buff);
#endif
