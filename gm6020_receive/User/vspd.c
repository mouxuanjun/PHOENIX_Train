#include "vspd.h"
#include "stdio.h"
#include "string.h"
#include "stdarg.h"
#include "usart.h"
#include "usb_device.h"
#include "usbd_cdc_if.h"
#include "cmsis_os.h"
#include "freertos.h"
#include "usb_device.h"
#include "dri_can.h"
#include "motor.h"
#include "usbd_cdc_if.h"

#define TX_BUF_LEN  256     

extern motor gm6020;

uint8_t TxBuf[TX_BUF_LEN];  
void UartPrintf(const char *__format, ...)
{
    va_list ap;
    va_start(ap, __format);
    memset(TxBuf, 0x0, TX_BUF_LEN);
    vsnprintf((char*)TxBuf, TX_BUF_LEN, (const char *)__format, ap);
    va_end(ap);
    int len = strlen((const char*)TxBuf);
    CDC_Transmit_FS(TxBuf, len);
}

void Can_task(void const * argument)
{
    MX_USB_DEVICE_Init();
	 int8_t CDC_Init_FS();
    can_filter_init();
	for(;;)
	{
    UartPrintf("%d,%d\r\n",
      gm6020.angle,
      gm6020.speed);
    osDelay(10);
	}
}
