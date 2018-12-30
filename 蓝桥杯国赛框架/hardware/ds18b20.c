#include "ds18b20.h"



uint ReadTemp(void)
{
	uint temp;
	uint temp_H,temp_L;	

	Init_DS18B20();
	Write_DS18B20(0xcc); //����
	Write_DS18B20(0x44);  //����
	Delay_OneWire(200);

	Init_DS18B20();
	Write_DS18B20(0xcc);
	Write_DS18B20(0xbe);  //��ȡ

	temp_L=Read_DS18B20();
	temp_H=Read_DS18B20();
	temp=temp_H;
	temp=temp<<8;
	temp=temp|temp_L;
	temp=temp>>4;  //ȡ12λ

	return temp;	
}