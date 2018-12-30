#include "digit.h"

uchar code tab[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xbf,0xff};

/*********************************************/
void Digit_H(uchar a,uchar b,uchar c,uchar d)
{
	P2=0xe0;
	P0=tab[a];
	P2=0xc0;
	P0=0x01;
	Delay1ms();
	
	P2=0xe0;
	P0=tab[b];
	P2=0xc0;
	P0=0x02;
	Delay1ms();
	
	P2=0xe0;
	P0=tab[c];
	P2=0xc0;
	P0=0x04;
	Delay1ms();	

	P2=0xe0;	
	P0=tab[d];
	P2=0xc0;
	P0=0x08;
	Delay1ms();			
}
/**********************************************/
void Digit_L(uchar a,uchar b,uchar c,uchar d)
{
	P2=0xe0;
	P0=tab[a];
	P2=0xc0;
	P0=0x10;
	Delay1ms();
	
	P2=0xe0;
	P0=tab[b];
	P2=0xc0;
	P0=0x20;
	Delay1ms();
	
	P2=0xe0;
	P0=tab[c];
	P2=0xc0;
	P0=0x40;
	Delay1ms();	

	P2=0xe0;	
	P0=tab[d];
	P2=0xc0;
	P0=0x80;
	Delay1ms();			
}
/**********************************************/
static void Delay1ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 11;
	j = 190;
	do
	{
		while (--j);
	} while (--i);
}











