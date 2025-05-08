#include "pid.h"
#include "motor.h"

extern pidcontroller SpeedPid;
extern pidcontroller AnglePid;
extern motor_measure_t gm6020;

void Handle_Angle_PID_Over_Zero(pidcontroller *Pid){
    if(Pid->target - Pid->current > 4096)    
    {
    Pid->error -= 8192;        
    } 
    else if(Pid->target - Pid->current < -4096)
    {
    Pid->error += 8192;
    }
}

void pid_init(pidcontroller *SpeedPid, float kp, float ki, float kd,float *current,float *target){
    SpeedPid->kp = kp;
    SpeedPid->ki = ki;
    SpeedPid->kd = kd;
    SpeedPid->integral = 0.0f;
    SpeedPid->error = 0.0f;
    SpeedPid->last_error = 0.0f;
    SpeedPid->p_output = 0.0f;
    SpeedPid->i_output = 0.0f;
    SpeedPid->d_output = 0.0f;
    SpeedPid->output = 0.0f;
    SpeedPid->current = *current;
    SpeedPid->target = *target;
}

float pid_update_speed(pidcontroller *Pid, float* tar, float* cur,float *max_output){
    
    Pid->target = *tar;
    Pid->current = *cur;
    Pid->error = Pid->target - Pid->current;
    Pid->p_output = Pid->kp * Pid->error;
    Pid->integral += Pid->error;
	  if(Pid->integral > 5000)
		    Pid->integral = 5000;
		else if(Pid->integral < -5000)
		    Pid->integral = -5000;
    Pid->i_output = Pid->ki * Pid->integral;
    Pid->d_output = Pid->kd * (Pid->error - Pid->last_error);
    Pid->output = Pid->p_output + Pid->i_output + Pid->d_output;
    if(Pid->output > *max_output) Pid->output =  *max_output;
    else if(Pid->output < -*max_output) Pid->output = -*max_output;
    Pid->last_error = Pid->error; 
    return Pid->output;
}

float pid_update_angle(pidcontroller *Pid, float* tar, float* cur,float *max_output){
    
    Pid->target = *tar;
    Pid->current = *cur;
    Pid->error = Pid->target - Pid->current;
    Handle_Angle_PID_Over_Zero(Pid);
    Pid->p_output = Pid->kp * Pid->error;
    Pid->integral += Pid->error;
	  if(Pid->integral > 20000)
		    Pid->integral = 20000;
		else if(Pid->integral < -20000)
		    Pid->integral = -20000;
    Pid->i_output = Pid->ki * Pid->integral;
    Pid->d_output = Pid->kd * (Pid->error - Pid->last_error);
    Pid->output = Pid->p_output + Pid->i_output + Pid->d_output;
    if(Pid->output > *max_output) Pid->output =  *max_output;
    else if(Pid->output < -*max_output) Pid->output = -*max_output;
    Pid->last_error = Pid->error; 
//		Pid->output = 320;                                                         //¼Ù¶¨½ÇËÙ¶È
    return Pid->output;
}

