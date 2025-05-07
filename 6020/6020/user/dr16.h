
#ifndef __DR16_H__
#define __DR16_H__

#include "main.h"

typedef struct
{
	int16_t ch0;
	int16_t ch1;
	int16_t ch2;
	int16_t ch3;
	uint8_t s1;
	uint8_t s2;
}rc_info_t;
extern rc_info_t dr16_receive;
void RDP_(rc_info_t *rc,uint8_t rx_data[18]);
	
#endif

