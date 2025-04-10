#include "TASK_RLED.h"
void TASK_RLED(void const * argument)
{
    while(1)
    {
        HAL_GPIO_WritePin(GPIOH, GPIO_PIN_12, GPIO_PIN_RESET);
        osDelay(1000);
        HAL_GPIO_WritePin(GPIOH, GPIO_PIN_12, GPIO_PIN_RESET);
        osDelay(1000);
        HAL_GPIO_WritePin(GPIOH, GPIO_PIN_12, GPIO_PIN_SET);
        osDelay(1000);
    }
}

