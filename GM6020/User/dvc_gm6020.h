#ifndef __DVC_GM6020__
#define __DVC_GM6020__

#include "main.h"
typedef struct
{
	int16_t motor_angle;
	int16_t motor_speed;
	int16_t Actual_torque;
	int16_t temp;
}Motor_GM6020_t;

void GET_MOTOR_GM6020_data(uint32_t StdId,uint8_t rx_data[8]);



#endif
