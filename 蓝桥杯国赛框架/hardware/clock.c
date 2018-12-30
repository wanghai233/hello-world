#include "clock.h"

uchar clockbuf[3]={0x50,0x59,0x23,};

/************************************/
void DS1302Init(void)
{
	Ds1302_Single_Byte_Write(0x8e,0x00);
	Ds1302_Single_Byte_Write(0x80,clockbuf[0]);
	Ds1302_Single_Byte_Write(0x82,clockbuf[1]);
	Ds1302_Single_Byte_Write(0x84,clockbuf[2]);
	Ds1302_Single_Byte_Write(0x8e,0x80);
}
/************************************/
void DS1302ReadTimes(void)
{
	clockbuf[0]=Ds1302_Single_Byte_Read(0x81);
	clockbuf[1]=Ds1302_Single_Byte_Read(0x83);
	clockbuf[2]=Ds1302_Single_Byte_Read(0x85);
}
/*************************************/