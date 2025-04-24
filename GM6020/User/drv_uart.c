#include "drv_uart.h"

extern Motor_GM6020_t GM6020;
#define TX_BUF_LEN  256   
uint8_t TxBuf[TX_BUF_LEN]; 
void UART_Printf(const char *__format, ...)
{
  va_list ap;
  va_start(ap, __format);
  memset(TxBuf, 0x0, TX_BUF_LEN);
  vsnprintf((char*)TxBuf, TX_BUF_LEN, (const char *)__format, ap);
  va_end(ap);
  int len = strlen((const char*)TxBuf);
  CDC_Transmit_FS(TxBuf,len);
}

void can_rx_Task(void const * argument)
{

	for(;;)
  {
    UART_Printf("%d,%d\r\n",GM6020.motor_angle,GM6020.motor_speed);
		osDelay(10);
  }
}
