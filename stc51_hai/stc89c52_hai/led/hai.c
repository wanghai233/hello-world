#include <reg52.h>
#include <intrins.h>    //������λ����
#define uint unsigned int   //�궨��
#define uchar unsigned char
sbit S1=P3^7;       //����S1����
void delay(uint);
uchar temp;

  void main()
  {     
        temp=0xfe;      //��ʼ��
        P2=temp;

      while(1)
      { 
        if(S1==0)   //�ж��Ƿ���
        { 
            delay(10);            
            if(S1==0)   //�ٴ��ж��Ƿ���
            {
                temp=_crol_(temp,1);//����
                delay(100); //��ʱ
                P2=temp;    //���¸�ֵ

                 while(!S1);    //����
                 delay(5);
                 while(!S1);
            }
        }     
      }
  }

 void delay(uint z)     //��ʱ����
 {
    uint x,y;
    for(x=200;x>0;x--)
    {
        for(y=z;y>0;y--);
    }


 }