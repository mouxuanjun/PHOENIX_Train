#ifndef  __PID_H_
#define  __PID_H_

#include <main.h>
#include "stm32f4xx.h"

typedef struct  _pid_struct_t
{
	float kp;
	float ki;
	float kd;
	float i_max;//ji fen xiane
	float out_max;//shu chu xiane
	float p_out;
	float i_put;
	float d_out;
	float pid_out;
	
	float ref;
	float fdb;
	float err[2];
	float output;
}pid_sturct_t;

void pid_init(pid_sturct_t *pid,float kp,float ki,float kd,float i_out,float out_max);

void gimbal_PID_init(void);

float pid_calc(pid_sturct_t *pid, float ref, float fdb);





#endif


