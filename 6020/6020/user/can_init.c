#include <can.h>
#include <6020.h>

void can_init(void) {
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
    HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING);
}
