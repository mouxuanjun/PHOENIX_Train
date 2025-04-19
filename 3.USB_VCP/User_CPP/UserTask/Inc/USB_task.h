//
// Created by 22560 on 25-4-18.
//

#ifndef USB_TASK_H
#define USB_TASK_H



#include "main.h"


#ifdef __cplusplus
extern "C"{
#endif
    void USB_Task(void const * argument);

    void USBData_Process();

    void USBData_GetData(uint8_t* Buf, uint32_t *Len);

    void USBData_SendData(uint8_t* Buf, uint32_t *Len);
#ifdef __cplusplus
    }
#endif

#endif //USB_TASK_H
