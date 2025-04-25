#include "gm6020.h"

HAL_StatusTypeDef can_1;

extern motor_measure_t gm6020;

void get_gm6020_data(uint32_t id, uint8_t data[8]) {
    switch (id) {
        case 0x205:
               
            gm6020.mechanical_angle = ((data)[0] << 8 | (data)[1]);            
            gm6020.speed_rpm        = ((data)[2] << 8 | (data)[3]);      
            gm6020.torque_current   = ((data)[4] << 8 | (data)[5]);  
            gm6020.temp             = (data)[6];
            
            break;
    }
        
}
