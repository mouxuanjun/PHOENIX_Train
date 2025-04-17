#ifndef __DR16_H__
#define __DR16_H__
#include "main.h"
typedef struct{
    int16_t channel_0;
    int16_t channel_1;
    int16_t channel_2;
    int16_t channel_3;
    uint8_t s1;
    uint8_t s2;
}rx;
void RemoteData(rx *rc,uint8_t rx_data[18]);
#endif
