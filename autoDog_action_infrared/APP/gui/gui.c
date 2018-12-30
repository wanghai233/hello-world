#include "gui.h"
#include "tftlcd.h"
#include "ascii.h" 

#ifdef ICON_SIZE_58X58
u8 ICON_XLEN = 58;
u8 ICON_YLEN = 58;
u8 ICON_SIZE = 58;

u8 ICON_XFRAM = 10;
u8 ICON_YFRAM = 25;
u8 ICON_XSPACE = 10;
u8 ICON_YSPACE = 30;
#endif

#ifdef ICON_SIZE_48X48
u8 ICON_XLEN = 48;
u8 ICON_YLEN = 48;
u8 ICON_SIZE = 48;

u8 ICON_XFRAM = 10;
u8 ICON_YFRAM = 25;
u8 ICON_XSPACE = 10;
u8 ICON_YSPACE = 30;
#endif

#ifdef ICON_SIZE_38X38
u8 ICON_XLEN = 38;
u8 ICON_YLEN = 38;
u8 ICON_SIZE = 38;

u8 ICON_XFRAM = 10;
u8 ICON_YFRAM = 25;
u8 ICON_XSPACE = 23;
u8 ICON_YSPACE = 25;
#endif





void LCD_ShowCharTrans(u16 x,u16 y,u8 num,u8 size,u8 mode)
{  							  
    u8 temp,t1,t;
	u16 y0=y;
	u8 csize=(size/8+((size%8)?1:0))*(size/2);		//�õ�����һ���ַ���Ӧ������ռ���ֽ���	
 	num=num-' ';//�õ�ƫ�ƺ��ֵ��ASCII�ֿ��Ǵӿո�ʼȡģ������-' '���Ƕ�Ӧ�ַ����ֿ⣩
	for(t=0;t<csize;t++)
	{   
		if(size==12)temp=asc_1206[num][t]; 	 	//����1206����
		else if(size==16)temp=asc_1608[num][t];	//����1608����
		else if(size==24)temp=asc_2412[num][t];	//����2412����
		else return;								//û�е��ֿ�
		for(t1=0;t1<8;t1++)
		{			    
			if(temp&0x80)LCD_DrawFRONT_COLOR(x,y,WHITE);
			else if(mode==0)LCD_DrawFRONT_COLOR(x,y,BACK_COLOR);
			temp<<=1;
			y++;
			if(y>=tftlcd_data.height)return;		//��������
			if((y-y0)==size)
			{
				y=y0;
				x++;
				if(x>=tftlcd_data.width)return;	//��������
				break;
			}
		}  	 
	}  	    	   	 	  
}

void LCD_ShowStringTrans(u16 x,u16 y,u16 width,u16 height,u8 size,u8 *p)
{         
	u8 x0=x;
	width+=x;
	height+=y;
    while((*p<='~')&&(*p>=' '))//�ж��ǲ��ǷǷ��ַ�!
    {       
        if(x>=width){x=x0;y+=size;}
        if(y>=height)break;//�˳�
        LCD_ShowCharTrans(x,y,*p,size,1);
        x+=size/2;
        p++;
    }  
}



const unsigned char gImage_return[2400] = { /* 0X00,0X10,0X28,0X00,0X1E,0X00,0X01,0X1B, */
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X24,0XDE,0X24,
0XBE,0X1C,0XBE,0X14,0XBE,0X14,0XBE,0X14,0XBE,0X1C,0XDE,0X24,0XFF,0X24,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XDE,0X24,
0XDE,0X24,0XDF,0X24,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X24,0XDE,0X24,0XBF,0X5D,
0XDF,0XB6,0XFF,0XB6,0XFF,0XB6,0XFF,0XB6,0XFF,0XB6,0X7F,0X4D,0XDE,0X24,0XFF,0X24,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XDE,0X24,0X9E,0X14,0X3E,0X3D,
0X7F,0X55,0XDE,0X24,0XDF,0X24,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XDE,0X1C,0X9F,0XA6,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X1F,0X86,0XDE,0X24,0XDF,0X24,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XDE,0X24,0XDE,0X24,0XBE,0X14,0X3F,0X45,0X1F,0XC7,0XFF,0XFF,
0XFF,0XFF,0XBF,0X65,0XDE,0X24,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XDE,0X1C,0X9F,0X9E,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X1F,0X7E,0XDE,0X24,0XDF,0X24,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XDE,0X24,0XBE,0X1C,0X1F,0X35,0X9F,0X9E,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XDF,0X65,0XBE,0X1C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XDE,0X1C,0X9F,0X9E,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X1F,0X7E,0XDE,0X24,0XDF,0X24,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XDE,0X24,
0XBE,0X1C,0XDE,0X24,0X7F,0X96,0XDF,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XDF,0X65,0XBE,0X1C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XDE,0X1C,0X9F,0X9E,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X1F,0X7E,0XDE,0X24,0XDF,0X24,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XBE,0X1C,0XFF,0X2C,
0XFF,0X75,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XDF,0X65,0XBE,0X1C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XDE,0X1C,0X9F,0X9E,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X1F,0X7E,0XDE,0X24,0XDF,0X24,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XBE,0X1C,0X9E,0X14,0XBF,0X5D,0X5F,0XD7,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XDF,0X65,0XBE,0X1C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XDE,0X1C,0X9F,0X9E,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X1F,0X7E,0XDE,0X24,0XDF,0X24,
0XFF,0X24,0XDE,0X24,0XDE,0X24,0X9E,0X14,0XBF,0X65,0X7F,0XDF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XDF,0X65,0XBE,0X1C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XDE,0X1C,0X9F,0X9E,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X1F,0X7E,0XDE,0X24,0XDF,0X24,
0XDE,0X24,0XBE,0X1C,0X3F,0X3D,0XFF,0XB6,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XDF,0X65,0XBE,0X1C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XDE,0X1C,0X9F,0X9E,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X1F,0X7E,0XDE,0X24,0XBE,0X1C,
0X1F,0X35,0XBF,0XA6,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XDF,0X65,0XBE,0X1C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XDE,0X1C,0X9F,0X9E,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X1F,0X7E,0XBE,0X1C,0X7F,0X9E,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XDF,0X65,0XBE,0X1C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XDE,0X1C,0X9F,0X9E,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X75,0X1F,0X7E,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XDF,0X65,0XBE,0X1C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XDE,0X1C,0X9F,0X9E,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X75,0X7F,0X4D,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XDF,0X65,0XBE,0X1C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XDE,0X1C,0X9F,0X9E,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X1F,0X7E,0XBE,0X14,0X7F,0X4D,
0X1F,0XC7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XDF,0X65,0XBE,0X1C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XDE,0X1C,0X9F,0X9E,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X1F,0X7E,0XDE,0X24,0XDE,0X24,
0XBE,0X1C,0X9F,0X55,0X3F,0XCF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XDF,0X65,0XBE,0X1C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XDE,0X1C,0X9F,0X9E,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X1F,0X7E,0XDE,0X24,0XDF,0X24,
0XDF,0X24,0XDE,0X1C,0XBE,0X1C,0X9F,0X5D,0X9F,0XE7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XDF,0X65,0XBE,0X1C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XDE,0X1C,0X9F,0X9E,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X1F,0X7E,0XDE,0X24,0XDF,0X24,
0XFF,0X2C,0XDF,0X24,0XDE,0X24,0XBE,0X1C,0XDE,0X24,0X3F,0X86,0XDF,0XF7,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XDF,0X65,0XBE,0X1C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XDE,0X1C,0X9F,0X9E,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X1F,0X7E,0XDE,0X24,0XDF,0X24,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDE,0X24,0XBE,0X1C,0XDE,0X24,0X3F,0X86,
0XBF,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XDF,0X65,0XBE,0X1C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XDE,0X1C,0X9F,0X9E,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X1F,0X7E,0XDE,0X24,0XDF,0X24,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDE,0X24,0XBE,0X1C,
0X1E,0X35,0XDF,0XAE,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XDF,0X65,0XBE,0X1C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XDE,0X1C,0X9F,0X9E,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X1F,0X7E,0XDE,0X24,0XDF,0X24,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,
0XDE,0X24,0XBE,0X1C,0X3F,0X45,0XFF,0XB6,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XDF,0X65,0XBE,0X1C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XDE,0X1C,0X9F,0X9E,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X1F,0X7E,0XDE,0X24,0XDF,0X24,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XDF,0X24,0XDE,0X24,0XBE,0X1C,0X5F,0X4D,0X3F,0XC7,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XDF,0X6D,0XBE,0X1C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XBE,0X1C,0X7F,0X96,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X1F,0X7E,0XDE,0X24,0XDF,0X24,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XDE,0X24,0XDE,0X24,0XBE,0X1C,0XDF,0X6D,0XBF,0XEF,
0XFF,0XFF,0X7F,0X55,0XDE,0X24,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XBE,0X1C,
0X9E,0X0C,0X7E,0X0C,0X7E,0X0C,0X7E,0X0C,0X7E,0X0C,0XBE,0X1C,0XDF,0X24,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XDF,0X24,0XBE,0X1C,0X9E,0X14,
0X9E,0X14,0XDE,0X24,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,0XFF,0X2C,
};
