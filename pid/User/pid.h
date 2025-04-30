#ifndef __PID_H__
#define __PID_H__

#define PID_MAX_OUT 25000.0f
#define PID_MAX_OUT_V 320.0f
#define PID_MAX_IOUT 21000.0f
#define PID_MAX_IOUT_V 40.0f

#include "motor.h"

typedef struct
{
    float kp;
    float ki;
    float kd;
	  float kf; 

    float set;
    float now;
	  float past_set;
    float error[3];
	  float error_f;

    float out;
    float Pout;
    float Iout;
    float Dout;
	  float Kout;
    float max_Iout;
    float max_out;
}pid;

void pid_init(pid* pid,float Pid[]);
float pid_angle_calc(pid *pid, motor *motor);
float pid_speed_calc(pid *pid, motor *motor);
void limit(float *data, float max);
#endif
