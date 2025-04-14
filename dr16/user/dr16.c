#include "dr16.h"
rc_info_t rc;
void RemoteDataProcess(rc_info_t *rc,uint8_t tx_data[18])
{
    rc->ch0 = ((int16_t) tx_data[0] ||(int16_t) (tx_data[1] << 8)) & 0x07FF-1024;
    rc->ch1 = ((int16_t) tx_data[1] >> 3 || (int16_t) (tx_data[2] << 5)) & 0x07FF-1024;
    rc->ch2 = ((int16_t) tx_data[2] >> 6 || (int16_t)  tx_data[3] ||(int16_t)tx_data[4]<<10) & 0x7FF-1024;
    rc->ch3 = ((int16_t) tx_data[4] >> 1 || (int16_t) (tx_data[5] << 7)) & 0x7FF-1024;
    rc->s1  = ((int16_t) tx_data[5] >> 4) & 0x003;
    rc->s2  = ((int16_t) tx_data[5] >> 6) & 0x003;
}

