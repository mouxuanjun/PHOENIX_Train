#include "remote_control.h"

extern RC_Ctl_t RC_Ctl;
extern float target_angle;
extern float angle_out;
extern float speed_out;
extern pid_type_def speed_pid,angle_pid;      //声明pid数据结构体类型
extern const motor_measure_t* motor_data;  //声明电机数据指针
float speed_k = 30;


extern CAN_HandleTypeDef hcan1;
extern CAN_HandleTypeDef hcan2;

void remote_control(void const * argument)
{

    while(1)
	{
    motor_data = get_yaw_gimbal_motor_measure_point();
	  
	target_angle += (RC_Ctl.rc.ch0 - 1024) / 660.f * speed_k;
	
	if(target_angle >= 8192){
	    target_angle -= 8192;
	}else if(target_angle <= 0){
	    target_angle += 8192;
	}
	angle_out = PID_calc_angle(&angle_pid,motor_data->ecd,target_angle);  
    speed_out = PID_calc_speed(&speed_pid,motor_data->speed_rpm,angle_out);    //pid参数;实际转速;设定参数
	
	CAN_cmd_gimbal(speed_out,0,0,0);  
	osDelay(1);
	}
}

