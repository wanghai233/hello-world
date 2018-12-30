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
    CCON = 0;                       //��ʼ��PCA���ƼĴ���
    CL = 0;                         //��λPCA�Ĵ���
    CH = 0;
    CMOD = 0x00;                    //����PCAʱ��Դ
                                    //��ֹPCA��ʱ������ж�
    value = T100Hz;
    CCAP0L = value;
    CCAP0H = value >> 8;            //��ʼ��PCAģ��0
    value += T100Hz;
    CCAPM0 = 0x49;                  //PCAģ��0Ϊ16λ��ʱ��ģʽ
    CR = 1;                         //PCA��ʱ����ʼ����
    EA = 1;
    cnt = 0;
}
/***********************************/
void Timer0Exint(void)
{
	AUXR = 0x80;                    //��ʱ��0Ϊ1Tģʽ
    TMOD = 0x04;                    //���ö�ʱ��0Ϊ16λ�Զ���װ���ⲿ����ģʽ
    TH0 = TL0 = 0xff;               //���ö�ʱ��0��ʼֵ
    TR0 = 1;                        //��ʱ��0��ʼ����
    ET0 = 1;                        //����ʱ��0�ж�
    EA = 1;
}
/************************************/
void PCA_isr() interrupt 7 using 1
{
    CCF0 = 0;                       //���жϱ�־
    CCAP0L = value;
    CCAP0H = value >> 8;            //���±Ƚ�ֵ
    value += T100Hz;
    if (cnt-- == 0)
    {
        cnt = 25;                  //����100��
		FreCheck=Fre;
		FreCheck=FreCheck<<2;
		Fre=0;
    }
}
/*************************************/
void t0int() interrupt 1            //�ж����
{
	Fre++;
}