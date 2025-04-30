#include "pid.h"


void pid_init(pid* pid,float Pid[])
{
    pid->kp =Pid[0];
    pid->ki =Pid[1];
    pid->kd =Pid[2];
    pid->kf =Pid[3];
    pid->error[0] = pid->error[1] = pid->error[2] = pid->out = pid->Iout = pid->Dout = pid->Pout = 0.0f;
    pid->max_out = PID_MAX_OUT;
    pid->max_Iout = PID_MAX_IOUT;
}

float pid_angle_calc(pid *pid, motor *motor){
	  pid->past_set =pid->set;
	
  if(motor->angle_f != 0  || motor->angle_set_f != 0){
		pid->set = motor->angle_set_f;
    pid->now = motor->angle_f;
  }
	else if(motor->angle != 0  || motor->angle_set != 0){
    pid->set = motor->angle_set;
    pid->now = motor->angle;
  }
	else return 0;
	
	if(pid->set < 0){
    pid->set = 8191 + pid->set;
}		
    pid->error[2] = pid->error[1];
    pid->error[1] = pid->error[0];
    pid->error[0] = pid->set - pid->now;
    pid->error_f =pid->set - pid->past_set;
	  if(pid->error[0] > 4096)
    pid->error[0] = pid->error[0]  - 8191;
    else if(pid->error[0] < -4096)
    pid->error[0] = 8191 + pid->error[0];
		
	  if(pid->error_f > 4096)
    pid->error_f = pid->error_f  - 8191;
    else if(pid->error_f < -4096)
    pid->error_f = 8191 + pid->error_f;
    
		pid->Pout = pid->kp * pid->error[0];
    pid->Iout += pid->ki * pid->error[0];
    pid->Dout = pid->kd * (pid->error[0] - pid->error[1]);
	  pid->Kout = pid->kf * pid->error_f;
    limit(&pid->Iout,80.0f);                              //changed

    pid->out = pid->Pout + pid->Iout + pid->Dout + pid->Kout;
    limit(&pid->out,320.0f);                               //changed

	  return pid->out;
}

float pid_speed_calc(pid *pid, motor *motor){
    pid->past_set =pid->set;

  if(motor->speed_set_f != 0 || motor->speed_f != 0 ){
  	pid->set = motor->speed_set_f != 0 ;
    pid->now = motor->speed_f; 
	}
	else if(motor->speed_set != 0 || motor->speed != 0 ){
  	pid->set = motor->speed_set;
    pid->now = motor->speed; 
	}
	else return 0;
		pid->error[2] = pid->error[1];
    pid->error[1] = pid->error[0];
    pid->error[0] = pid->set- pid->now;

    pid->Pout = pid->kp * pid->error[0];
    pid->Iout+= pid->ki * pid->error[0];
    pid->Dout = pid->kd * (pid->error[0] - pid->error[1]);
    pid->Kout = pid->kf * (pid->set - pid->past_set);
    limit(&pid->Iout,pid->max_Iout);

    pid->out = pid->Pout + pid->Iout + pid->Dout +pid->Kout;
    limit(&pid->out,pid->max_out);
	return pid->out;
}

void limit(float *data, float max){
    if(*data > max){
    *data=max;
    }
    else if(*data < -max){
    *data=-max;
    }
}
