#include "dr16.h"
rx rc;
void RemoteData(rx *rc,uint8_t rx_data[18]){
rc->channel_0 = (( (int16_t)rx_data[0] | (int16_t)rx_data[1] << 8 ) & 0x07FF ) - 1024;
rc->channel_1 = (( (int16_t)rx_data[1] >> 3 | (int16_t)rx_data[2] << 5 ) & 0x07FF ) - 1024;
rc->channel_2 = (( (int16_t)rx_data[2] >> 6 | (int16_t)rx_data[3] << 2 | (int16_t)rx_data[4] << 10 ) & 0x07FF ) - 1024;
rc->channel_3 = (( (int16_t)rx_data[4] >> 1 | (int16_t)rx_data[5] << 7 ) & 0x07FF ) - 1024;
rc->s1 = ( (int16_t)rx_data[5] >> 4 ) & 0x0003;
rc->s2 = ( (int16_t)rx_data[5] >> 6 ) & 0x0003;
}
