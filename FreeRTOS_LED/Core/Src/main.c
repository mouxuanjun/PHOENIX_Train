/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint16_t pwmval = 0;
uint16_t buzzerval = 0;
int tones[12] = {261,270,293,311,329,349,370,392,415,440,466,493};
// int tones_arr[12] = {137931,133333,122866,115755,109422,103151,97297,91836,86746,81818,77253,73022};
int tones_arr[12] = {45977,44444,40955,38585,36474,34383,32432,30612,28915,27272,25751,24340};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_FREERTOS_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void playtone(int num){
  int arr = 0;
  int tone = tones[num-1];
  arr = 36000000.0/tone;
  __HAL_TIM_SET_AUTORELOAD(&htim4,arr);
  __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_3,(int)arr/4);
}
void playtone_arr(int num){
  int arr = tones_arr[num-1];
  __HAL_TIM_SET_AUTORELOAD(&htim4,arr);
  __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_3,(int)arr/4);
}
void stoptone(){
  __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_3,1);
}

void led_task(void const * argument){
  while(1){
	while(pwmval < 1000){
      pwmval++;
      __HAL_TIM_SetCompare(&htim5,TIM_CHANNEL_1,pwmval);	
	  __HAL_TIM_SetCompare(&htim5,TIM_CHANNEL_2,pwmval);
      __HAL_TIM_SetCompare(&htim5,TIM_CHANNEL_3,pwmval);
	  osDelay(2); 
	}		
	while(pwmval > 0){
      pwmval--;
      __HAL_TIM_SetCompare(&htim5,TIM_CHANNEL_1,pwmval);	
	  __HAL_TIM_SetCompare(&htim5,TIM_CHANNEL_2,pwmval);
      __HAL_TIM_SetCompare(&htim5,TIM_CHANNEL_3,pwmval);
	  osDelay(2); 
	}
   	 osDelay(200); 
  }

}


void buzzer_task(void const * argument){

    playtone_arr(2);
    osDelay(250);
    stoptone();
    playtone_arr(3);
    osDelay(250);
    stoptone();
    playtone_arr(6);
    osDelay(350);
    stoptone();



	  // playtone(1);
    // osDelay(500);
    // stoptone();
    // playtone(2);
    // osDelay(500);
    // stoptone();
    // playtone(1);
    // osDelay(500);
    // stoptone();

    __HAL_TIM_SET_AUTORELOAD(&htim4, 6000);
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 0);

    
    HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_3);
    
    
//    osDelay(1000);
//    osThreadTerminate(NULL);
    
	 while(1){
	   osDelay(1000);	 
	 }	 
   
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM5_Init();
  MX_TIM4_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Init(&htim4);
  HAL_TIM_Base_Init(&htim5);
  HAL_TIM_PWM_Start(&htim5,TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim5,TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim5,TIM_CHANNEL_3);
  HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_3);
  /* USER CODE END 2 */

  /* Call init function for freertos objects (in freertos.c) */
  MX_FREERTOS_Init();

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 72;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
