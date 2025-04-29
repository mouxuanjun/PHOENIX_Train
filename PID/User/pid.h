#ifndef PID_H
#define PID_H
#include "stdbool.h"

typedef enum{
    NORMAL_PID,  //普通PID
    INTERGRAL_SEPARATION_PID, //积分分离PID
    VARIABLE_SPEED_INTEGRAL_PID, //变速积分PID
} Pid_Type;


typedef struct {
	float target;
	float Kp; //比例系数
    float Ki; //积分系数
    float Kd; //微分系数

    float dt; //采样时间
    float error; //当前误差
    float error_last; //上次误差
    float error_sum; //误差和
    float output; //输出值
	
    float max_output;  //最大输出限幅
    float Max_Integral_Limit; // 最大积分限幅
    float Integral_Separation_Threshold; //积分分离阈值
    float Variable_Speed_Integral_Lower_Limit;  //变速积分下限
    float Variable_Speed_Integral_Upper_Limit;  //变速积分上限

    bool  EnableZeroCrossingProtection;
    float  ZeroCrossingProtection_Threshold;
    Pid_Type type;
}  Pid;




void Pid_Update(Pid *pid ,float current_value , float target_value);

void Pid_Init(Pid *pid, float Kp, float Ki, float Kd, float dt, Pid_Type type);

void Normal_Pid_Update(Pid *pid ,float current_value , float target_value);

void Intergral_Separation_Pid_Update(Pid *pid ,float current_value , float target_value);

void Pid_Enable_ZeroCrossingProtection(Pid *pid, bool EnableZeroCrossingProtection , float  ZeroCrossingProtection_Threshold);

void Pid_Set_Kp(Pid *pid, float Kp);

void Pid_Set_Ki(Pid *pid, float Ki);

void Pid_Set_Kd(Pid *pid, float Kd);

void Pid_Set_Target(Pid *pid, float target);

void Pid_Set_Max_Output(Pid *pid, float max_output);

void Pid_Set_Max_Integral_Limit(Pid *pid, float Max_Integral_Limit); 

void Pid_Set_Parameters(Pid *pid, float Kp, float Ki, float Kd, float dt, Pid_Type type);




#endif // PID_H

