#include "LED_G.h"
void LED_GTask(void const * argument)
{
	for(;;)
  {
		HAL_GPIO_TogglePin(LED_G_GPIO_Port,LED_G_Pin);
    osDelay(1000);
  }
}
