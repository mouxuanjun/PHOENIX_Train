#ifndef __DRV_UART_H__
#define __DRV_UART_H__

#include "stdio.h"
#include "main.h"
#include "stdarg.h"
#include "string.h"
#include "dvc_gm6020.h"
#include "usb_device.h"
#include "usbd_cdc_if.h"
#include "drv_can.h"
#include "freertos.h"
#include "cmsis_os.h"

void UART_Printf(const char *__format, ...);
void can_rx_Task(void const * argument);


#endif
