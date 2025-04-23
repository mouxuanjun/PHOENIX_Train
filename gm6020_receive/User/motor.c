#include "motor.h"

void motor_data_process(motor *gm6020, uint8_t *data)
{
    gm6020->angle =((int16_t)(data[0]<<8) | (int16_t)data[1]) & 0x1FFF ;
    gm6020->speed = (((int16_t)data[2]<<8) | (int16_t)data[3]);
    gm6020->current = ((int16_t)(data[4]<<8) | (int16_t)data[5]);
    gm6020->temperature = (data[6]) & 0xFF ;
}
