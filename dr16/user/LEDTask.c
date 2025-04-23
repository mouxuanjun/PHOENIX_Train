#include "LEDTask.h"
extern rc_info_t rc;
extern mouse_info_t mouse;
extern key_info_t key;

void TASK_LED(void const * argument)
{
	while(1)
	{
		if(rc.s1 == 1)
		{
			HAL_GPIO_WritePin(GPIOH,GPIO_PIN_10,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOH,GPIO_PIN_11,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOH,GPIO_PIN_12,GPIO_PIN_RESET);
		}
		if(rc.s1 == 2)
		{
			HAL_GPIO_WritePin(GPIOH,GPIO_PIN_10,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOH,GPIO_PIN_11,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOH,GPIO_PIN_12,GPIO_PIN_RESET);
		}
		if(rc.s1 == 3)
		{
			HAL_GPIO_WritePin(GPIOH,GPIO_PIN_10,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOH,GPIO_PIN_11,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOH,GPIO_PIN_12,GPIO_PIN_SET);
		}
	}
}

