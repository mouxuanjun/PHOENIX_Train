//
// Created by 22560 on 25-4-17.
//

#include "cpp_main.h"

int cpp_main(void) {
    HAL_GPIO_WritePin(GPIOH,GPIO_PIN_11,GPIO_PIN_RESET);

    while(1) {
        HAL_GPIO_TogglePin(GPIOH,GPIO_PIN_11);
        HAL_Delay(500);
    }
}
