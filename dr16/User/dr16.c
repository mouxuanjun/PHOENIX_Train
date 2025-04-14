#include "dr16.h"

rc_info_t rc; //������һ��rc_info_t���͵ı���rc

/***************************************************
* @brief �� rx_data ��������ȡ���ݣ������䴦���洢�� rc �ṹ��� chx ��Ա��
* @param ����˵�� :rc_info_t *rc��һ��ָ�� rc_info_t ���͵�ָ�룬�����޸� rc �ṹ��ĳ�Ա��
uint8_t rx_data[18]��һ������ 18 �� uint8_t ����Ԫ�ص����飬���ڴ洢���յ�������
* @return ����ֵ˵�� 
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
