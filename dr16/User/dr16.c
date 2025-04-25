#include "dr16.h"

RC_Ctrl_t RC_CtrlData;

void Get_DR16_Data(uint8_t *Buff)
{
	RC_CtrlData.remote.ch0 = (Buff[0] | Buff[1] << 8) & 0x07FF;
	RC_CtrlData.remote.ch0 -= 1024;
}
	