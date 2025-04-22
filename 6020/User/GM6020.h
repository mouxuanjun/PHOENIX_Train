#ifndef __GM6020_H__
#define __GM6020_H__

#include "main.h"

typedef struct{
	uint16_t GM6020_ID;
	uint16_t GM6020_angle;
	int16_t GM6020_speed;
	int16_t GM6020_current;
	uint8_t GM6020_temp;
} motor_6020;

extern motor_6020 GM6020;

void GM6020_RxData(uint32_t StdID, uint8_t rx_data[8]);

#endif 
