#include "GM6020.h"

HAL_StatusTypeDef can_1;
extern Moto_GM6020_t GM6020;
void Get_GM6020_Motor_Message(uint32_t StdId,uint8_t rx_data[8])
{
    switch(StdId)
    {
        case 0x208:
        {
            GM6020.rotor_angle    = ((rx_data[0] << 8) | rx_data[1]);
            GM6020.rotor_speed    = ((rx_data[2] << 8) | rx_data[3]);
            GM6020.torque_current = ((rx_data[4] << 8) | rx_data[5]);
            GM6020.temp           =  rx_data[6];
            break;
        }
    }
}
void Set_GM6020_Gimbal_Voltage(CAN_HandleTypeDef* hcan,Moto_GM6020_t GM6020)
{
    CAN_TxHeaderTypeDef tx_header;
    uint8_t             CAN1_tx_data[8] = {0};
    
    tx_header.StdId = 0x1FF;
    tx_header.IDE   = CAN_ID_STD;
    tx_header.RTR   = CAN_RTR_DATA;
    tx_header.DLC   = 8;
    CAN1_tx_data[6] = ((int16_t)GM6020.Speed_pid.output>>8)&0xff;
    CAN1_tx_data[7] = ((int16_t)GM6020.Speed_pid.output)&0xff;
    HAL_CAN_AddTxMessage(&hcan1, &tx_header, CAN1_tx_data,(uint32_t*)CAN_TX_MAILBOX0);
}

