#include "dr16.h"

extern rc_info_t rc;

void RemoteDataProcess(rc_info_t *rc,uint8_t rx_data[18]){
    rc->ch0 = ((int16_t)rx_data[0] | ((int16_t)rx_data[1] << 8))& 0x07FF ; 
    rc->ch0 -= 1024;	
    rc->ch1 = (((int16_t)rx_data[1] >> 3) | ((int16_t)rx_data[2] << 5)) & 0x07FF ; 
    rc->ch1 -= 1024;	
    rc->ch2 = (((int16_t)rx_data[2] >> 6) | ((int16_t)rx_data[3] << 2) | ((int16_t)rx_data[4] << 10))& 0x07FF ;
    rc->ch2 -= 1024;	
    rc->ch3 = (((int16_t)rx_data[4] >> 1) | ((int16_t)rx_data[5]<<7)) & 0x07FF ; 
	  rc->ch3 -= 1024;	
     
    rc->s1 = (((int16_t)rx_data[5] >> 4) & 0x000C) >> 2; 
    rc->s2 = (((int16_t)rx_data[5] >> 4) & 0x0003); 
 
    rc->x = ((int16_t)rx_data[6]) | ((int16_t)rx_data[7] << 8); 
    rc->y = ((int16_t)rx_data[8]) | ((int16_t)rx_data[9] << 8); 
    rc->z = ((int16_t)rx_data[10]) | ((int16_t)rx_data[11] << 8);     
 
    rc->press_l = rx_data[12]; 
    rc->press_r = rx_data[13]; 
  
    rc->v = (rx_data[14]);
}
