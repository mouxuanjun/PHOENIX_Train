#include "poweroff.h"


void Power_off(void const * argument){
    while(1){
        if(dr16_receive.s2==1){
            motor_write(0x1FF,0,0,0,0);
            osDelay(1);
        }
    
    }
}