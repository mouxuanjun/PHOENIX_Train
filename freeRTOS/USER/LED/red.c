#include "red.h"
void LED_RED(void const * argument)
{
  /* USER CODE BEGIN LED_RED */
  /* Infinite loop */
	for(  ;  ;  ){


		for(int i = 0 ; i <= 100 ; i++ ){
__HAL_TIM_SetCompare(&htim5,TIM_CHANNEL_3,i);
	osDelay(50);
}
		for(int i = 100 ; i >= 0 ; i-- ){
__HAL_TIM_SetCompare(&htim5,TIM_CHANNEL_4,i);
	osDelay(50);
}
	 }
  /* USER CODE END LED_RED */
}
