#ifndef __CLOCK_H
#define __CLOCK_H

#include "stc15f2k60s2.h"
#include "ds1302.h"

#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long

extern uchar clockbuf[3];

void DS1302Init(void);
void DS1302ReadTimes(void);







#endif