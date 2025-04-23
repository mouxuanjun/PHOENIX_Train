#ifndef __MOTOR_H
#define __MOTOR_H
#include "main.h"
typedef struct
{
    uint16_t angle;
    int16_t speed;
    int16_t current;
    uint8_t temperature;
}motor;
void motor_data_process( motor* gm6020, uint8_t *data);
#endif
