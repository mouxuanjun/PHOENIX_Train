#include "dr16.h"

rc_info_t rc;

void Remotedata(rc_info_t *rc,uint8_t rx_data[18])
{
	
	rc->ch0 = (((uint16_t) rx_data[0] | (int16_t) rx_data[1] << 8) & 0x07FF) - 1024;
	rc->ch1 = (((uint16_t) rx_data[1] >> 3 | (uint16_t) rx_data[2] << 5) & 0x07FF) - 1024;
	rc->ch2 = (((uint16_t) rx_data[2] >> 6 | (uint16_t) rx_data[3] | (uint16_t) rx_data[4] << 10) & 0x07FF) - 1024;
	rc->ch3 = (((uint16_t) rx_data[4] >> 1 | (uint16_t) rx_data[5] << 7) & 0x07FF) - 1024;
	rc->s1  = ((uint16_t) rx_data[5] >> 4) & 0x003;
	rc->s2  = ((uint16_t) rx_data[5] >> 6) & 0x003;
	rc->x   = ((int16_t) rx_data[6] | (int16_t) rx_data[7] << 8);
	rc->y   = ((int16_t) rx_data[8] | (int16_t) rx_data[9] << 8);
	rc->z   = ((int16_t) rx_data[10] | (int16_t) rx_data[11] << 8);
	rc->press_l = ((uint16_t) rx_data[12]) & 0x00FF;
	rc->press_r = ((uint16_t) rx_data[13]) & 0x00FF;
	rc->W   = ((uint16_t) rx_data[14]) & 0x0001;
	rc->S   = ((uint16_t) rx_data[14] >> 1) & 0x0001;
	rc->A   = ((uint16_t) rx_data[14] >> 2) & 0x0001;
	rc->D   = ((uint16_t) rx_data[14] >> 3) & 0x0001;
	rc->Q   = ((uint16_t) rx_data[14] >> 4) & 0x0001;
	rc->E   = ((uint16_t) rx_data[14] >> 5) & 0x0001;
	rc->Shift  = ((uint16_t) rx_data[14] >> 6) & 0x0001;
	rc->Ctrl   = ((uint16_t) rx_data[14] >> 7) & 0x0001;
	rc->staydata = ((uint16_t) rx_data[16] | (uint16_t) rx_data[17] << 8);
}
