#include "TASK_GLED.h"
void TASK_GLED(void const * argument)
{
    while(1)
    {
        HAL_GPIO_WritePin(GPIOH, GPIO_PIN_11, GPIO_PIN_RESET);
        osDelay(1000);
        HAL_GPIO_WritePin(GPIOH, GPIO_PIN_11, GPIO_PIN_SET);
        osDelay(1000);
        HAL_GPIO_WritePin(GPIOH, GPIO_PIN_11, GPIO_PIN_RESET);
        osDelay(1000);
    }
}

