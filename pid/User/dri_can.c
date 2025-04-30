#include "dri_can.h"

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

void GM6020_Tx_Init(void){

}
void GM6020_Tx(CAN_TxHeaderTypeDef* tx_header ,
               uint8_t tmp_usedID ,
               int16_t voltage0 ,
               int16_t voltage1 ,
               int16_t voltage2 ,
               int16_t voltage3 ){								 //ID为1-4若ID为5-8则地址取2FF
    uint32_t TxMailbox;
    uint8_t tmp_TxData[8] = {0};
  if(tmp_usedID >= 1 && tmp_usedID <= 4){
    tx_header->StdId = 0x1FF;
  }
  else if(tmp_usedID >= 5 && tmp_usedID <= 8){
    tx_header->StdId = 0x2FF;
  }
    tmp_TxData[0] = ( voltage0 >> 8 ) & 0xFF;
    tmp_TxData[1] = voltage0 & 0xFF;
    tmp_TxData[2] = ( voltage1 >> 8 ) & 0xFF;
    tmp_TxData[3] = voltage1 & 0xFF;
    tmp_TxData[4] = ( voltage2 >> 8 ) & 0xFF;
    tmp_TxData[5] = voltage2 & 0xFF;
    tmp_TxData[6] = ( voltage3 >> 8 ) & 0xFF;
    tmp_TxData[7] = voltage3 & 0xFF;
    if(HAL_CAN_AddTxMessage(&hcan1, tx_header, tmp_TxData, &TxMailbox) != HAL_OK)
    {
      Error_Handler();
    }
}
							 
