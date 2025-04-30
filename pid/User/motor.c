#include "motor.h"

void gm6020_data_process(motor *gm6020, uint8_t *data)
{
    gm6020->angle =((int16_t)(data[0]<<8) | (int16_t)data[1]);
    gm6020->speed = (((int16_t)data[2]<<8) | (int16_t)data[3]);
    gm6020->current = ((int16_t)(data[4]<<8) | (int16_t)data[5]);
    gm6020->temperature_average = (data[6]) ;
}
