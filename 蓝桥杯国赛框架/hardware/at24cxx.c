#include "at24cxx.h"



/*****************************************/
void EEPWriteData(uchar Addr,uchar Dat)
{
	IIC_Start();
	IIC_SendByte(0xa0);
	IIC_WaitAck();
	IIC_SendByte(Addr);
	IIC_WaitAck();
	IIC_SendByte(Dat);
	IIC_WaitAck();
	IIC_Stop();
	Delay5ms();
}
/*****************************************/
uchar EEPReadData(uchar Addr)
{
	uchar Dat;
	IIC_Start();
	IIC_SendByte(0xa0);
	IIC_WaitAck();
	IIC_SendByte(Addr);
	IIC_WaitAck();
	IIC_Start();
	IIC_SendByte(0xa1);
	IIC_WaitAck();
	Dat=IIC_RecByte();
	IIC_Ack(1);
	IIC_Stop();
	return Dat;
}
/****************************************/
static void Delay5ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 54;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}
/**************************************/




















