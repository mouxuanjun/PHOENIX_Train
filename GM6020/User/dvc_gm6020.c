#include "dvc_gm6020.h"

HAL_StatusTypeDef can1;
extern Motor_GM6020_t GM6020;
void GET_MOTOR_GM6020_data(uint32_t StdId,uint8_t rx_data[8])
{
	switch(StdId)
	{
		case 0x205:
		{
			GM6020.motor_angle   = ((rx_data[0] << 8) | rx_data[1]);
			GM6020.motor_speed   = ((rx_data[2] << 8) | rx_data[3]);
			GM6020.Actual_torque = ((rx_data[4] << 8) | rx_data[5]);
			GM6020.temp          = (rx_data[6]);
			break;
		}	
	}
}
