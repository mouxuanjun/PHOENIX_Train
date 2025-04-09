#include "LED_B.h"
void LED_BTask(void const * argument)
{
	for(;;)
  {
		HAL_GPIO_TogglePin(LED_B_GPIO_Port,LED_B_Pin);
    osDelay(1000);
  }
}
