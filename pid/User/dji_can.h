#ifndef __DJI_CAN_H__
#define __DJI_CAN_H__

#include "main.h"
#include "can.h"
#include "motor.h"
#include "stm32f4xx.h"

void can_filter_init(void);
void set_gm6020_motor_voltage(CAN_HandleTypeDef *hcan,float *motor1);
#endif
