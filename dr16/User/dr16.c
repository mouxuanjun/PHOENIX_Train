#include "dr16.h"

rc_info_t rc; //定义了一个rc_info_t类型的变量rc

/***************************************************
* @brief 从 rx_data 数组中提取数据，并将其处理后存储到 rc 结构体的 chx 成员中
* @param 参数说明 :rc_info_t *rc：一个指向 rc_info_t 类型的指针，用于修改 rc 结构体的成员。
uint8_t rx_data[18]：一个包含 18 个 uint8_t 类型元素的数组，用于存储接收到的数据
* @return 返回值说明 
* @date 2025/4/13
* @author DingYong
***************************************************/
void RemoteDataProcess(rc_info_t *rc,uint8_t rx_data[18])
{
	rc->ch0 = ((int16_t) rx_data[0] | (int16_t) rx_data[1]<<8 ) & 0x07FF -1024;
	rc->ch1 = (((int16_t) rx_data[1] >> 3) | ((int16_t) rx_data[2] << 5))
& 0x07FF -1024;
	rc->ch2 = (((int16_t) rx_data[2] >> 6) | ((int16_t) rx_data[3] << 2) |
((int16_t) rx_data[4] << 10)) & 0x07FF -1024;
	rc->ch3 = (((int16_t) rx_data[4] >> 1) | ((int16_t) rx_data[5]<<7)) &
0x07FF -1024;
	rc->s1 = ((rx_data[5] >> 4) & 0x000C) >> 2;
	rc->s2	= ((rx_data[5] >> 4) & 0x0003);
	
}
