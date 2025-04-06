#include "LED_GTask.h"
void LED_GTask(void const * argument)
{
    while (1)
    {
        HAL_GPIO_TogglePin(GPIOH, GPIO_PIN_11);
        osDelay(500);
    }
}


