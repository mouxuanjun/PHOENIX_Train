#include "dji_can.h"
#include "gm6020.h"
#include "can.h"
#include "stm32f4xx_hal_can.h"

void can_filter_init(void){
    CAN_FilterTypeDef can1_filter_st;
    can1_filter_st.FilterIdHigh = 0x0000;                                    
    can1_filter_st.FilterIdLow = 0x0000;                                      
    can1_filter_st.FilterMaskIdHigh = 0x0000;                                
    can1_filter_st.FilterMaskIdLow = 0x0000;                                 
    can1_filter_st.FilterFIFOAssignment = CAN_RX_FIFO0;                       
    can1_filter_st.FilterBank = 0;                                           
    can1_filter_st.FilterMode = CAN_FILTERMODE_IDMASK;                             
    can1_filter_st.FilterScale = CAN_FILTERSCALE_32BIT;                        
    can1_filter_st.FilterActivation = ENABLE;                                 
    can1_filter_st.SlaveStartFilterBank = 14;                                
    HAL_CAN_ConfigFilter(&hcan1,&can1_filter_st);                       
    HAL_CAN_Start (&hcan1);                                              
    HAL_CAN_ActivateNotification (&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING);  
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan){
    CAN_RxHeaderTypeDef rx_header;
    uint8_t rx_data[8];
    HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &rx_header, rx_data); {
            if(rx_header.StdId == 0x205){
                get_gm6020_data(rx_header.StdId, rx_data);
            } 
    }
   
}
