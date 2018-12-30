#include "adc.h"


/*****************************************/
uchar ADConver(void)
{
	uchar adc;
	IIC_Start();
	IIC_SendByte(0x90);  //�豸��ַ
	IIC_WaitAck();
	IIC_SendByte(0x03);  //ͨ��
	IIC_WaitAck();
	IIC_Stop();
	
	IIC_Start();
	IIC_SendByte(0x91);
	IIC_WaitAck();
	adc=IIC_RecByte();
	IIC_Ack(1);
	IIC_Stop();
	return adc;
}
/****************************************/
void DACConver(uchar dat)
{
	IIC_Start();
	IIC_SendByte(0x90);  //�豸��ַ
	IIC_WaitAck();
	IIC_SendByte(0x40);  //ͨ��
	IIC_WaitAck();
	IIC_SendByte(dat);
	IIC_WaitAck();
}
/****************************************/




















