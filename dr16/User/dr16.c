#include "dr16.h"
rx rc;
void RemoteData(rx *rc,uint8_t rx_data[18]){
    rc->channel_0 = (( (int16_t)rx_data[0] | (int16_t)rx_data[1] << 8 ) & 0x07FF ) - 1024;
    rc->channel_1 = (( (int16_t)rx_data[1] >> 3 | (int16_t)rx_data[2] << 5 ) & 0x07FF ) - 1024;
    rc->channel_2 = (( (int16_t)rx_data[2] >> 6 | (int16_t)rx_data[3] << 2 | (int16_t)rx_data[4] << 10 ) & 0x07FF ) - 1024;
    rc->channel_3 = (( (int16_t)rx_data[4] >> 1 | (int16_t)rx_data[5] << 7 ) & 0x07FF ) - 1024;
    rc->s1 = ( (int16_t)rx_data[5] >> 4 ) & 0x0003;
    rc->s2 = ( (int16_t)rx_data[5] >> 6 ) & 0x0003;
    rc->x = ((int16_t)rx_data[6] | (int16_t)rx_data[7] << 8 ) & 0xFFFF;
    rc->y = ((int16_t)rx_data[8] | (int16_t)rx_data[9] << 8 ) & 0xFFFF;
    rc->z = ((int16_t)rx_data[10] | (int16_t)rx_data[11] << 8 ) & 0xFFFF;
    rc->MouseLeft = rx_data[12] & 0x01;
    rc->MouseRight = rx_data[13] & 0x01;
    rc->PressW = rx_data[14] & 0x01;
    rc->PressS = (rx_data[14] >> 1 ) & 0x01;
    rc->PressA = (rx_data[14] >> 2 ) & 0x01;
    rc->PressD = (rx_data[14] >> 3 ) & 0x01;
    rc->PressQ = (rx_data[14] >> 4 ) & 0x01;
    rc->PressE = (rx_data[14] >> 5 ) & 0x01;
    rc->PressShift = (rx_data[14] >> 6 ) & 0x01;
    rc->PressCtrl = (rx_data[14] >> 7 ) & 0x01;
    rc->ReservedField = ((uint16_t)rx_data[16] | (uint16_t)rx_data[17] << 8 ) & 0xFFFF;
}
