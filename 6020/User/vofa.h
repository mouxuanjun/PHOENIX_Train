#ifndef __VOFA_H__
#define __VOFA_H__

#include "main.h"
#include <stdio.h>

int fputc(int ch, FILE *f);
void VOFA_Tx(void);
void vofaTask(void const * argument);

#endif
