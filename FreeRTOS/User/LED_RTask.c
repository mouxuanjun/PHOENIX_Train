#include "LED_RTask.h"
void LED_RTask(void const * argument)
{
    while (1)
    {
        HAL_GPIO_TogglePin(GPIOH, GPIO_PIN_12);
        osDelay(1000);
    }
}


