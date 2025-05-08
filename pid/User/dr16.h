#ifndef __DR16_H__
#define __DR16_H__

#include "main.h"

typedef  struct 
{ 
int16_t ch0; 
int16_t ch1; 
int16_t ch2; 
int16_t ch3; 
uint8_t  s1; 
uint8_t  s2;  
int16_t x; 
int16_t y; 
int16_t z; 
uint8_t press_l; 
uint8_t press_r; 
uint16_t v;
}rc_info_t;

void RemoteDataProcess(rc_info_t *rc,uint8_t rx_data[18]);


#endif
