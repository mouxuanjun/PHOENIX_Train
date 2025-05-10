#ifndef __REMOTE_CONTROL_H__
#define __REMOTE_CONTROL_H__

#include "main.h"
#include "dr16.h"
#include "pid.h"
#include "can_rx_tx.h"
#include "freertos.h"
#include "cmsis_os.h"

void remote_control(void const * argument);

#endif

