#ifndef __PID_H__
#define __PID_H__

#include "main.h"
#include "can.h"
#include "motor.h"
#include "stm32f4xx.h"

typedef struct{
    float kp;
    float ki;
    float kd;
    float error;
    float last_error;
    float integral;       
    float p_output;
    float i_output;
    float d_output;
    float output;
    float current;
    float target;
    float max_output;
}pidcontroller;

void pid_init(pidcontroller *Pid, float kp, float ki, float kd,float *current_speed,float *target);
float pid_update_angle(pidcontroller *Pid, float *tar, float *cur,float *max_output);
float pid_update_speed(pidcontroller *Pid, float *tar, float *cur,float *max_output);
#endif
