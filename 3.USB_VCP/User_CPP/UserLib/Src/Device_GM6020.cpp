//
// Created by 22560 on 25-4-20.
//

#include "Device_GM6020.hpp"
#include "Device_GM6020.h"
#include "Middleware_CAN.hpp"

extern CPP_CAN CPP_CAN1;
extern CPP_CAN CPP_CAN2;

void GM6020::CPP_GM6020_init(uint8_t id,CAN_HandleTypeDef *hcan) {
    CPP_motor_id = id;
    CPP_Motor_hcan = hcan;
}

void GM6020::CPP_GM6020_update() {
    if(CPP_Motor_hcan->Instance == CAN1) {
        // if(CPP_CAN1.CPP_CAN_Rx_CAN_id != CPP_motor_id + 0x204) return;
        CPP_motor_info.angle_ecd = (CPP_CAN1.CPP_CAN_RxBuffer[0] << 8)|CPP_CAN1.CPP_CAN_RxBuffer[1];
        CPP_motor_info.speed_rpm = (CPP_CAN1.CPP_CAN_RxBuffer[2] << 8)|CPP_CAN1.CPP_CAN_RxBuffer[3];
        CPP_motor_info.current_raw = (CPP_CAN1.CPP_CAN_RxBuffer[4] << 8)|CPP_CAN1.CPP_CAN_RxBuffer[5];
        CPP_motor_info.temperate = CPP_CAN1.CPP_CAN_RxBuffer[6];
    }else if(CPP_Motor_hcan->Instance == CAN2) {
        // if(CPP_CAN2.CPP_CAN_Rx_CAN_id != CPP_motor_id + 0x204) return;
        CPP_motor_info.angle_ecd = (CPP_CAN2.CPP_CAN_RxBuffer[0] << 8)|CPP_CAN2.CPP_CAN_RxBuffer[1];
        CPP_motor_info.speed_rpm = (CPP_CAN2.CPP_CAN_RxBuffer[2] << 8)|CPP_CAN2.CPP_CAN_RxBuffer[3];
        CPP_motor_info.current_raw = (CPP_CAN2.CPP_CAN_RxBuffer[4] << 8)|CPP_CAN2.CPP_CAN_RxBuffer[5];
        CPP_motor_info.temperate = CPP_CAN2.CPP_CAN_RxBuffer[6];
    }
}

GM6020 GM6020_1;
GM6020 GM6020_2;
GM6020 GM6020_3;
GM6020 GM6020_4;

void CPP_GM6020_update(uint32_t CAN_id) {
    switch(CAN_id) {
    case 0x205:GM6020_1.CPP_GM6020_update();break;
    case 0x206:GM6020_2.CPP_GM6020_update();break;
    case 0x207:GM6020_3.CPP_GM6020_update();break;
    case 0x208:GM6020_4.CPP_GM6020_update();break;
    }
}

extern "C" {
    void GM6020_1_Init(CAN_HandleTypeDef *hcan) {
        GM6020_1.CPP_GM6020_init(1, hcan);
    }
    void GM6020_2_Init(CAN_HandleTypeDef *hcan) {
        GM6020_2.CPP_GM6020_init(2, hcan);
    }
    void GM6020_3_Init(CAN_HandleTypeDef *hcan) {
        GM6020_3.CPP_GM6020_init(3, hcan);
    }
    void GM6020_4_Init(CAN_HandleTypeDef *hcan) {
        GM6020_4.CPP_GM6020_init(4, hcan);
    }
    void GM6020_update() {
        CPP_GM6020_update(CPP_CAN1.CPP_CAN_Rx_CAN_id);
    }
}
