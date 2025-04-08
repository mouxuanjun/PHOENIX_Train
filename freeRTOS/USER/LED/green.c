#include "green.h"
void LED_GREEN(void const * argument)
{
  /* USER CODE BEGIN LED_RED */
  /* Infinite loop */
	for(  ;  ;  ){

		for(int i = 0 ; i <= 100 ; i++ ){
__HAL_TIM_SetCompare(&htim5,TIM_CHANNEL_2,i);
	osDelay(20);
}
		for(int i = 100 ; i >= 0 ; i-- ){
__HAL_TIM_SetCompare(&htim5,TIM_CHANNEL_2,i);
	osDelay(20);
}
		}
  /* USER CODE END LED_RED */
}
