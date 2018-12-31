#include"reg52.h"
#define uchar unsigned char
#define uint unsigned int

sbit led = P2^7;
sbit button = P3^7;

uint number = 0;

void timer() interrupt 0
{
	TH0 = (65536 - 15536)/256;
	TL0 = (65536 - 15536)%256;
	number++;
}

void init_timer()
{
	TMOD = 0x01;
	TH0 = (65536 - 15536)/256;
	TL0 = (65536 - 15536)%256;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}

void delay_1s()
{
	init_timer();
	if(number != 20);
}

void main()
{
	init();
	while(1)
	{
		delay_1s();
		led = ~led;
	}
}