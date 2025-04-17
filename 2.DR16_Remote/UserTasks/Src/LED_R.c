//
// Created by 22560 on 25-4-11.
//

#include "LED_R.h"
#include "LED.h"
#include "tim.h"

LED_HandleTypedef LED_R;
extern RC_t RC;

void LED_R_Task(void const * argument) {
    LED_Init(&LED_R, &htim5,'R',1000,3);

    while(1) {
        if(RC.s1 == 3) {
            LED_Flow(&LED_R, 1000);
        }
    }
}
