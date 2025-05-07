#include"motor_run.h"
#include"math.h"

void motor_init(void){
    const float pid_const[3] = {25,2,1};//speed{25,2,1},angle{130,0,0}
    pid_init(&motor_data.motor_pid[1], pid_const[0],pid_const[1],pid_const[2],PID_MAX_OUTPUT ,PID_MAX_IOUT);
}


void motor_control(void const * argument){
    motor_init();
	  float count=0;
    while(1){
        motor_data.angle_set=dr16_receive.s1*100-200;
        motor_data.angle=motor6020rx.speed;
        motor_data.give_current=pid_calc(&motor_data.motor_pid[1], motor_data.angle_set, motor_data.angle,8191);

        motor_write(0x1FF,motor_data.give_current,0,0,0);
        osDelay(1);
			  count+=0.01;
				

    }


}