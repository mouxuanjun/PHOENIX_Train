#include "motor.h"

#define Motor_CAN hcan1
MotorStatus motor_status = {0};
static uint32_t last_tick = 0;
static float feedback_freq = 0.0f;

//CAN口初始化
void CAN_Filter_Init(void)
{
    CAN_FilterTypeDef filterConfig;
    filterConfig.FilterActivation = ENABLE;
    filterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
    filterConfig.FilterScale = CAN_FILTERSCALE_32BIT;

    filterConfig.FilterIdHigh = 0x0000;
    filterConfig.FilterIdLow = 0x0000;

    filterConfig.FilterMaskIdHigh = 0x0000;
    filterConfig.FilterMaskIdLow = 0x0000;
    //RX端初始化
    filterConfig.FilterBank = 0;
    filterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
    HAL_CAN_ConfigFilter(&Motor_CAN, &filterConfig);
    HAL_CAN_Start(&Motor_CAN);
    HAL_CAN_ActivateNotification(&Motor_CAN, CAN_IT_RX_FIFO0_MSG_PENDING);  //使能各种中断
    
    
    

} 


//解析函数
void Deserialize_Motor_Status(uint8_t *buffer, MotorStatus *status , CAN_RxHeaderTypeDef Header)
{   
    status->ID = Header.StdId - 0x204; // 0x200是ID偏移量
    status->MechanicalAngle = (buffer[0] << 8) | buffer[1];
    status->Speed = (buffer[2] << 8) | buffer[3];
    status->TorqueCurrent =(buffer[4]<< 8) | (buffer[5]);\
    status->Temperature = buffer[6];
}

//CAN1回调
void CAN1_RX_Callback(uint8_t* buffer , MotorStatus * status )
{
    CAN_RxHeaderTypeDef rx_header;
    HAL_CAN_GetRxMessage(&Motor_CAN, CAN_RX_FIFO0, &rx_header,buffer);
    Deserialize_Motor_Status(buffer, status , rx_header); // 0x200是ID偏移量
    uint32_t now = HAL_GetTick(); // ms
    if (last_tick != 0) {
        uint32_t interval = now - last_tick;
        if (interval > 0) {
            feedback_freq = 1000.0f / interval; // Hz
        }
    }
    last_tick = now;
}


//通用发送函数指定type和输入数据即可完成
void Motor_CTL_Message_Send(CTL_Message_Type type, int value1 , int value2 , int value3 , int value4 ){
	
    if (type == MSG_VOLTAGE_LOW){
        Voltage_CTL_Message_Low msg = {0};
        msg.ID1_Voltage = value1;
        msg.ID2_Voltage = value2;
        msg.ID3_Voltage = value3;
        msg.ID4_Voltage = value4;
        Send_Voltage_CTL_Message_Low(&msg);
		
    }
    else if (type == MSG_VOLTAGE_HIGH){
        Voltage_CTL_Message_High msg = {0};
        msg.ID5_Voltage = value1;
        msg.ID6_Voltage = value2;
        msg.ID7_Voltage = value3;
        Send_Voltage_CTL_Message_High(&msg);
    }
    else if (type == MSG_CURRENT_LOW){
        ElectricCurrent_CTL_Message_Low msg = {0};
        msg.ID1_ElectricCurrent = value1;
        msg.ID2_ElectricCurrent = value2;
        msg.ID3_ElectricCurrent = value3;
        msg.ID4_ElectricCurrent = value4;
        Send_ElectricCurrent_CTL_Message_Low(&msg);
    }
    else if (type == MSG_CURRENT_HIGH){
        ElectricCurrent_CTL_Message_High msg = {0};
        msg.ID5_ElectricCurrent = value1;
        msg.ID6_ElectricCurrent = value2;
        msg.ID7_ElectricCurrent = value3;
        Send_ElectricCurrent_CTL_Message_High(&msg);
    }
    //TODO: 未进行的错误处理
    // else{

    // }
}


void Send_Voltage_CTL_Message_Low(Voltage_CTL_Message_Low *msg)
{   
	
    //错误处理
    if (msg->ID1_Voltage > 25000 || msg->ID1_Voltage < -25000 ||
        msg->ID2_Voltage > 25000 || msg->ID2_Voltage < -25000 ||
        msg->ID3_Voltage > 25000 || msg->ID3_Voltage < -25000 ||
        msg->ID4_Voltage > 25000 || msg->ID4_Voltage < -25000){
        return;
    }
    //发送基本配置
    CAN_TxHeaderTypeDef tx_header;
    tx_header.StdId = 0x1FF;
    tx_header.IDE = CAN_ID_STD;
    tx_header.RTR = CAN_RTR_DATA;
    tx_header.DLC = 8;
    //发送数据帧解析
    uint8_t tx_data[8];
    uint32_t tx_mailbox;
    tx_data[0] = msg->ID1_Voltage >> 8;
    tx_data[1] = msg->ID1_Voltage & 0xFF;
    tx_data[2] = msg->ID2_Voltage >> 8;
    tx_data[3] = msg->ID2_Voltage & 0xFF;
    tx_data[4] = msg->ID3_Voltage>> 8;
    tx_data[5] = msg->ID3_Voltage & 0xFF;
    tx_data[6] = msg->ID4_Voltage >> 8; 
    tx_data[7] = msg->ID4_Voltage & 0xFF;

    if (HAL_CAN_AddTxMessage(&Motor_CAN, &tx_header, tx_data, &tx_mailbox) == HAL_OK){
		HAL_GPIO_WritePin(GPIOH,GPIO_PIN_10 , GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOH,GPIO_PIN_10 , GPIO_PIN_RESET);
	}
	
	
}

void Send_Voltage_CTL_Message_High(Voltage_CTL_Message_High *msg)
{   
    //错误处理
    if (msg->ID5_Voltage > 25000 || msg->ID5_Voltage < -25000 ||
        msg->ID6_Voltage > 25000 || msg->ID6_Voltage < -25000 ||
        msg->ID7_Voltage > 25000 || msg->ID7_Voltage < -25000){
        return;
    }
    //发送格式配置
    CAN_TxHeaderTypeDef tx_header;
    tx_header.StdId = 0x2FF;
    tx_header.IDE = CAN_ID_STD;
    tx_header.RTR = CAN_RTR_DATA;
    tx_header.DLC = 8;
    //发送数据帧解析
    uint8_t tx_data[8];
    uint32_t tx_mailbox;
    tx_data[0] = msg->ID5_Voltage >> 8;
    tx_data[1] = msg->ID5_Voltage & 0xFF;
    tx_data[2] = msg->ID6_Voltage >> 8;
    tx_data[3] = msg->ID6_Voltage & 0xFF;
    tx_data[4] = msg->ID7_Voltage>> 8;
    tx_data[5] = msg->ID7_Voltage & 0xFF;
    tx_data[6] = 0; // 填充NULL数据
    tx_data[7] = 0; // 填充NULL数据

    HAL_CAN_AddTxMessage(&Motor_CAN, &tx_header, tx_data, &tx_mailbox);
}

void Send_ElectricCurrent_CTL_Message_Low(ElectricCurrent_CTL_Message_Low *msg)
{   
    //错误处理
    if (msg->ID1_ElectricCurrent > 16384 || msg->ID1_ElectricCurrent < -16384 ||
        msg->ID2_ElectricCurrent > 16384 || msg->ID2_ElectricCurrent < -16384 ||
        msg->ID3_ElectricCurrent > 16384 || msg->ID3_ElectricCurrent < -16384 ||
        msg->ID4_ElectricCurrent > 16384 || msg->ID4_ElectricCurrent < -16384){
        return;
    }
    CAN_TxHeaderTypeDef tx_header;
    tx_header.StdId = 0x1FE;
    tx_header.IDE = CAN_ID_STD;
    tx_header.RTR = CAN_RTR_DATA;
    tx_header.DLC = 8;
    //发送数据帧解析
    uint8_t tx_data[8];
    uint32_t tx_mailbox;
    tx_data[0] = msg->ID1_ElectricCurrent >> 8;
    tx_data[1] = msg->ID1_ElectricCurrent & 0xFF;
    tx_data[2] = msg->ID2_ElectricCurrent >> 8;
    tx_data[3] = msg->ID2_ElectricCurrent & 0xFF;
    tx_data[4] = msg->ID3_ElectricCurrent>> 8;
    tx_data[5] = msg->ID3_ElectricCurrent & 0xFF;
    tx_data[6] = msg->ID4_ElectricCurrent >> 8;
    tx_data[7] = msg->ID4_ElectricCurrent & 0xFF;

    HAL_CAN_AddTxMessage(&Motor_CAN, &tx_header, tx_data, &tx_mailbox);
}


void Send_ElectricCurrent_CTL_Message_High(ElectricCurrent_CTL_Message_High *msg)
{   
    //错误处理
    if (msg->ID5_ElectricCurrent > 16384 || msg->ID5_ElectricCurrent < -16384 ||
        msg->ID6_ElectricCurrent > 16384 || msg->ID6_ElectricCurrent < -16384 ||
        msg->ID7_ElectricCurrent > 16384 || msg->ID7_ElectricCurrent < -16384){
        return;
    }
    CAN_TxHeaderTypeDef tx_header;
    tx_header.StdId = 0x2FE;
    tx_header.IDE = CAN_ID_STD;
    tx_header.RTR = CAN_RTR_DATA;
    tx_header.DLC = 8;
    //发送数据帧解析
    uint8_t tx_data[8];
    uint32_t tx_mailbox;
    tx_data[0] = msg->ID5_ElectricCurrent >> 8;
    tx_data[1] = msg->ID5_ElectricCurrent & 0xFF;
    tx_data[2] = msg->ID6_ElectricCurrent >> 8;
    tx_data[3] = msg->ID6_ElectricCurrent & 0xFF;
    tx_data[4] = msg->ID7_ElectricCurrent>> 8;
    tx_data[5] = msg->ID7_ElectricCurrent & 0xFF;
    tx_data[6] = 0; // 填充NULL数据
    tx_data[7] = 0; // 填充NULL数据

    HAL_CAN_AddTxMessage(&Motor_CAN, &tx_header, tx_data, &tx_mailbox);
}





//can口中断

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    if(hcan->Instance == CAN1){
        uint8_t RX_Buffer[8] = {0};
        CAN1_RX_Callback(RX_Buffer, &motor_status);
    }
}
