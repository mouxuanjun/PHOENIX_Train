#ifndef __DBUS_H__
#define __DBUS_H__

#include "main.h"

typedef struct{
    int16_t ch0;
    int16_t ch1;
    int16_t ch2;
    int16_t ch3;
    char s1;
    char s2;
} rc_info_t;

void RemoteDataProcess(rc_info_t *rc, uint8_t rx_data[18]);

#endif
