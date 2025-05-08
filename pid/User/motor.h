#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "main.h"
#include "can.h"
#include "stm32f4xx.h"
#include "stm32f4xx_hal_can.h"

typedef struct
{
    int16_t mechanical_angle;
    int16_t speed_rpm;
    int16_t torque_current;
    uint8_t temp;
}motor_measure_t;

void get_gm6020_data(uint32_t id, uint8_t *rx_data);
  
#endif
