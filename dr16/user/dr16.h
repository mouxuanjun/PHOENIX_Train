#ifndef __DR16_H__
#define __DR16_H__

#include "main.h"

typedef struct
{
	int16_t ch0;
	int16_t ch1;
	int16_t ch2;
	int16_t ch3;
	int8_t  s1;
	int8_t  s2;
}rc_info_t;

typedef struct
{
	int16_t x;
	int16_t y;
	int16_t z;
	int8_t r;
	int8_t l; 
}mouse_info_t;

typedef struct
{
	uint16_t v;
}key_info_t;

void RemoteDataProcess(rc_info_t *rc,uint8_t tx_data[18]);
void MouseDataProcess(mouse_info_t *mouse,uint8_t tx_data[18]);
void KeyDataProcess(key_info_t *key,uint8_t tx_data[18]);

#endif

