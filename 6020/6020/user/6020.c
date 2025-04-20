#include "6020.h"

void motor_read(Motor6020 *motor,uint8_t *data){
    motor->angle=(data[0]<<8)|data[1];
    motor->speed=(data[2]<<8)|data[3];
    motor->current=(data[4]<<8)|data[5];
    motor->temperature=data[6];
}


void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    CAN_RxHeaderTypeDef RxHeader;
    uint8_t RxData[8];
    HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxHeader, RxData);

    if(RxHeader.StdId == 0x208){
        motor_read(&motor6020,RxData);

    }
    
}

