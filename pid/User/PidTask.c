#include "PidTask.h"

void PidTask(void const * argument)
{
  /* USER CODE BEGIN PidTask */
  /* Infinite loop */
    extern motor_measure_t gm6020;
    extern pidcontroller SpeedPid;
    extern pidcontroller AnglePid;
    extern rc_info_t rc;
	  extern uint8_t rx_data[18];
	  can_filter_init();
    float current_speed;
	  float current_angle;
    float target_angle;
    float target_speed;
    float *motor1;
	  float angle_max = 320;
	  float speed_max = 40000;
    pid_init(&SpeedPid,42.0,4.6,3.5,&current_speed,&target_speed); 	
    pid_init(&AnglePid,0.3,0.00012,0.4,&current_angle,&target_angle);     
    HAL_UART_Receive_DMA(&huart3,rx_data,18);
  for(;;)
  {
    target_angle += (rc.ch0/16);
		if(target_angle > 8192)
		  target_angle = target_angle - (target_angle / 8192)*8192;
	  else if(target_angle < 0)
		  target_angle = target_angle + (target_angle / 8192)*8192 + 8192;
    current_angle = gm6020.mechanical_angle * 1.0;
    current_speed = gm6020.speed_rpm * 1.0;
    pid_update_angle(&AnglePid,&target_angle,&current_angle,&angle_max);
    pid_update_speed(&SpeedPid,&AnglePid.output,&current_speed,&speed_max);
	  motor1 = &SpeedPid.output;
    set_gm6020_motor_voltage(&hcan1,motor1);
    osDelay(1);
    HAL_GPIO_TogglePin(GPIOH,GPIO_PIN_12);
}
  
  /* USER CODE END PidTask */
}
