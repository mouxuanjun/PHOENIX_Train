#include "main.h"


typedef struct {
    int16_t speed;
    uint16_t angle;
    uint8_t temperature;
    int16_t current;
}Motor6020;

extern Motor6020 motor6020;


void can_init(void);
