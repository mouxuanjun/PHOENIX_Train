#ifndef __MOTOR_H
#define __MOTOR_H
#include "main.h"
typedef struct
{
    uint16_t angle;
    int16_t speed;
    int16_t current;
    int16_t voltage;
    uint8_t temperature_mos;
	  uint8_t temperature_average;
    int16_t speed_set;
    int16_t angle_set;
    int16_t current_set;
    int16_t voltage_set;
	  int16_t torque;
    int16_t torque_set;

  	float angle_f;
    float speed_f;
    float current_f;
    float voltage_f;
    float temperature_mos_f;
	  float temperature_average_f;
    float speed_set_f;
    float angle_set_f;
    float current_set_f;
    float voltage_set_f;
		float torque_f;
		float torque_set_f;
}motor;


void gm6020_data_process( motor* gm6020, uint8_t *data);


#endif
