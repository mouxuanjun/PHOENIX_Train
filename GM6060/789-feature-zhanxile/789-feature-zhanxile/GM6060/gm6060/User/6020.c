#include "6020.h"
void motor_measure(Motor6020 *motor,uint8_t *data)
{
	motor->angle =(data[0]<<8)|data[1];
	motor->speed =(data[2]<<8)|data[3];
	motor->current =(data[4]<<8)|data[5];
	motor->temperate =data[6];
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
	CAN_RxHeaderTypeDef rx_header;
	uint8_t rx_data[8];
	HAL_CAN_GetRxMessage(hcan,CAN_RX_FIFO0,&rx_header,rx_data);
	if (rx_header.StdId == 0x209)
		{
			motor_measure(&motor6020,rx_data);
			
	  }
}



