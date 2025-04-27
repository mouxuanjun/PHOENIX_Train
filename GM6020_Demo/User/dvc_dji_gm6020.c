#include "dvc_dji_gm6020.h"

HAL_StatusTypeDef can_1;
extern Moto_GM6020_t GM6020;
/**
 * @file GM6020.c
 * @brief GM6020接受反馈报文函数
 * @param StdId 电机ID
 * @param rx_data CAN通道收到的数据
 * @author HWX
 * @date 2024/10/20
 */
void Get_GM6020_Motor_Message(uint32_t StdId,uint8_t rx_data[8])
{
    switch(StdId)//接收指定电机反馈的信息
    {
        case 0x207://反馈报文标识符
        {
            GM6020.rotor_angle    = ((rx_data[0] << 8) | rx_data[1]);//接收机械角度（16bit）
            GM6020.rotor_speed    = ((rx_data[2] << 8) | rx_data[3]);//接收转速（16bit）
            GM6020.torque_current = ((rx_data[4] << 8) | rx_data[5]);//接收实际转矩
            GM6020.temp           =   rx_data[6];//接收电机温度（8bit）
            break;
        }
    }
}

