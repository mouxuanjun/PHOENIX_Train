#include "blue.h"
void LED_BLUE(void const *	argument)
{
  /* USER CODE BEGIN LED_RED */
  /* Infinite loop */
	for(  ;  ;  ){

		for(int i = 0 ; i <= 100 ; i++ ){
__HAL_TIM_SetCompare(&htim5,TIM_CHANNEL_1,i);
	osDelay(10);
}
		for(int i = 100 ; i >= 0 ; i-- ){
__HAL_TIM_SetCompare(&htim5,TIM_CHANNEL_1,i);
	osDelay(10);
}
	 }
  /* USER CODE END LED_RED */
}
