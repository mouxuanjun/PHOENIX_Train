#include "led.h"
#include "main.h"
#include "dr16.h"

extern RC_Ctrl_t RC_CtrlData;

void led(void const * argument)
{
	while(1)
	{
		if(RC_CtrlData.remote.ch0 == 1)
		{
			HAL_GPIO_WritePin(GPIOH,GPIO_PIN_10,GPIO_PIN_SET);
		    HAL_GPIO_WritePin(GPIOH,GPIO_PIN_11,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOH,GPIO_PIN_12,GPIO_PIN_RESET);
		}
		if(RC_CtrlData.remote.ch0 == 200)
		{
			HAL_GPIO_WritePin(GPIOH,GPIO_PIN_10,GPIO_PIN_RESET);
		    HAL_GPIO_WritePin(GPIOH,GPIO_PIN_11,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOH,GPIO_PIN_12,GPIO_PIN_RESET);
		}
		if(RC_CtrlData.remote.ch0 == 400)
		{
			HAL_GPIO_WritePin(GPIOH,GPIO_PIN_10,GPIO_PIN_RESET);
		    HAL_GPIO_WritePin(GPIOH,GPIO_PIN_11,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOH,GPIO_PIN_12,GPIO_PIN_SET);
		}
	}
}