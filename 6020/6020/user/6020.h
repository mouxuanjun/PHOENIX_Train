#ifndef __6020_H__
#define __6020_H__


#include "main.h"
#include "can.h"


typedef struct //Motor6020结构体包含四个数据
{
    int16_t speed;   
    uint16_t angle;
    uint8_t temperature;
    int16_t current;
}Motor6020rx;
extern Motor6020rx motor6020rx;



void can_init(void);
void motor_read(Motor6020rx *motor,uint8_t *data);

HAL_StatusTypeDef motor_write(uint32_t stdid,int16_t motor1,int16_t motor2,int16_t motor3,int16_t motor4);





#endif