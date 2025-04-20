//
// Created by 22560 on 25-4-20.
//

#ifndef DEVICE_GM6020_H
#define DEVICE_GM6020_H

#include "main.h"

#ifdef __cplusplus
extern "C" {
#endif

    void GM6020_1_Init(CAN_HandleTypeDef *hcan);

    void GM6020_2_Init(CAN_HandleTypeDef *hcan);

    void GM6020_3_Init(CAN_HandleTypeDef *hcan);

    void GM6020_4_Init(CAN_HandleTypeDef *hcan);

    void GM6020_update();

    void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef * hcan);

    void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef * hcan);
#ifdef __cplusplus
    }
#endif

#endif //DEVICE_GM6020_H
