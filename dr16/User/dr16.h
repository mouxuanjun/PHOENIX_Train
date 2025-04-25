#ifndef __dr16_H__
#define __dr16_H__

#include "main.h"  //int16_t

typedef struct  //typedef用于将已有的数据类型创建一个新的名称;
{               //struct是用户自定义的数据类型,可以将不同类型数据组合在一起
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
