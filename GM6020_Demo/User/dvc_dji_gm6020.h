#ifndef __GM6020_H__
#define __GM6020_H__

#include "main.h"
#include "can.h"
#include "stm32f4xx.h"


typedef struct
{
    uint16_t can_id;//电机ID
    int16_t  set_voltage;//设定的电压值
    float Set_Speed;//设定速度
    float Set_Angle;//设定角度

    uint16_t rotor_angle;//电机角度
    int16_t  rotor_speed;//电机速度
    int16_t  torque_current;//电机扭矩
    uint8_t  temp;//温度

}Moto_GM6020_t;

void Set_GM6020_Gimbal_Voltage(CAN_HandleTypeDef* hcan,Moto_GM6020_t GM6020_Yaw,Moto_GM6020_t GM6020_Pitch);
void Get_GM6020_Motor_Message(uint32_t StdId,uint8_t rx_data[8]);

#endif
