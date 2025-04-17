#include "led.h"
#include "dr16.h"
extern rx rc;
void LED_Task(void const * argument)
{
  /* USER CODE BEGIN LED_Task */
  /* Infinite loop */
  for(;;)
  {
		if(rc.s1 == 1){
    HAL_GPIO_WritePin(GPIOH,GPIO_PIN_10,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOH,GPIO_PIN_11,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOH,GPIO_PIN_12,GPIO_PIN_RESET);
    }

    else if(rc.s1 == 2){
        HAL_GPIO_WritePin(GPIOH,GPIO_PIN_10,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOH,GPIO_PIN_11,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOH,GPIO_PIN_12,GPIO_PIN_SET);
    }
    
    else if(rc.s1 == 3){
        HAL_GPIO_WritePin(GPIOH,GPIO_PIN_10,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOH,GPIO_PIN_11,GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOH,GPIO_PIN_12,GPIO_PIN_RESET);
    }
    osDelay(1);
  }
  /* USER CODE END LED_Task */
}
