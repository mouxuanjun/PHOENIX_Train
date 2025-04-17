#include "DBUS.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

extern rc_info_t rc;

void RemoteDataProcess(rc_info_t *rc, uint8_t rx_data[18]){
    rc -> ch0 = (((int16_t)rx_data[0] | ((int16_t)rx_data[1] << 8)) & 0x07ff) - 1024;
    rc -> ch1  = (((int16_t)(rx_data[1] >> 3) | ((int16_t)rx_data[2] << 5)) & 0x07ff) - 1024;
    rc -> ch2 = (((int16_t)(rx_data[2] >> 6) | ((int16_t)rx_data[3] << 2) | ((int16_t)rx_data[4] << 10)) &0x07ff) - 1024;
    rc -> ch3 = (((int16_t)(rx_data[4] >> 1) | ((int16_t)rx_data[5] << 7)) & 0x07ff) - 1024;
    rc -> s1 = ((int16_t)(rx_data[5] >> 4) & 0x0003);
    rc -> s2 = ((int16_t)(rx_data[5] >> 4) & 0x000C) >> 2;
}
