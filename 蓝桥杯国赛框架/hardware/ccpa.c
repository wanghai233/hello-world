#include "ccpa.h"

#define FOSC    11059200L
#define T100Hz  (FOSC / 12 / 100)
typedef unsigned char BYTE;
typedef unsigned int WORD;
#define CCP_S0 0x10                 //P_SW1.4
#define CCP_S1 0x20                 //P_SW1.5
uint Fre;
BYTE cnt;
WORD value;
/************************************/
void CCPAInit(void)
{
	ACC = P_SW1;
    ACC &= ~(CCP_S0 | CCP_S1);      //CCP_S0=0 CCP_S1=0
    P_SW1 = ACC;                    //
    CCON = 0;                       //初始化PCA控制寄存器
    CL = 0;                         //复位PCA寄存器
    CH = 0;
    CMOD = 0x00;                    //设置PCA时钟源
                                    //禁止PCA定时器溢出中断
    value = T100Hz;
    CCAP0L = value;
    CCAP0H = value >> 8;            //初始化PCA模块0
    value += T100Hz;
    CCAPM0 = 0x49;                  //PCA模块0为16位定时器模式
    CR = 1;                         //PCA定时器开始工作
    EA = 1;
    cnt = 0;
}
/***********************************/
void Timer0Exint(void)
{
	AUXR = 0x80;                    //定时器0为1T模式
    TMOD = 0x04;                    //设置定时器0为16位自动重装载外部记数模式
    TH0 = TL0 = 0xff;               //设置定时器0初始值
    TR0 = 1;                        //定时器0开始工作
    ET0 = 1;                        //开定时器0中断
    EA = 1;
}
/************************************/
void PCA_isr() interrupt 7 using 1
{
    CCF0 = 0;                       //清中断标志
    CCAP0L = value;
    CCAP0H = value >> 8;            //更新比较值
    value += T100Hz;
    if (cnt-- == 0)
    {
        cnt = 25;                  //记数100次
		FreCheck=Fre;
		FreCheck=FreCheck<<2;
		Fre=0;
    }
}
/*************************************/
void t0int() interrupt 1            //中断入口
{
	Fre++;
}