//
// Created by 22560 on 25-4-22.
//

#include "MotorTask.h"

#include <cmath>

#include "Algorithm_Math.hpp"
#include "can.h"
#include "cmsis_os.h"
#include "freertos.h"
#include "task.h"
#include "Middleware_CAN.hpp"
#include "Device_GM6020.hpp"

extern GM6020 GM6020_1;
extern GM6020 GM6020_2;
extern GM6020 GM6020_3;
extern GM6020 GM6020_4;
extern Class_CAN CPP_CAN1;
extern GM6020_All GM6020_All1;

float P = 3.14f;

void CPP_Motor_Task() {
    //电机类Init
    GM6020_4.Init(4, &hcan1);
    GM6020_All1.Init(nullptr, nullptr, nullptr, &GM6020_4);

    TickType_t xLastWakeTime;
    const TickType_t xFrequency = 1  / portTICK_PERIOD_MS; // 周期为1ms
    xLastWakeTime = xTaskGetTickCount();
    int cnt = 0;
    while (1) {
        //生成正弦波信号
        cnt = (cnt == 500) ? 0 : cnt + 1;
        P = 3 + 2.5 * sin(2 * PI * (1.0f / 500) * cnt);

        GM6020_4.Ctrl_Angle(P);
        GM6020_All1.Ctrl_Current();
        vTaskDelayUntil(&xLastWakeTime, xFrequency);
    }
}

extern "C" {
void Motor_Task(void const* argument) {
    CPP_Motor_Task();
}
}
