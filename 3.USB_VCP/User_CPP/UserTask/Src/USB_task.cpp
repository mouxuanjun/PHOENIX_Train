//
// Created by 22560 on 25-4-18.
//

#include "USB_task.h"
#include "freertos.h"
#include "cmsis_os.h"
#include "usbd_cdc_if.h"

class USB_Data {
public:
    uint8_t CPP_myUSBRxData[64];
    uint16_t CPP_myUSBRxNum;
    uint8_t CPP_myUSBTxData[64];
    uint16_t CPP_myUSBTxNum;
    void CPP_USBData_Process(void);
    void CPP_USBData_GetData(uint8_t* Buf, uint32_t *Len);
    void CPP_USBData_SendData(uint8_t* Buf, uint32_t *Len);
};

void USB_Data :: CPP_USBData_Process(void) {
    if(CPP_myUSBRxNum) {
        char myStr[100] = {0};
        sprintf(myStr, "\rUSB Received Data %dbit :%s \r", CPP_myUSBRxNum,(char *)CPP_myUSBRxData);
        CDC_Transmit_FS((uint8_t *)myStr, strlen(myStr));

        memset(CPP_myUSBRxData, 0, 64); //数据处理后清空缓存区
        CPP_myUSBRxNum = 0;//有利于判断，置0
    }
}

void USB_Data :: CPP_USBData_GetData(uint8_t* Buf, uint32_t* Len) {
    memset(CPP_myUSBRxData, 0, 64); //清空缓存区
    memcpy(CPP_myUSBRxData, Buf, *Len); //接收的数据复制到缓存区
    CPP_myUSBRxNum = *Len;//复制字节数
}

void USB_Data :: CPP_USBData_SendData(uint8_t* Buf, uint32_t* Len) {
    memset(CPP_myUSBTxData, 0, 64);
    memcpy(CPP_myUSBTxData, Buf, *Len);
    CPP_myUSBTxNum = *Len;
    CDC_Transmit_FS(Buf,*Len);
    memset(CPP_myUSBTxData, 0, 64);
}

USB_Data USB_Data1;

void CPP_USB_Task(){
    uint32_t TxLen = 10;

    while(1) {
        osDelay(1000);
        USB_Data1.CPP_USBData_Process();
        USB_Data1.CPP_USBData_SendData((uint8_t*)"&USB_Data1", &TxLen);

    }
  }

extern "C" {
    void USB_Task(void const * argument) {
        CPP_USB_Task();
        }

    void USBData_Process() {
        USB_Data1.CPP_USBData_Process();
    }

    void USBData_GetData(uint8_t* Buf, uint32_t *Len) {
        USB_Data1.CPP_USBData_GetData(Buf, Len);
    }
    void USBData_SendData(uint8_t* Buf, uint32_t *Len) {
        USB_Data1.CPP_USBData_SendData(Buf, Len);
    }
}
