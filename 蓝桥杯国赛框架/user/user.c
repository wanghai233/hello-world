#include "other.h"
#include "hard.h"
#include "digit.h"
#include "key.h"
#include "clock.h"
#include "ds18b20.h"
#include "at24cxx.h"
#include "adc.h"
#include "sonic.h"
#include "ccpa.h"
#include "uart.h"

/*****************************************/


/******************************************/
void main()
{
	uchar i;
	HardOther(0x00);
	HardLED(0xff);
	CCPAInit();
	Timer0Exint();
	while(1)
	{
		i++;
		if(i==200)
		{
			i=0;
			
		}
		Digit_H(FreCheck/100,FreCheck%100/10,FreCheck%10,10);
//		Digit_L(clockbuf[1]%16,10,clockbuf[0]/16,clockbuf[0]%16);
	}
}

/*******************************************/

