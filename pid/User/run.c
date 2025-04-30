#include "run.h"

pid angle;
pid speed;
float pid_angle[4]={0.5,0,1.5,10};
float pid_speed[4]={55,1.12,3,0};
float cnt=0;
float n=0;
uint8_t s = 0;
uint8_t rx_data[18]={0};
rx rc;
float cmd_motor[4]={0};
motor gm6020;


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
    RemoteData(&rc,rx_data);
}
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    CAN_RxHeaderTypeDef rx_header;
    uint8_t rx_data[8];
    HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &rx_header, rx_data);
if(rx_header.StdId == 0x205)                                      //观察电机小灯一秒亮n次，则地址取204+n
    {
    gm6020_data_process(&gm6020 , rx_data );
    }
}



void PID_IN(void const * argument){
    HAL_UART_Receive_DMA(&huart3,rx_data,18);
  	can_filter_init();
	
//    pid_init(&angle,pid_angle);

 for(;;){
//gm6020.speed_set = (int16_t)pid_angle_calc(&angle,&gm6020);
    osDelay(1);
    }
}

void PID_OUT(void const * argument){
    MX_USB_DEVICE_Init();
    pid_init(&speed,pid_speed);

	  pid_init(&angle,pid_angle);  //双环记得删

    CAN_TxHeaderTypeDef tx_header;
    tx_header.DLC = 8;
    tx_header.IDE = CAN_ID_STD;
    tx_header.RTR = CAN_RTR_DATA;
	
    GM6020_Tx_Init();
	
 for(;;){
//    cnt+=600;	 
//		gm6020.angle_set=1024*s;
//		
//		 if(cnt > 600000)
//		{		cnt = 0;
//	      s++;
//		}
//		if(s >= 8)
//			s=0;
//	 
		if(rc.s1 == 1 ){
    gm6020.speed_set = 250 * rc.channel_1 / 660;
		}
	 else if(rc.s1 == 2 ){
	 		gm6020.angle_set +=  8 * rc.channel_0/660 ;
				if(gm6020.angle_set < 0){
    gm6020.angle_set += 8192;
}
		else if(gm6020.angle_set > 8191){
		gm6020.angle_set-= 8192;
}		
	 gm6020.speed_set = pid_angle_calc(&angle,&gm6020);

}
 cmd_motor[1]=(int16_t)pid_speed_calc(&speed,&gm6020);
	 	GM6020_Tx(&tx_header,1,
	           (int16_t)cmd_motor[1],
	           (int16_t)cmd_motor[1],
	           (int16_t)cmd_motor[1],
	           (int16_t)cmd_motor[1]);
    osDelay(1);
}


   
}    
