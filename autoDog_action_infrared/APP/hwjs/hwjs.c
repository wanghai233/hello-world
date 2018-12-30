#include "hwjs.h"
#include "SysTick.h"
#include "tftlcd.h" 
#include "touch.h"
#include "font_show.h"
#include "gui.h"
#include "time.h"

u32 hw_jsm;	  //����һ��32λ���ݱ��������������
u8  hw_jsbz;  //����һ��8λ���ݵı���������ָʾ���ձ�־
extern void UnderarmPos();
extern void UpPos();
extern void initSys(void);
extern void delay(uint32_t ms);
extern __IO uint32_t TimingMillis;
/*******************************************************************************
* �� �� ��         : Hwjs_Init
* ��������		   : ����˿ڳ�ʼ������	  ʱ�Ӷ˿ڼ��ⲿ�жϳ�ʼ�� 
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void Hwjs_Init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	/* ����GPIOʱ�Ӽ��ܽŸ���ʱ�� */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG|RCC_APB2Periph_AFIO,ENABLE);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_15;//�������
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOG,&GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOG, GPIO_PinSource15); //ѡ��GPIO�ܽ������ⲿ�ж���·
	EXTI_ClearITPendingBit(EXTI_Line15);
	
	/* �����ⲿ�жϵ�ģʽ */ 
	EXTI_InitStructure.EXTI_Line=EXTI_Line15;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure); 

	/* ����NVIC���� */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;   //��ȫ���ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //��ռ���ȼ�Ϊ0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 	 //��Ӧ���ȼ�Ϊ1
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;   //ʹ��
	NVIC_Init(&NVIC_InitStructure);

}

void Hwjs_Init_close()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	/* ����GPIOʱ�Ӽ��ܽŸ���ʱ�� */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG|RCC_APB2Periph_AFIO,ENABLE);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_15;//�������
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOG,&GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOG, GPIO_PinSource15); //ѡ��GPIO�ܽ������ⲿ�ж���·
	EXTI_ClearITPendingBit(EXTI_Line15);
	
	/* �����ⲿ�жϵ�ģʽ */ 
	EXTI_InitStructure.EXTI_Line=EXTI_Line15;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure); 

	/* ����NVIC���� */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;   //��ȫ���ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //��ռ���ȼ�Ϊ0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 	 //��Ӧ���ȼ�Ϊ1
	NVIC_InitStructure.NVIC_IRQChannelCmd = DISABLE;   //ʹ��
	NVIC_Init(&NVIC_InitStructure);

}


/*******************************************************************************
* �� �� ��         : HW_jssj
* ��������		   : �ߵ�ƽ����ʱ�䣬����¼��ʱ�䱣����t�з��أ�����һ�δ�Լ20us 
* ��    ��         : ��
* ��    ��         : t
*******************************************************************************/

#include "system.h"
extern u32   uip_timer5;
//��ʱnus
//nusΪҪ��ʱ��us��.	

//void delay_ms_wh(u32 i)
//{
//    u32 temp;
//    SysTick->LOAD=9000*i;      
//    SysTick->CTRL=0X01;        
//    SysTick->VAL=0;          
//    do
//    {
//        temp=SysTick->CTRL;      
//    }
//    while((temp&0x01)&&(!(temp&(1<<16))));   
//    SysTick->CTRL=0;  
//    SysTick->VAL=0;     
//}
////void SysTick_wh(void)
////{
////	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);//ϵͳʱ�Ӱ˷�Ƶ
////	SysTick_SetReload(90000);														 //����10ms
////	
////}
//void delay_usnew(u32 nus)
//{		
//  uip_timer5=0;
//	while((uip_timer5)<nus);
//}

u8 HW_jssj()
{
	u8 t=0;
	int i=0;
	while(GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_15)==1)//�ߵ�ƽ
	{
		t++;
	
		delay_us(20);
		
		if(t>=250) return t;//��ʱ���
	}
	return t;
}


void EXTI15_10_IRQHandler(void)	  //����ң���ⲿ�ж�
{
	u8 Tim=0,Ok=0,Data,Num=0;
	 while(1)
   {
	   	if(GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_15)==1)
		{
			 Tim=HW_jssj();//��ô˴θߵ�ƽʱ��

			 if(Tim>=250) break;//�������õ��ź�

			 if(Tim>=200 && Tim<250)
			 {
			 	Ok=1;//�յ���ʼ�ź�
			 }
			 else if(Tim>=60 && Tim<90)
			 {
			 	Data=1;//�յ����� 1
			 }
			 else if(Tim>=10 && Tim<50)
			 {
			 	Data=0;//�յ����� 0
			 }

			 if(Ok==1)
			 {
			 	hw_jsm<<=1;
				hw_jsm+=Data;

				if(Num>=32)
				{
					hw_jsbz=1;
				  	break;
				}
			 }

			 Num++;
		}
   }
	
  EXTI_ClearITPendingBit(EXTI_Line15);	
 

   
}



#define ICON8_XS   ICON_XFRAM+3*ICON_XLEN+3*ICON_XSPACE
#define ICON8_YS   ICON_YFRAM+ICON_YSPACE+ICON_YLEN
#define ICON8_XE   ICON_XFRAM+4*ICON_XLEN+3*ICON_XSPACE
#define ICON8_YE   ICON_YFRAM+ICON_YSPACE+2*ICON_YLEN

//void LCD_DisplayWindows(void);
void IRED_Test(void)
{
	u8 dat[4],irdisp[9];
	u8 num[16]="0123456789ABCDEF";
	int i;
	//RTC_ITConfig(RTC_IT_SEC, DISABLE);//�ر�RTC���ж�
	
//	LCD_Clear(BLACK);
	Hwjs_Init();
//	FRONT_COLOR=YELLOW;
//	LCD_ShowFont12Char(10,10,"����ң�ز���");
//	LCD_ShowPicture(tftlcd_data.width-RETURN_X,tftlcd_data.height-RETURN_Y,RETURN_X,RETURN_Y,(u8 *)gImage_return);
//	LCD_ShowFont12Char(10,50,"����ң�ؼ��룺");
	
	while(1)
	{

		if(hw_jsbz==1)	//���������յ�
		{
			hw_jsbz=0;	   //����
			Hwjs_Init_close();
			if(hw_jsm==0x00ff6897)
			{
				//LCD_ShowFont12Char(131,50,"0");
				 	
				initSys();
				TimingMillis=0;
				//SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);   
				UnderarmPos();
				 SysTick_Init(72);
					SysTick->LOAD  = 72000 - 1; 

			}

			if(hw_jsm==0x00ff30cf)
			{


				initSys();
				TimingMillis=0;
				//SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);   

				UpPos();
				 SysTick_Init(72);
					SysTick->LOAD  = 72000 - 1; 

			}
			Hwjs_Init();
#if 0
			if(hw_jsm==0x00ffa25d)
			/*dat[0]=hw_jsm>>24;
			dat[1]=(hw_jsm>>16)&0xff;
			dat[2]=(hw_jsm>>8)&0xff;
			dat[3]=hw_jsm&0xff;
			hw_jsm=0;					//����������
			irdisp[0]=num[dat[0]/16];//��ʾ��λ
			irdisp[1]=num[dat[0]%16];//��ʾ��λ  
			irdisp[2]=num[dat[1]/16];
			irdisp[3]=num[dat[1]%16];	 //ͬһ��ң������2���ֽڵ������������ǲ���ı�ģ��ı��ֻ�������뼰����
			irdisp[4]=num[dat[2]/16];
			irdisp[5]=num[dat[2]%16];
			irdisp[6]=num[dat[3]/16];
			irdisp[7]=num[dat[3]%16];
			irdisp[8]='\0';*/
			LCD_ShowFont12Char(131,50,"power");
			if(hw_jsm==0x00ff629d)
				LCD_ShowFont12Char(131,50,"mode");
				if(hw_jsm==0x00fff21d)
				LCD_ShowFont12Char(131,50,"mute");
				if(hw_jsm==0x00ff02fd)
				LCD_ShowFont12Char(131,50,"begin");
				if(hw_jsm==0x00ffc23d)
				LCD_ShowFont12Char(131,50,"right");
				if(hw_jsm==0x00ffe01f)
				LCD_ShowFont12Char(131,50,"eq");
				if(hw_jsm==0x00ffa857)
				LCD_ShowFont12Char(131,50,"vol��");
				if(hw_jsm==0x00ff906f)
				LCD_ShowFont12Char(131,50,"vol+");
				if(hw_jsm==0x00ff9867)
				LCD_ShowFont12Char(131,50,"rpt");
				if(hw_jsm==0x00ffb04f)
				LCD_ShowFont12Char(131,50,"u/sd");
				LCD_ShowFont12Char(131,50,"2");
				if(hw_jsm==0x00ff7ac5)
				LCD_ShowFont12Char(131,50,"3");
				if(hw_jsm==0x00ff10ef)
				LCD_ShowFont12Char(131,50,"4");
				if(hw_jsm==0x00ff38c7)
				LCD_ShowFont12Char(131,50,"5");
				if(hw_jsm==0x00ff5aa5)
				LCD_ShowFont12Char(131,50,"6");
				if(hw_jsm==0x00ff42bd)
				LCD_ShowFont12Char(131,50,"7");
				if(hw_jsm==0x00ff4ab5)
				LCD_ShowFont12Char(131,50,"8");
				if(hw_jsm==0x00ff52ad)
				LCD_ShowFont12Char(131,50,"9");
#endif			
		}
		
	}
}
