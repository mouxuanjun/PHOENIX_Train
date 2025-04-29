#ifndef MOTOR_H
#define MOTOR_H
#include "stm32f4xx_hal.h"
#include "can.h"
#include "cmsis_os.h"
typedef enum{
    MSG_VOLTAGE_LOW ,
    MSG_VOLTAGE_HIGH,
    MSG_CURRENT_LOW,
    MSG_CURRENT_HIGH
} CTL_Message_Type;

typedef struct
{   
    int8_t ID;  // 电机ID
    int16_t MechanicalAngle;  // 机械角度
    int16_t Speed;  // 速度
    int16_t TorqueCurrent;  // 力矩电流
    int8_t Temperature;  // 温度
} MotorStatus;



typedef struct 
{   
    //实际传输电压范围：-25000~0~25000
    int16_t ID1_Voltage; // 电压ID1
    int16_t ID2_Voltage; // 电压ID2
    int16_t ID3_Voltage; // 电压ID3
    int16_t ID4_Voltage; // 电压ID4
}Voltage_CTL_Message_Low;

typedef struct 
{   
    //实际传输电压范围：-25000~0~25000
    int16_t ID5_Voltage; // 电压ID5
    int16_t ID6_Voltage; // 电压ID6
    int16_t ID7_Voltage; // 电压ID7

}Voltage_CTL_Message_High;


typedef struct 
{   
    //实际传输电流范围：-16384~0~16384, 
    int16_t ID1_ElectricCurrent; // 电流ID1
    int16_t ID2_ElectricCurrent; // 电流ID2
    int16_t ID3_ElectricCurrent; // 电流ID3
    int16_t ID4_ElectricCurrent; // 电流ID4


}ElectricCurrent_CTL_Message_Low;


typedef struct 
{   
    //实际传输电流范围：-16384~0~16384, 
    int16_t ID5_ElectricCurrent; // 电流ID5
    int16_t ID6_ElectricCurrent; // 电流ID6
    int16_t ID7_ElectricCurrent; // 电流ID7

}ElectricCurrent_CTL_Message_High;



/**
 * @brief CAN1接收消息回调函数
 */
void CAN_Filter_Init(void);

/**
 * @brief 反序列化电机状态
 * @param buffer 接收到的CAN数据缓冲区
 * @param status 电机状态结构体指针
 * @param Header CAN接收头部信息
 */
void Deserialize_Motor_Status(uint8_t *buffer, MotorStatus *status , CAN_RxHeaderTypeDef Header);


/**
 * @brief  CAN1接收消息回调函数 
 * 
 * @param buffer CAN接收数据缓冲区
 * @param status 电机状态结构体指针
 */
void CAN1_RX_Callback(uint8_t* buffer , MotorStatus * status);



/**
 * @brief 通用的控制消息发送函数
 * 
 * @param type 发送的消息类型
 * @param value1 填入第一个值
 * @param value2 填入第二个值
 * @param value3 填入第三个值
 * @param value4 填入第四个值
 */
void Motor_CTL_Message_Send(CTL_Message_Type type, int value1 , int value2 , int value3 , int value4 );


/**
 * @brief 发送ID为前4的电压控制消息
 * 
 * @param msg 电压控制消息结构体指针
 */
void Send_Voltage_CTL_Message_Low(Voltage_CTL_Message_Low *msg);


/**
 * @brief 发送ID为后3的电压控制消息
 * 
 * @param msg 电压控制消息结构体指针
 */
void Send_Voltage_CTL_Message_High(Voltage_CTL_Message_High *msg);


/**
 * @brief 发送ID为前4的电流控制消息
 * 
 * @param msg 电流控制消息结构体指针
 */
void Send_ElectricCurrent_CTL_Message_Low(ElectricCurrent_CTL_Message_Low *msg);


/**
 * @brief 发送ID为后3的电流控制消息
 * 
 * @param msg 电流控制消息结构体指针
 */
void Send_ElectricCurrent_CTL_Message_High(ElectricCurrent_CTL_Message_High *msg);
#endif //MOTOR_H



