#ifndef __USB_HANDEL_H_
#define __USB_HANDEL_H_

#include "main.h"
#include "can.h"
#include "stm32f4xx.h"
#include "dvc_dji_gm6020.h"


typedef struct
{   
    float P;//�趨�ٶ�
    float I;//�趨�Ƕ�
	  float D;

}PID;

#endif
