#ifndef __DRIVER_CAN_H__
#define __DRIVER_CAN_H__
#include "main.h"
#include "can.h"
#include "motor.h"
#include "stm32f4xx_hal_can.h"
void can_filter_init(void);
void GM6020_Tx_Init(void);
void GM6020_Tx(CAN_TxHeaderTypeDef* tx_header ,
    uint8_t tmp_usedID ,
    int16_t voltage0 ,
    int16_t voltage1 ,
    int16_t voltage2 ,
    int16_t voltage3 );
#endif
