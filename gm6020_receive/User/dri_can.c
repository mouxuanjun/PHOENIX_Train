#include "dri_can.h"
#include "main.h"
#include "motor.h"
#include "can.h"

motor gm6020;

void can_filter_init(void)
{
    CAN_FilterTypeDef can_filter_st;
	
	  can_filter_st.FilterIdHigh = 0x0000;
    can_filter_st.FilterIdLow = 0x0000;
    can_filter_st.FilterMaskIdHigh = 0x0000;
    can_filter_st.FilterMaskIdLow = 0x0000;
  	can_filter_st.FilterFIFOAssignment = CAN_RX_FIFO0;
    can_filter_st.FilterActivation = ENABLE;
    can_filter_st.FilterMode = CAN_FILTERMODE_IDMASK;
    can_filter_st.FilterScale = CAN_FILTERSCALE_32BIT;
    can_filter_st.FilterBank = 0;
    can_filter_st.SlaveStartFilterBank = 14;
	
    if(HAL_CAN_ConfigFilter(&hcan1, &can_filter_st) != HAL_OK)
    {
      Error_Handler();
    }
		
    if(HAL_CAN_Start(&hcan1) != HAL_OK)
    {
      Error_Handler();
    }
		
    if(HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK)
    {
      Error_Handler();
    }
}

    void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    CAN_RxHeaderTypeDef rx_header;
    uint8_t rx_data[8];
    HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &rx_header, rx_data);
    if(rx_header.StdId == 0x207)                                      //观察电机小灯一秒亮n次，则地址取204+n
    {
      motor_data_process(&gm6020 , rx_data );
    }
}
