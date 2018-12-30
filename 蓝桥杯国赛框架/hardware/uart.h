#ifndef __UART_H
#define __UART_H

#include "stc15f2k60s2.h"
#include<intrins.h>

#define uchar unsigned char
#define uint unsigned int

void UartInit(void);
void UartSend(uchar Dat);
void SendString(uchar *s);










#endif