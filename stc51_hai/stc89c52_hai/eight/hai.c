#include <reg52.h>
#include <stdlib.h>
#define uint unsigned long            
#define uchar unsigned char

sbit N1 = P1^0;
sbit N2 = P1^1; 
sbit N3 = P1^2; 
sbit N4 = P1^3; 
 
sbit S1 = P3^7; 

uchar code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90}; //0~916���ƹ��������� 
uint num;
void delayms(uint xms) //��ʱ���� 
{
    uint i,j;
    for(i=xms;i>0;i--)
       for(j=10;j>0;j--); 
} 
void display(unsigned long num) 
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

//      N5=0;
//      P0=table[(num%10000)/1000]; 
//      delayms(1);
//      P0=0XFF;
//      N5=1;

//      N6=0; 
//      P0=table[(num%1000)/100]; 
//      delayms(1);
//      P0=0XFF;
//      N6=1;

//      N7=0;
//      P0=table[(num%100)/10];
//      delayms(1);
//      P0=0XFF; 
//      N7=1;
// 
//      N8=0;
//      P0=table[num%10];
//      delayms(1);
//      P0=0XFF;
//      N8=1;

      }


void main()
 {
   TMOD=0x01; //����T0��ʽ����M1��0��M0��1���Ƿ�ʽһ�Ķ�ʱ��
   EA=1; //�ⲿ�ж��ܿ��� 
   EX0=1; //  �����ⲿ�ж�0�����жϡ�


   num=1234;//  ��ʼ��


      while(1) 
         { 
            while(1) 
                { 
                   display(num); 

                       if(S1==0) //�ж��Ƿ��� 
                       { 
                          delayms(50);
                          if(S1==0) //�ٴ�ȷ�� 
                          {
                             num++;
                          } 
                          while(!S1);//���� 
                          delayms(50); 
                          while(!S1); 
                          break; //�������ڵĵ�һ��whileѭ�� 
                          }
                  } 
           } 
}
