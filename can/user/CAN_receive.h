#ifndef __GM6020_H__
#define __GM6020_H__
#include "main.h"
#include "can.h"
#include "stm32f4xx.h"

typedef struct
{
    uint16_t can_id;
    int16_t set_voltage;
    float   Set_Speed;
    float   Set_angle;

    uint16_t rotor_angle;
    int16_t rotor_speed;
    int16_t torque_current;
    int16_t temp;

} Moto_GM6020_t;


void Set_GM6020_Gimbal_Voltage(CAN_HandleTypeDef *hcan, Moto_GM6020_t GM6020_Yaw, Moto_GM6020_t GM6020_Pitch);
void Get_GM6020_Motor_Message(uint32_t StdId,uint8_t rx_data[8]);

#endif