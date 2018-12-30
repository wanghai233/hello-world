#ifndef __ADC_H
#define __ADC_H

#include "stc15f2k60s2.h"
#include "iic.h"

#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long

uchar ADConver(void);
void DACConver(uchar dat);



#endif