#ifndef __RXCAN_H__
#define __RXCAN_H__

#include "main.h"
#include "can.h"
#include "GM6020.h"

extern motor_6020 GM6020;

void Filter_Init(void);
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan);

#endif
