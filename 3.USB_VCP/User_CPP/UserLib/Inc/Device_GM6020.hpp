//
// Created by 22560 on 25-4-20.
//

#ifndef DEVICE_GM6020_HPP
#define DEVICE_GM6020_HPP

#include "main.h"

typedef struct {
    uint16_t angle_ecd;
    int16_t speed_rpm;
    int16_t current_raw;
    int16_t temperate;
}GM6020_t;

class GM6020 {
public:
    uint8_t CPP_motor_id;
    CAN_HandleTypeDef *CPP_Motor_hcan;
    GM6020_t CPP_motor_info;

    void CPP_GM6020_init(uint8_t id,CAN_HandleTypeDef *hcan);
    void CPP_GM6020_update();
};

#endif //DEVICE_GM6020_HPP
