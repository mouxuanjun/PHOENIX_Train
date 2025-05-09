#ifndef __GM6020_H__
#define __GM6020_H__

#include "main.h"
#include "can.h"
#include "stm32f4xx.h"


typedef struct
{
    uint16_t can_id;//���ID
    int16_t  set_voltage;//�趨�ĵ�ѹֵ
    float Set_Speed;//�趨�ٶ�
    float Set_Angle;//�趨�Ƕ�

    uint16_t rotor_angle;//����Ƕ�
    int16_t  rotor_speed;//����ٶ�
    int16_t  torque_current;//���Ť��
    uint8_t  temp;//�¶�
	  uint16_t test;

}Moto_GM6020_t;

/*typedef struct
{
		uint16_t StdId; //标识符
    uint8_t IDE; //
		uint8_t RTR; //
		uint8_t DLC;//DLC
}chassis_tx_message;*/

void Set_GM6020_Gimbal_Voltage(CAN_HandleTypeDef* hcan,Moto_GM6020_t GM6020_Yaw,Moto_GM6020_t GM6020_Pitch);
void Get_GM6020_Motor_Message(uint32_t StdId,uint8_t rx_data[8]);
void Send_GM6020_Motor_Message(int16_t motor1, int16_t motor2, int16_t motor3, int16_t motor4);
#endif
