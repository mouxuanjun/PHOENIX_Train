#ifndef __DR16_H__
#define __DR16_H__
#include "main.h"
typedef struct{
    int16_t channel_0;
    int16_t channel_1;
    int16_t channel_2;
    int16_t channel_3;
    int16_t x;
    int16_t y;
    int16_t z;
    uint16_t ReservedField;
    uint8_t MouseLeft;
    uint8_t MouseRight;
    uint8_t s1;
    uint8_t s2;
    uint8_t PressW;
    uint8_t PressS;
    uint8_t PressA;
    uint8_t PressD;
    uint8_t PressQ;
    uint8_t PressE;
    uint8_t PressCtrl;
    uint8_t PressShift;
}rx;
void RemoteData(rx *rc,uint8_t rx_data[18]);

#endif
