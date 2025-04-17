//
// Created by 22560 on 25-4-11.
//

#include "LED_G.h"
#include "LED.h"
#include "tim.h"

LED_HandleTypedef LED_G;
extern RC_t RC;

void LED_G_Task(void const * argument) {
    LED_Init(&LED_G, &htim5,'G',3000,2);

    while(1) {
        if(RC.s1 == 2) {
            LED_Flow(&LED_G, 3000);
        }
    }
}
