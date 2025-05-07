#ifndef __MOTOR_RUN_H__
#define __MOTOR_RUN_H__

#include"main.h"
#include"pid.h"
#include"6020.h"
#include"dr16.h"

void motor_init(void);
void motor_control(void const * argument);

extern Motor6020rx motor6020rx;
extern rc_info_t dr16_receive;



#endif