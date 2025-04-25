#include "vofa.h"
#include "usbd_cdc_if.h"
#include "main.h"
#include "usart.h"
#include "stdarg.h"
#include "gm6020.h"
#include "stdarg.h"
#include "freertos.h"
#include "usbd_cdc_if.h"
#include "cmsis_os.h"
#include <stdarg.h>

extern motor_measure_t gm6020;

uint8_t tx_data[256];

void usb_printf(const char *format, ...)                                          
{
    va_list args;
    uint32_t length;
    va_start(args, format);
    length = vsnprintf((char *)tx_data, sizeof tx_data, (char *)format, args);
    va_end(args);
    CDC_Transmit_FS(tx_data, length);
}

	
void vofa_Task(void const * argument)
{
  int8_t CDC_Init_FS();
  while(1)
  {
		usb_printf("%d\n,%d\r\n",gm6020.mechanical_angle,gm6020.speed_rpm);
    osDelay(1000);
  }
  
}
