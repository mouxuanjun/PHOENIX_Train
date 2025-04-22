#include "GM6020.h"

void GM6020_RxData(uint32_t StdID, uint8_t rx_data[8]){
	if (StdID == 0x205){
		GM6020.GM6020_angle = ((rx_data[0] << 8) | rx_data[1]);
		GM6020.GM6020_speed = ((rx_data[2] << 8) | rx_data[3]);
		GM6020.GM6020_current = ((rx_data[4] << 8) | rx_data[5]);
		GM6020.GM6020_temp = rx_data[6];
	}
}
