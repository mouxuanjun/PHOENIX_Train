#include "vofa.h"
#include <stdio.h>
#include <stdarg.h>
#include "usart.h"
#include "GM6020.h"
#include "rxcan.h"
#include "cmsis_os.h"
#include "usbd_cdc_if.h"

void usb_printf(const char *fmt,...)
{
  static uint8_t tx_buf[16] = {0};
  static va_list ap;
  static uint16_t len;
  va_start(ap, fmt);
  len = vsprintf((char *)tx_buf, fmt, ap);
  va_end(ap);
//  HAL_UART_Transmit_DMA(&huart1,tx_buf,len);
	CDC_Transmit_FS(tx_buf, len);
}

void VOFA_Tx(void){
	usb_printf("%d\r\n", GM6020.GM6020_angle);
}

void vofaTask(void const * argument){
	Filter_Init();
  int8_t CDC_Init_FS(void);
	while(1){
		VOFA_Tx();
	}
}
