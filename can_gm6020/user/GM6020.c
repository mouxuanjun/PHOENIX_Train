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

