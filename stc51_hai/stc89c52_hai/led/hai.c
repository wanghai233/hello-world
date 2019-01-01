#include <reg52.h>
#include <intrins.h>    //包含移位函数
#define uint unsigned int   //宏定义
#define uchar unsigned char
sbit S1=P3^7;       //定义S1变量
void delay(uint);
uchar temp;

  void main()
  {     
        temp=0xfe;      //初始化
        P2=temp;

      while(1)
      { 
        if(S1==0)   //判断是否按下
        { 
            delay(10);            
            if(S1==0)   //再次判断是否按下
            {
                temp=_crol_(temp,1);//右移
                delay(100); //延时
                P2=temp;    //重新赋值

                 while(!S1);    //消抖
                 delay(5);
                 while(!S1);
            }
        }     
      }
  }

 void delay(uint z)     //延时程序
 {
    uint x,y;
    for(x=200;x>0;x--)
    {
        for(y=z;y>0;y--);
    }


 }