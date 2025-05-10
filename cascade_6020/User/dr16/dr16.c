#include "dr16.h"

extern RC_Ctl_t RC_Ctl; 
extern uint8_t sbus_rx_buffer[18];

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    RC_Ctl.rc.ch0 = (sbus_rx_buffer[0] | (sbus_rx_buffer[1] << 8)) & 0x07ff;
	RC_Ctl.rc.ch1 = ((sbus_rx_buffer[1] >> 3) | (sbus_rx_buffer[2] << 5)) & 0x07ff;
	RC_Ctl.rc.ch2 = ((sbus_rx_buffer[2] >> 6) | (sbus_rx_buffer[3] << 2) | (sbus_rx_buffer[4]  << 10)) & 0x07ff;
	RC_Ctl.rc.ch3 = ((sbus_rx_buffer[4] >> 1) | (sbus_rx_buffer[5] << 7)) & 0x07ff;
	RC_Ctl.rc.s1 = ((sbus_rx_buffer[5] >> 4) & 0x000C) >> 2;
	RC_Ctl.rc.s2 = ((sbus_rx_buffer[5] >> 4) & 0x0003);
	
	
}
