#include "led.h"

void LEDTask(void const * argument){
	while(1){
		if (rc_ctrl.rc.s2 == 1){
			HAL_GPIO_WritePin(GPIOH, GPIO_PIN_12,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOH, GPIO_PIN_11,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOH, GPIO_PIN_10,GPIO_PIN_RESET);
		}
		else if (rc_ctrl.rc.s2 == 2){
			HAL_GPIO_WritePin(GPIOH, GPIO_PIN_12,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOH, GPIO_PIN_11,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOH, GPIO_PIN_10,GPIO_PIN_RESET);
		}
		else if (rc_ctrl.rc.s2 == 3){
			HAL_GPIO_WritePin(GPIOH, GPIO_PIN_12,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOH, GPIO_PIN_11,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOH, GPIO_PIN_10,GPIO_PIN_SET);
		}
    if (rc_ctrl.key.shift){
			HAL_GPIO_WritePin(GPIOH, GPIO_PIN_12,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOH, GPIO_PIN_11,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOH, GPIO_PIN_10,GPIO_PIN_RESET);
		}
	}
}
