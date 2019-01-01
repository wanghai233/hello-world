#include<reg51.h>					  //头文件
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
sbit P10=P1^0;						  //端口定义
sbit P11=P1^1;
uchar code DSY_CODE[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xff};
//延时
void DelayMS(uint x)
{
	uchar t;
	while(x--)for(t=0;t<120;t++);
}
//主程序
void main()
{
	uchar i=0;
	uchar j;
	P0=0x00;
	while(1)
	{
		i = i+1;
		if (i>99)
		i = 0;
		for(j=0;j<50;j++)
	{		
	P10=0;
	P11=1;
	P0 = DSY_CODE[i/10];	   //下载到单片机不需要取反符号
	DelayMS(5);

	P10=1;
	P11=0;
	P0 = DSY_CODE[i%10];
	DelayMS(5);
	
	
	}
  }
}
