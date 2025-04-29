#include "dr16.h"


Dr16_Receive_Data dr16_data = {0};
uint8_t dr16_buffer[dbus_buf_len] = {0};

void Deserialize_DR16_Data(uint8_t *buffer, Dr16_Receive_Data *data)
{
    data->channel_0 = (((int16_t)buffer[0] | ((int16_t)buffer[1] << 8)) & 0x07ff) - 1024;
    data->channel_1 =  (((int16_t)(buffer[1] >> 3) | ((int16_t)buffer[2] << 5)) & 0x07ff) - 1024;
    data->channel_2 = (((int16_t)(buffer[2] >> 6) | ((int16_t)buffer[3] << 2) | ((int16_t)buffer[4] << 10)) &0x07ff) - 1024;
    data->channel_3 = (((int16_t)(buffer[4] >> 1) | ((int16_t)buffer[5] << 7)) & 0x07ff) - 1024;
    data->s1 = ((int16_t)(buffer[5] >> 4) & 0x0003);
    data->s2 = ((int16_t)(buffer[5] >> 4) & 0x000C) >> 2;
    data->mouse_x = buffer[6] | (buffer[7] << 8);
    data->mouse_y = buffer[8] | (buffer[9] << 8);
    data->mouse_z = buffer[10] | (buffer[11] << 8);

    data->mouse_left = buffer[12];
    data->mouse_right = buffer[13];
    data->button = buffer[14] | (buffer[15] << 8);

    if ((abs(data->channel_0) > 660) ||
        (abs(data->channel_1) > 660) ||
        (abs(data->channel_2) > 660) ||
        (abs(data->channel_3) > 660))
    {
        memset(data, 0, sizeof(Dr16_Receive_Data));
        return;
    }
}

void dma_init(void){
    HAL_UART_Receive_DMA(&dbus_huart, dr16_buffer, dbus_buf_len);
}


