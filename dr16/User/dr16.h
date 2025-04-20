#ifndef __DR16_H__
#define __DR16_H__

#include "main.h"

typedef struct
{
	uint16_t ch0;
	uint16_t ch1;
	uint16_t ch2;
	uint16_t ch3;
	uint8_t s1;
	uint8_t s2;
	int16_t x; 
  int16_t y; 
  int16_t z; 
  uint8_t press_l; 
  uint8_t press_r; 
	uint16_t  W;
  uint16_t  S;
	uint16_t  A;
	uint16_t  D;
	uint16_t  Q;
	uint16_t  E;
	uint16_t  Shift;
	uint16_t  Ctrl;
	uint16_t staydata;
}rc_info_t;

void Remotedata(rc_info_t *rc,uint8_t rx_data[18]);
	
#endif
