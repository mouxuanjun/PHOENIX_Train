#ifndef __PID_H__
#define __PID_H__

#define PID_KP 0.0f
#define PID_KI 0.0f
#define PID_KD 0.0f
#define PID_MAX_OUTPUT 20000.0f
#define PID_MAX_IOUT 20000.0f

typedef struct {
    float kp; 
    float ki; 
    float kd; 

    float maxout;
    float maxiout;

    float set; 
    float fdb;

    float out;
    float Pout;
    float Iout;
    float Dout;

    float error[3];//last 3 errors

}pid_def;

typedef struct {
    pid_def motor_pid[2];//speed,angle
    float angle;
    float speed;
    float angle_set;
    float speed_set;
    float give_current;
}motor_t;


float pid_calc(pid_def *pid, float set, float fdb,int max_angle);
void pid_init(pid_def *pid, float kp, float ki, float kd, float maxout, float maxiout);
void zero_error(pid_def *pid,int max_angle);

extern motor_t motor_data;   

#endif