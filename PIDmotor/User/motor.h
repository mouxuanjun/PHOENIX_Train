#ifndef  __MOTOR_H_
#define  __MOTOR_H_

#include "main.h"
#include "can.h"
#include "stm32f4xx.h"
typedef struct
{
    uint16_t can_id;
    int16_t  set_voltage;
    uint16_t rotor_angle;
    int16_t  rotor_speed;
    int16_t  torque_current;
    uint8_t  temp;
}moto_info_t;


void can_filter_init(void);
void set_GM6020_motor_voltage(CAN_HandleTypeDef* hcan,int16_t v1);
 
#endif


