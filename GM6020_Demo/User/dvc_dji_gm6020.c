#include "dvc_dji_gm6020.h"

HAL_StatusTypeDef can_1;
extern Moto_GM6020_t GM6020;
#define CAN_CHASSIS_ALL_ID 0x1FF           //标识符的id
#define CHASSIS_CAN hcan1
uint8_t chassis_can_send_data[8];
//uint8_t test2=0;
/**
 * @file GM6020.c
 * @brief GM6020���ܷ������ĺ���
 * @param StdId ���ID
 * @param rx_data CANͨ���յ�������
 * @author HWX
 * @date 2024/10/20
 */
void Get_GM6020_Motor_Message(uint32_t StdId,uint8_t rx_data[8])
{
    switch(StdId)//����ָ�������������Ϣ
    {
        case 0x205://�������ı�ʶ��
        {
            //test2++;
 					  GM6020.rotor_angle    = ((rx_data[0] << 8) | rx_data[1]);//���ջ�е�Ƕȣ�16bit��
            GM6020.rotor_speed    = ((rx_data[2] << 8) | rx_data[3]);//����ת�٣�16bit��
            GM6020.torque_current = ((rx_data[4] << 8) | rx_data[5]);//����ʵ��ת��
            GM6020.temp           =   rx_data[6];//���յ���¶ȣ�8bit��
            break;
        }
    }
}

CAN_TxHeaderTypeDef Ctx;
/**
*  @brief Send_GM6020_Motor_Message
*
*  @author CGH
*/
void Send_GM6020_Motor_Message(int16_t motor1, int16_t motor2, int16_t motor3, int16_t motor4)
{
    uint32_t send_mail_box; 
    Ctx.StdId = CAN_CHASSIS_ALL_ID; //标识符
    Ctx.IDE = CAN_ID_STD; //标准发送格式
    Ctx.RTR = CAN_RTR_DATA; //数据帧
		Ctx.DLC = 0x08; //一次发送的数据的字节数
    chassis_can_send_data[0] = motor1 >> 8; 
    chassis_can_send_data[1] = motor1; 
    chassis_can_send_data[2] = motor2 >> 8; 
    chassis_can_send_data[3] = motor2; 
    chassis_can_send_data[4] = motor3 >> 8; 
    chassis_can_send_data[5] = motor3; 
    chassis_can_send_data[6] = motor4 >> 8; 
    chassis_can_send_data[7] = motor4; 
 
    HAL_CAN_AddTxMessage(&CHASSIS_CAN, &Ctx, chassis_can_send_data, &send_mail_box); 



}

