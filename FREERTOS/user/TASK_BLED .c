#include "TASK_BLED.h"
void TASK_BLED(void const * argument)
{
    while(1)
    {
        HAL_GPIO_WritePin(GPIOH, GPIO_PIN_10, GPIO_PIN_SET);
        osDelay(1000);
        HAL_GPIO_WritePin(GPIOH, GPIO_PIN_10, GPIO_PIN_RESET);
        osDelay(1000);
        HAL_GPIO_WritePin(GPIOH, GPIO_PIN_10, GPIO_PIN_RESET);
        osDelay(1000);
    }
}

