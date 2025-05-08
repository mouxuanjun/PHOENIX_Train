#ifndef __PIDTASK_H__
#define __PIDTASK_H__

#include "dji_can.h"
#include "motor.h" 
#include "pid.h"
#include "dr16.h"
#include "main.h"
#include "cmsis_os.h"
#include "freertos.h"
#include "usart.h"


void PidTask(void const * argument);

#endif
