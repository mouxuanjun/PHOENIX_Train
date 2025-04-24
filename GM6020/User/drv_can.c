#include "drv_can.h"


void CAN_Filter_Init(void)
{
	CAN_FilterTypeDef can1_filter_st;
	can1_filter_st.FilterIdHigh = 0x0000;
	can1_filter_st.FilterIdLow = 0x0000;
	can1_filter_st.FilterMaskIdHigh = 0x0000;
	can1_filter_st.FilterMaskIdLow = 0x0000;
	can1_filter_st.FilterFIFOAssignment = CAN_RX_FIFO0;
	can1_filter_st.FilterActivation = ENABLE;
	can1_filter_st.FilterMode = CAN_FILTERMODE_IDMASK;
	can1_filter_st.FilterScale = CAN_FILTERSCALE_32BIT;
	can1_filter_st.FilterBank = 0;
	can1_filter_st.SlaveStartFilterBank = 14;
	
	if (HAL_CAN_ConfigFilter(&hcan1,&can1_filter_st) != HAL_OK)
	{
		Error_Handler();
	}
	if (HAL_CAN_ActivateNotification(&hcan1,CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK)
	{
		Error_Handler();
	}
	if (HAL_CAN_Start(&hcan1) != HAL_OK)
	{
		Error_Handler();
	}
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
  CAN_RxHeaderTypeDef rx_header;
	uint8_t rx_data[8];
	HAL_CAN_GetRxMessage(&hcan1,CAN_RX_FIFO0,&rx_header,rx_data);
	if(hcan->Instance == CAN1)
	{
		if(rx_header.StdId == 0x205)
		{
			GET_MOTOR_GM6020_data(rx_header.StdId,rx_data);
		}
	}
}
