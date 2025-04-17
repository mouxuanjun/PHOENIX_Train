//
// Created by 22560 on 25-4-11.
//

#include "LED_B.h"
#include "LED.h"
#include "tim.h"

LED_HandleTypedef LED_B;
extern RC_t RC;

void LED_B_Task(void const * argument) {
    LED_Init(&LED_B, &htim5,'G',5000,1);

    while(1) {
        if(RC.s1 == 1) {
            LED_Flow(&LED_B, 5000);
        }
    }
}
