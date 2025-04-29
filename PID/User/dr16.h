#ifndef DR16_H
#define DR16_H
#include "stdint.h"
#include "usart.h"
#include "stdlib.h"
#include "string.h"

#define dbus_buf_len 18
#define dbus_huart huart3

typedef struct {
    uint16_t channel_0;
    uint16_t channel_1;
    uint16_t channel_2;
    uint16_t channel_3;
    uint8_t s1;
    uint8_t s2;
    uint16_t mouse_x;
    uint16_t mouse_y;
    uint16_t mouse_z;
    uint8_t mouse_left;
    uint8_t mouse_right;
    uint16_t button;
} Dr16_Receive_Data;

void Deserialize_DR16_Data(uint8_t *buffer, Dr16_Receive_Data *data);


void dma_init(void);

#endif // DR16_H


