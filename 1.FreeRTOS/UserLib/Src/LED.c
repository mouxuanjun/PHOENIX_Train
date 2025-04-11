//
// Created by 22560 on 25-4-11.
//

#include "LED.h"

#include "cmsis_os.h"
#include "FreeRTOS.h"
#include "math.h"

void LED_Init(LED_HandleTypedef* LED, TIM_HandleTypeDef* htim,uint8_t color,uint16_t period,uint8_t channel) {
    LED->color = color;
    LED->period = period;
    LED->htim = htim;
    LED->channel = channel;

    switch (LED->channel) {
        case 1:
            HAL_TIM_PWM_Start(htim, TIM_CHANNEL_1);
        case 2:
            HAL_TIM_PWM_Start(htim, TIM_CHANNEL_2);
        case 3:
            HAL_TIM_PWM_Start(htim, TIM_CHANNEL_3);
    }
}

void LED_Flow(LED_HandleTypedef* LED,uint16_t period) {
    LED->period = period;

    switch(LED->channel) {
        case 1:
            float cnt1 = 0;
            for(int i=0;i<LED->period;i++) {
                cnt1 = i * (3.1415927 / LED->period);
                uint32_t compare = 1000*sin(cnt1);
                __HAL_TIM_SET_COMPARE(LED->htim,TIM_CHANNEL_1,compare);
                osDelay(1);
            }
        case 2:
            float cnt2 = 0;
            for(int i=0;i<LED->period;i++) {
                cnt2 = i * (3.1415927 / LED->period);
                uint32_t compare = 1000*sin(cnt2);
                __HAL_TIM_SET_COMPARE(LED->htim,TIM_CHANNEL_2,compare);
                osDelay(1);
            }
        case 3:
            float cnt3 = 0;
            for(int i=0;i<LED->period;i++) {
                cnt3 = i * (3.1415927 / LED->period);
                uint32_t compare = 1000*sin(cnt3);
                __HAL_TIM_SET_COMPARE(LED->htim,TIM_CHANNEL_3,compare);
                osDelay(1);
            }
    }
}
