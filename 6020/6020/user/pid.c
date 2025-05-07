#include "pid.h"
#include <stdio.h>

void zero_error(pid_def *pid,int max_angle){
    if(pid->error[0]>=max_angle/2){//过零保护
        pid->error[0]=pid->error[0]-max_angle;
    }
    else if(pid->error[0]<=-max_angle/2){
        pid->error[0]=max_angle+pid->error[0];
    }
}

float pid_calc(pid_def *pid, float set, float fdb,int max_angle){
    if(pid== NULL)
        return 0;
    pid->error[2]=pid->error[1];
    pid->error[1]=pid->error[0];
    pid->error[0]=set - fdb;

    zero_error(pid,max_angle);
    pid->set=set;
    pid->fdb=fdb;
    
    
    pid->Pout=pid->kp*pid->error[0];
    pid->Iout+=pid->ki*pid->error[0];
    if(pid->Iout>pid->maxiout)
        pid->Iout=pid->maxiout;
    else if(pid->Iout<-pid->maxiout)
        pid->Iout=-pid->maxiout;
    
    pid->Dout=pid->kd*(pid->error[0]-pid->error[1]);
    

    pid->out=pid->Pout+pid->Iout+pid->Dout;
    if(pid->out>pid->maxout)
        pid->out=pid->maxout;
    else if(pid->out<-pid->maxout)
        pid->out=-pid->maxout;
    
    return pid->out;
}


void pid_init(pid_def *pid, float kp, float ki, float kd, float maxout, float maxiout){
    if(pid==NULL)
        return;
    pid->kp=kp;
    pid->ki=ki;
    pid->kd=kd;
    pid->maxout=maxout;
    pid->maxiout=maxiout;
    pid->error[0]=0;
    pid->error[1]=0;
    pid->error[2]=0;
    pid->Pout=0;
    pid->Iout=0;
    pid->Dout=0;
}




