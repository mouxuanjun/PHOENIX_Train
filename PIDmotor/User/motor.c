#include "motor.h"
#include <can.h>
#include "6020.h"

moto_info_t motor_yaw_info;
uint16_t can_cnt;



void can_filter_init(void) {
    CAN_FilterTypeDef cf;
    cf.FilterBank = 0; 
    cf.SlaveStartFilterBank = 14;
    cf.FilterMode = CAN_FILTERMODE_IDMASK;
    cf.FilterScale = CAN_FILTERSCALE_32BIT;
    cf.FilterIdHigh = 0x0000;
    cf.FilterIdLow = 0x0000;
    cf.FilterMaskIdHigh = 0x0000;
    cf.FilterMaskIdLow = 0x0000;
    cf.FilterFIFOAssignment = CAN_FILTER_FIFO0;
    cf.FilterActivation = ENABLE;
    HAL_CAN_ConfigFilter(&hcan1, &cf);
    HAL_CAN_Start(&hcan1);
		HAL_CAN_ActivateNotification(&hcan1,CAN_IT_RX_FIFO0_MSG_PENDING);
}



void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
  CAN_RxHeaderTypeDef rx_header;
  uint8_t  rx_data[8];
  if(hcan->Instance == CAN1)
  {
  HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &rx_header, rx_data); //receive can data
  switch(rx_header.StdId)
	{
	  case 0x205:
	{
    motor_yaw_info.rotor_angle   = ((rx_data[0] << 8) | rx_data[1]);
    motor_yaw_info.rotor_speed   = ((rx_data[2] << 8) | rx_data[3]);
    motor_yaw_info.torque_current = ((rx_data[4] << 8) | rx_data[5]);
    motor_yaw_info.temp           =   rx_data[6];
		break;
	}
	}
  }
}
 
void set_GM6020_motor_voltage(CAN_HandleTypeDef* hcan,int16_t v1)
{
  CAN_TxHeaderTypeDef tx_header;
  uint8_t             tx_data[8] = {0};
    
  tx_header.StdId = 0x1ff;
  tx_header.IDE   = CAN_ID_STD;
  tx_header.RTR   = CAN_RTR_DATA;
  tx_header.DLC   = 8;
 
  tx_data[0] = (v1>>8)&0xff;
  tx_data[1] =    (v1)&0xff;
	 
  HAL_CAN_AddTxMessage(&hcan1, &tx_header, tx_data,(uint32_t*)CAN_TX_MAILBOX0);
}


     

