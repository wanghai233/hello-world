#ifndef __AT24Cxx_H
#define __AT24Cxx_H

#include "stc15f2k60s2.h"
#include "iic.h"

#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long

void EEPWriteData(uchar Addr,uchar Dat);
uchar EEPReadData(uchar Addr);
static void Delay5ms();




#endif