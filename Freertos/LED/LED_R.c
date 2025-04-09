#include "LED_R.h"
void LED_RTask(void const * argument)
{
	for(;;)
  {
		HAL_GPIO_TogglePin(LED_R_GPIO_Port,LED_R_Pin);
    osDelay(1000);
  }
}
