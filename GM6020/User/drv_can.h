#ifndef __DRV_CAN_H__
#define __DRV_CAN_H__

#include "can.h"
#include "dvc_gm6020.h"

void CAN_Filter_Init(void);
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan);

#endif
