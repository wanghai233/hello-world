#include "hard.h"


/*******************************/
void HardLED(uchar dat)
{
	P2=0x80;
	P0=dat;
}
/*******************************/
void HardOther(uchar dat)
{
	P2=0xa0;
	P0=dat;
}
/*******************************/