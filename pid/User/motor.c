#include "motor.h"

HAL_StatusTypeDef can_1;

extern motor_measure_t gm6020;

void get_gm6020_data(uint32_t id, uint8_t data[8]) {
    switch (id) {
        case 0x208:
               
            gm6020.mechanical_angle = ((int16_t)(data)[0] << 8 | (int16_t)(data)[1]);            
            gm6020.speed_rpm        = ((int16_t)(data)[2] << 8 | (int16_t)(data)[3]);      
            gm6020.torque_current   = ((int16_t)(data)[4] << 8 | (int16_t)(data)[5]);  
            gm6020.temp             = (int16_t)(data)[6];
            break;
    }
        
}


