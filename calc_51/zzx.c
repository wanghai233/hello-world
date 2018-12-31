#include<reg51.h>  
#include<math.h>
#define uint unsigned int  
#define uchar unsigned char

sbit lcden=P1^2; 
sbit rs=P1^0;
sbit rw=P1^1;

sbit LCD_RS=P1^0;//????
sbit LCD_RW=P1^1;
sbit LCD_E=P1^2;
void delay(uchar z) 
{
uchar y;
for(z;z>0;z--)
   for(y=0;y<110;y++);
}
#define LCD_Data P0
#define Busy    0x80 //????LCD?????Busy??

/********????*************************************************************/
unsigned char code uctech[] = {"lu yang"};
unsigned char code net[] = {"coder"};

/********????*************************************************************/
void WriteDataLCD(unsigned char WDLCD);					//???
void WriteCommandLCD(unsigned char WCLCD,BuysC);		//???
unsigned char ReadDataLCD(void);						//???
unsigned char ReadStatusLCD(void);						//???
void LCDInit(void);										//???
void DisplayOneChar(unsigned char X, unsigned char Y, unsigned char DData);			//??????????
void DisplayListChar(unsigned char X, unsigned char Y, unsigned char code *DData);	//????????????
void Delay5Ms(void);									//??
void Delay400Ms(void);									//??


/***********?????********************************************************/	


/***********???********************************************************/	
void WriteDataLCD(unsigned char WDLCD)
{
 	ReadStatusLCD(); //???
 	LCD_Data = WDLCD;
 	LCD_RS = 1;
 	LCD_RW = 0;
 	LCD_E = 0; 		//?????????????????
 	LCD_E = 0; 		//??
 	LCD_E = 1;
}

/***********???********************************************************/	
void WriteCommandLCD(unsigned char WCLCD,BuysC) //BuysC?0??????
{
 	if (BuysC) ReadStatusLCD(); //???????
 	LCD_Data = WCLCD;
 	LCD_RS = 0;
 	LCD_RW = 0; 
 	LCD_E = 0;
 	LCD_E = 0;
	LCD_E = 1; 
}

/***********???********************************************************/	
unsigned char ReadDataLCD(void)
{
 	LCD_RS = 1; 
 	LCD_RW = 1;
 	LCD_E = 0;
 	LCD_E = 0;
 	LCD_E = 1;
 	return(LCD_Data);
}

/***********???*******************************************************/	
unsigned char ReadStatusLCD(void)
{
 	LCD_Data = 0xFF; 
 	LCD_RS = 0;
 	LCD_RW = 1;
 	LCD_E = 0;
 	LCD_E = 0;
 	LCD_E = 1;
 	while (LCD_Data & Busy); //?????
 	return(LCD_Data);
}

/***********???********************************************************/	

void DisplayOneChar(unsigned char X, unsigned char Y, unsigned char DData)
{
 	Y &= 0x1;
 	X &= 0xF; 				//??X????15,Y????1
 	if (Y) X |= 0x40; 		//???????????+0x40;
 	X |= 0x80; 			//?????
 	WriteCommandLCD(X, 0); //????????,?????
 	WriteDataLCD(DData);
}

/***********???????????*****************************************/	
void DisplayListChar(unsigned char X, unsigned char Y, unsigned char code *DData)
{
 	unsigned char ListLength;

 	ListLength = 0;
 	Y &= 0x1;
 	X &= 0xF; 				//??X????15,Y????1
 	while (DData[ListLength]>=0x20){ //?????????
   		if (X <= 0xF){ 		//X?????0xF
     		DisplayOneChar(X, Y, DData[ListLength]); //??????
     		ListLength++;
     		X++;
    	}
  	}
}

/***********???********************************************************/	
void Delay5Ms(void)
{
 	unsigned int TempCyc = 5552;
 	while(TempCyc--);
}

/***********???********************************************************/	
void Delay400Ms(void)
{
 	unsigned char TempCycA = 5;
 	unsigned int TempCycB;
 	while(TempCycA--){
  		TempCycB=7269;
  		while(TempCycB--);
 	}
}


uchar code table[]={0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,
0x38,0x39,0x2B,0x2D,0x2A,0x2f,0x3D,"A"};

uchar code table_data[]={0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39};


long a,b,c;
uint temp_data;

void write_com(uchar com) // 写指令
{  
  rs=0;
	rw=0;
	P0=com; 
	delay(5);
	lcden=0;
	delay(5);
  lcden=1;
}

void write_date(uchar date) // 写数据
{   
  rs=1;
	rw=0;
	P0=date;
	delay(5);
  lcden=0;
  delay(5);
  lcden=1;
}
uchar flag,fuhao;

uchar k1()
{
 uchar temp;
	int num;
 P2=0xfe;
 temp=P2;
 temp=temp&0xf0;
 while(temp!=0xf0)
 {
   delay(5);
    temp=P2;
	temp=temp&0xf0;
	while(temp!=0xf0)
	{
	 temp=P2;
	 switch(temp)
	 {
	  case 0xee: num=1;
	           break;
	  case 0xde: num=2;
	           break;
	  case 0xbe: num=3;
	           break;
	  case 0x7e: num=10;
	           break;
	 }
	 write_date(table[num]);
	  if(num==1||num==2||num==3)
 {
    if(flag==0)
		{
		  a=a*10+num;
		}
		else if(flag==1)
		{
		  b=b*10+num;
		}
 }
 else
    {			
        flag=1;			
			  fuhao=1;	
    }
	while(temp!=0xf0)
	{
	  temp=P2;
      temp=temp&0xf0;
	 }
   }
  }


  P2=0xfd;
 temp=P2;
 temp=temp&0xf0;
 while(temp!=0xf0)
 {
   delay(5);
    temp=P2;
	temp=temp&0xf0;
	while(temp!=0xf0)
	{
	 temp=P2;
	 switch(temp)
	 {
	  case 0xed: num=4;
	           break;
	  case 0xdd: num=5;
	           break;
	  case 0xbd: num=6;
	           break;
	  case 0x7d: num=11;
	           break;
	 }
	 write_date(table[num]);
	  if(num==4||num==5||num==6)
 {
    if(flag==0)
		{
		  a=a*10+num;
		}
		else if(flag==1)
		{
		  b=b*10+num;
		}
 }
 else
    {
        flag=1;
			  fuhao=2;			
    }
	while(temp!=0xf0)
	{
	  temp=P2;
      temp=temp&0xf0;
	 }
   }
 }

 P2=0xfb;
 temp=P2;
 temp=temp&0xf0;
 while(temp!=0xf0)
 {
   delay(5);
    temp=P2;
	temp=temp&0xf0;
	while(temp!=0xf0)
	{
	 temp=P2;
	 switch(temp)
	 {
	  case 0xeb: num=7;
	           break;
	  case 0xdb: num=8;
	           break;
	  case 0xbb: num=9;
	           break;
	  case 0x7b: num=12;
	           break;
	 }
	 write_date(table[num]);
	 if(num==7||num==8||num==9)
 {
    if(flag==0)
		{
		  a=a*10+num;
		}
		else if(flag==1)
		{
		  b=b*10+num;
		}
 }
 else
    {
        flag=1;   
			  fuhao=3;
    }
	while(temp!=0xf0)
	{
	  temp=P2;
      temp=temp&0xf0;
	 }
   }
 }
 
 P2=0xf7;
 temp=P2;
 temp=temp&0xf0;
 while(temp!=0xf0)
 {
   delay(5);
    temp=P2;
	temp=temp&0xf0;
	while(temp!=0xf0)
	{
	 temp=P2;
	 switch(temp)
	 {
	  case 0xe7: num=15;
	           break;
	  case 0xd7: num=0;
	           break;
	  case 0xb7: num=14;
	           break;
	  case 0x77: num=13;
	           break;
	 }
	 write_date(table[num]);
	 if(num==0)
 {
     if(flag==0)
		{
		  a=a*10+num;
		}
		else if(flag==1)
		{
		  b=b*10+num;
		}
 }
 else if(num==13)
    {
        flag=1;
			  fuhao=4;
    }
 else if(num==15)
    {
     write_com(0x01);
			a=0;
			b=0;
			flag=0;
			fuhao=0;
    }
else if(num==14)
    {
     if(fuhao==1)
			 { 					 
           c=a+b; //此时c值无问题
				 if(c<10){
					 write_date(table[c]);
           delay(5);
				 }
         else	if(c>99){	       				 
					 temp_data = c/100;
           write_date(table_data[temp_data]);
					 delay(5);
				   temp_data = c/10%10;
				   write_date(table_data[temp_data]);
					 delay(5);
				   temp_data = c%10;
				   write_date(table_data[temp_data]);
           delay(5);
				 }
         else if(9<c<100){	
					 temp_data = c/10%10;
				   write_date(table_data[temp_data]);
					 delay(5);
				   temp_data = c%10;
				   write_date(table_data[temp_data]);
           delay(5);
				 }				 
       }
			else if(fuhao==2)
			 {				               					 
           c=a-b;
            if(c<10){
					 write_date(table[c]);
           delay(5);
				 }
         else	if(c>99){	       				 
					 temp_data = c/100;
           write_date(table_data[temp_data]);
					 delay(5);
				   temp_data = c/10%10;
				   write_date(table_data[temp_data]);
					 delay(5);
				   temp_data = c%10;
				   write_date(table_data[temp_data]);
           delay(5);
				 }
         else if(9<c<100){	
					 temp_data = c/10%10;
				   write_date(table_data[temp_data]);
					 delay(5);
				   temp_data = c%10;
				   write_date(table_data[temp_data]);
           delay(5);
				 }				 		 					 
       }
			 else if(fuhao==3)
			 {				   
           c=a*b;
           if(c<10){
					 write_date(table[c]);
           delay(5);
				 }
         else	if(c>99){	       				 
					 temp_data = c/100;
           write_date(table_data[temp_data]);
					 delay(5);
				   temp_data = c/10%10;
				   write_date(table_data[temp_data]);
					 delay(5);
				   temp_data = c%10;
				   write_date(table_data[temp_data]);
           delay(5);
				 }
         else if(9<c<100){	
					 temp_data = c/10%10;
				   write_date(table_data[temp_data]);
					 delay(5);
				   temp_data = c%10;
				   write_date(table_data[temp_data]);
           delay(5);
				 }				 			 					 
       }
			 else if(fuhao==4)
			 {				   					 
           c=a/b;
            if(c<10){
					 write_date(table[c]);
           delay(5);
				 }
         else	if(c>99){	       				 
					 temp_data = c/100;
           write_date(table_data[temp_data]);
					 delay(5);
				   temp_data = c/10%10;
				   write_date(table_data[temp_data]);
					 delay(5);
				   temp_data = c%10;
				   write_date(table_data[temp_data]);
           delay(5);
				 }
         else if(9<c<100){	
					 temp_data = c/10%10;
				   write_date(table_data[temp_data]);
					 delay(5);
				   temp_data = c%10;
				   write_date(table_data[temp_data]);
           delay(5);
				 }				 		 				 
       }
			
    }
	while(temp!=0xf0)
	{
	  temp=P2;
      temp=temp&0xf0;
	 }
   }
 }
 
  return num;
}

void init() 
{    
lcden=0; 
write_com(0x38); //1602开显示
write_com(0x0f); //打开光标
write_com(0x06); //每当写一个字符，光标加一
write_com(0x01); //清屏
write_com(0x80); //光标定位到第一行
a=0;
b=0;
c=0;
flag=0;
fuhao=0;
temp_data = 0;
}

main()
{
init();
while(1)
{
 k1();
}
}

