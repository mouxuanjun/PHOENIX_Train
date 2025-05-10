#ifndef __DR16_H__
#define __DR16_H__

#include "main.h"
#include "usart.h"

typedef struct
{
   struct
   {
       unsigned short ch0;  
       unsigned short ch1; 
	   unsigned short ch2; 
	   unsigned short ch3;
       unsigned char s1;
       unsigned char s2;	   
   }rc;
   
   struct
   {
       unsigned short x;
	   unsigned short y;
	   unsigned short z;
	   unsigned char press_1;
	   unsigned char press_r;
   }mouse;
   
   struct
   {
       unsigned short v;
   }key;
   
}RC_Ctl_t;

#endif
