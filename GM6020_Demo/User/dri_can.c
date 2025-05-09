#include "dri_can.h"

/**
 * @file BSP_Can.c
 * @brief ��ʼ��ɸѡ����������������붼��0x0000��
 * @author HWX
 * @date 2024/10/20
 */
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
	
	//ʹ��CANͨ��
    if (HAL_CAN_ConfigFilter(&hcan1, &can1_filter_st) != HAL_OK)// ���� CAN1 ������
    {
        Error_Handler();  // �������
    }
    if (HAL_CAN_Start(&hcan1) != HAL_OK)// ���� CAN1
    {
        Error_Handler();
    }
    if (HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK)// ʹ�� CAN1 ���� FIFO0 ��Ϣ�ж�
    {
        Error_Handler();
    }
}

/**
 * @brief CAN�����жϺ���
 * @param hcan CANͨ��
 */
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    CAN_RxHeaderTypeDef rx_header;
    uint8_t rx_data[8];
    HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &rx_header, rx_data);
    if(hcan->Instance == CAN1){
			if(rx_header.StdId == 0x205){//强烈建议这里改成用定义，不然修改太麻烦了
				
		    Get_GM6020_Motor_Message(rx_header.StdId,rx_data);
		 }
    }
}


