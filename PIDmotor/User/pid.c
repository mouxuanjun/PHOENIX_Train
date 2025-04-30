#include <main.h>
#include "pid.h"

 
pid_sturct_t gimbal_yaw_speed_pid;
pid_sturct_t gimbal_yaw_angle_pid;
 
void pid_init(pid_sturct_t *pid,
              float kp,
              float ki,
              float kd,
              float i_max,
              float out_max)//PID?????
{
  pid->kp      = kp;
  pid->ki      = ki;
  pid->kd      = kd;
  pid->i_max   = i_max;
  pid->out_max = out_max;
}
 
 
float pid_calc(pid_sturct_t *pid, float ref, float fdb)
{
  pid->ref = ref;
  pid->fdb = fdb;
  pid->err[1] = pid->err[0];
  pid->err[0] = pid->ref - pid->fdb;
  
  pid->p_out  = pid->kp * pid->err[0];
  pid->i_put += pid->ki * pid->err[0];
  pid->d_out  = pid->kd * (pid->err[0] - pid->err[1]);
  
  
  pid->output = pid->p_out + pid->i_put + pid->d_out;
  
  return pid->output;
}
 
void gimbal_PID_init()
{
	pid_init(&gimbal_yaw_speed_pid, 30, 0, 0, 30000, 30000);//P=30,I=0,D=0
	pid_init(&gimbal_yaw_angle_pid, 400, 0, 0, 0, 320);//P=400,I=0,D=0
}

