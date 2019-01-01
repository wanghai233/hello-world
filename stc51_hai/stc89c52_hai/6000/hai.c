#include <reg52.h>
#include <stdlib.h>
#define uint unsigned long
#define uchar unsigned char 
sbit N1 = P1^0; 
sbit N2 = P1^1;
sbit N3 = P1^2;
sbit N4 = P1^3;
//sbit N5 = P1^4;
//sbit N6 = P1^5;
uchar code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90}; 

uint num;
int a,t1=0;

void delayms(uint xms)  //延时函数
{       
    uint i,j;
    for(i=xms;i>0;i--)
        for(j=10;j>0;j--);
}

void display(uint num)                        
{
        N1=0;       
        P0=table[(num/1000)]; 
        delayms(1);     
        P0=0XFF;        
        N1=1;       

        N2=0;       
        P0=table[(num%1000)/100];   
        delayms(1);     
        P0=0XFF;        
        N2=1;

        N3=0;       
        P0=table[(num%100)/10]; 
        delayms(1);     
        P0=0XFF;        
        N3=1;       

        N4=0;       
        P0=table[(num%10)];   
        delayms(1);     
        P0=0XFF;        
        N4=1;

//        N5=0;       
//        P0=table[(num%100)/10]; 
//        delayms(1);     
//        P0=0XFF;        
//        N5=1;       

//        N6=0;       
//        P0=table[num%10];   
//        delayms(1);     
//        P0=0XFF;        
//        N6=1;

        }

void TimeAdd() interrupt 1
{

        TH0=(65536-50000)/256;  
        TL0=(65536-50000)%256;
        t1++;

        if(t1==10)  //20*50==1秒10*50=0.5秒
        {
            t1=0;
            num++;
        }

}




void main()
{
    TMOD=0X01;  // 定时器  初始化
    TH0=(65536-50000)/256;  
    TL0=(65536-50000)%256;
    EA=1;       //中断总开关
    ET0=1;      //开定时器0 中断
    TR0=1;      //启动定时器0

    num=6000;     //初始值
    while(1)
    {                           
        display(num);
	}
}