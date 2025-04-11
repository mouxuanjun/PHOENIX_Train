//
// Created by 22560 on 25-4-11.
//

#ifndef LED_H
#define LED_H

#include "main.h"

typedef struct {
    uint8_t color;
    uint16_t period;
    uint8_t channel;

    TIM_HandleTypeDef* htim;
}LED_HandleTypedef;

void LED_Init(LED_HandleTypedef* LED, TIM_HandleTypeDef* htim,uint8_t color,uint16_t period,uint8_t channel);

void LED_Flow(LED_HandleTypedef* LED,uint16_t period);
#endif //LED_H
