

#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "tftlcd.h"
#include "key.h"
#include "sram.h"
#include "malloc.h" 
#include "sd.h"
#include "flash.h"
#include "ff.h" 
#include "fatfs_app.h"
#include "font_show.h"
#include "touch.h"
#include "gui.h"
#include "rtc.h"
#include "beep.h"
#include "adc.h"
#include "dac.h"
#include "ds18b20.h"
#include "24cxx.h"
#include "hwjs.h"
#include "sram.h"
#include "adxl345.h"
#include "rs485.h"
#include "can.h"
#include "smg.h"
#include "enc28j60.h"
#include "time.h"


#include "icon_background.h"
#include "icon_led.h"
#include "icon_beep.h"
#include "icon_key.h"
#include "icon_adc.h"
#include "icon_smg.h"
#include "icon_dac.h"
#include "icon_ds18b20.h"
#include "icon_eeprom.h"
#include "icon_ired.h"
#include "icon_flash.h"
#include "icon_sram.h"
#include "icon_adx345.h"
#include "icon_sd.h"
#include "icon_rs232.h"
#include "icon_rs485.h"
#include "icon_can.h"
#include "icon_internet.h"
#include "icon_map.h"
#include "icon_phone.h"
#include "icon_message.h"



#define ICON1_XS   ICON_XFRAM
#define ICON1_YS   ICON_YFRAM
#define ICON1_XE   ICON_XFRAM+ICON_XLEN
#define ICON1_YE   ICON_YFRAM+ICON_YLEN

#define ICON2_XS   ICON_XFRAM+ICON_XLEN+ICON_XSPACE
#define ICON2_YS   ICON_YFRAM
#define ICON2_XE   ICON_XFRAM+2*ICON_XLEN+ICON_XSPACE
#define ICON2_YE   ICON_YFRAM+ICON_YLEN

#define ICON3_XS   ICON_XFRAM+2*ICON_XLEN+2*ICON_XSPACE
#define ICON3_YS   ICON_YFRAM
#define ICON3_XE   ICON_XFRAM+3*ICON_XLEN+2*ICON_XSPACE
#define ICON3_YE   ICON_YFRAM+ICON_YLEN

#define ICON4_XS   ICON_XFRAM+3*ICON_XLEN+3*ICON_XSPACE
#define ICON4_YS   ICON_YFRAM
#define ICON4_XE   ICON_XFRAM+4*ICON_XLEN+3*ICON_XSPACE
#define ICON4_YE   ICON_YFRAM+ICON_YLEN



#define ICON5_XS   ICON_XFRAM
#define ICON5_YS   ICON_YFRAM+ICON_YSPACE+ICON_YLEN
#define ICON5_XE   ICON_XFRAM+ICON_XLEN
#define ICON5_YE   ICON_YFRAM+ICON_YSPACE+2*ICON_YLEN

#define ICON6_XS   ICON_XFRAM+ICON_XLEN+ICON_XSPACE
#define ICON6_YS   ICON_YFRAM+ICON_YSPACE+ICON_YLEN
#define ICON6_XE   ICON_XFRAM+2*ICON_XLEN+ICON_XSPACE
#define ICON6_YE   ICON_YFRAM+ICON_YSPACE+2*ICON_YLEN

#define ICON7_XS   ICON_XFRAM+2*ICON_XLEN+2*ICON_XSPACE      
#define ICON7_YS   ICON_YFRAM+ICON_YSPACE+ICON_YLEN
#define ICON7_XE   ICON_XFRAM+3*ICON_XLEN+2*ICON_XSPACE
#define ICON7_YE   ICON_YFRAM+ICON_YSPACE+2*ICON_YLEN

#define ICON8_XS   ICON_XFRAM+3*ICON_XLEN+3*ICON_XSPACE
#define ICON8_YS   ICON_YFRAM+ICON_YSPACE+ICON_YLEN
#define ICON8_XE   ICON_XFRAM+4*ICON_XLEN+3*ICON_XSPACE
#define ICON8_YE   ICON_YFRAM+ICON_YSPACE+2*ICON_YLEN



#define ICON9_XS   ICON_XFRAM
#define ICON9_YS   ICON_YFRAM+2*ICON_YSPACE+2*ICON_YLEN
#define ICON9_XE   ICON_XFRAM+ICON_XLEN
#define ICON9_YE   ICON_YFRAM+2*ICON_YSPACE+3*ICON_YLEN

#define ICON10_XS   ICON_XFRAM+ICON_XLEN+ICON_XSPACE
#define ICON10_YS   ICON_YFRAM+2*ICON_YSPACE+2*ICON_YLEN
#define ICON10_XE   ICON_XFRAM+2*ICON_XLEN+ICON_XSPACE
#define ICON10_YE   ICON_YFRAM+2*ICON_YSPACE+3*ICON_YLEN

#define ICON11_XS   ICON_XFRAM+2*ICON_XLEN+2*ICON_XSPACE
#define ICON11_YS   ICON_YFRAM+2*ICON_YSPACE+2*ICON_YLEN
#define ICON11_XE   ICON_XFRAM+3*ICON_XLEN+2*ICON_XSPACE
#define ICON11_YE   ICON_YFRAM+2*ICON_YSPACE+3*ICON_YLEN

#define ICON12_XS   ICON_XFRAM+3*ICON_XLEN+3*ICON_XSPACE
#define ICON12_YS   ICON_YFRAM+2*ICON_YSPACE+2*ICON_YLEN
#define ICON12_XE   ICON_XFRAM+4*ICON_XLEN+3*ICON_XSPACE
#define ICON12_YE   ICON_YFRAM+2*ICON_YSPACE+3*ICON_YLEN



#define ICON13_XS   ICON_XFRAM
#define ICON13_YS   ICON_YFRAM+3*ICON_YSPACE+3*ICON_YLEN
#define ICON13_XE   ICON_XFRAM+ICON_XLEN
#define ICON13_YE   ICON_YFRAM+3*ICON_YSPACE+4*ICON_YLEN

#define ICON14_XS   ICON_XFRAM+ICON_XLEN+ICON_XSPACE
#define ICON14_YS   ICON_YFRAM+3*ICON_YSPACE+3*ICON_YLEN
#define ICON14_XE   ICON_XFRAM+2*ICON_XLEN+ICON_XSPACE
#define ICON14_YE   ICON_YFRAM+3*ICON_YSPACE+4*ICON_YLEN

#define ICON15_XS   ICON_XFRAM+2*ICON_XLEN+2*ICON_XSPACE
#define ICON15_YS   ICON_YFRAM+3*ICON_YSPACE+3*ICON_YLEN
#define ICON15_XE   ICON_XFRAM+3*ICON_XLEN+2*ICON_XSPACE
#define ICON15_YE   ICON_YFRAM+3*ICON_YSPACE+4*ICON_YLEN

#define ICON16_XS   ICON_XFRAM+3*ICON_XLEN+3*ICON_XSPACE
#define ICON16_YS   ICON_YFRAM+3*ICON_YSPACE+3*ICON_YLEN
#define ICON16_XE   ICON_XFRAM+4*ICON_XLEN+3*ICON_XSPACE
#define ICON16_YE   ICON_YFRAM+3*ICON_YSPACE+4*ICON_YLEN



#define ICON17_XS   ICON_XFRAM
#define ICON17_YS   ICON_YFRAM+4*ICON_YSPACE+4*ICON_YLEN
#define ICON17_XE   ICON_XFRAM+ICON_XLEN
#define ICON17_YE   ICON_YFRAM+4*ICON_YSPACE+5*ICON_YLEN

#define ICON18_XS   ICON_XFRAM+ICON_XLEN+ICON_XSPACE
#define ICON18_YS   ICON_YFRAM+4*ICON_YSPACE+4*ICON_YLEN
#define ICON18_XE   ICON_XFRAM+2*ICON_XLEN+ICON_XSPACE
#define ICON18_YE   ICON_YFRAM+4*ICON_YSPACE+5*ICON_YLEN

#define ICON19_XS   ICON_XFRAM+2*ICON_XLEN+2*ICON_XSPACE
#define ICON19_YS   ICON_YFRAM+4*ICON_YSPACE+4*ICON_YLEN
#define ICON19_XE   ICON_XFRAM+3*ICON_XLEN+2*ICON_XSPACE
#define ICON19_YE   ICON_YFRAM+4*ICON_YSPACE+5*ICON_YLEN

#define ICON20_XS   ICON_XFRAM+3*ICON_XLEN+3*ICON_XSPACE
#define ICON20_YS   ICON_YFRAM+4*ICON_YSPACE+4*ICON_YLEN
#define ICON20_XE   ICON_XFRAM+4*ICON_XLEN+3*ICON_XSPACE
#define ICON20_YE   ICON_YFRAM+4*ICON_YSPACE+5*ICON_YLEN


#include "stm32f10x.h"
#include "wiring.h"
#include "invers_kinematic.h"
#include "math.h"
#include "hwjs.h"
#include "tftlcd.h"

extern void setup(void);
extern void loop(void);
extern int posi_now[12];

#include "stm32f10x.h"
#include "SMServo.h"
#include "uart.h"
#include "wiring.h"

uint8_t ID[1];
void setup(void)
{
  Uart_Init(115200);
  delay(500);
  ID[0] = 1;
}
#if 0
void loop(void)
{
	//指令:同步写指令, ID:1\2, 目标:0, 速度=500/s
	SyncWritePos(ID, 1, 2047, 0, 500);
	
	//行程=4095-0=4095, 加减速与积分调节时间约=300ms(负载越大时间越长,不同舵机加减速度不同时间也不同), 总运行时间=8190+300=8490ms
	delay(8490);
	
	//指令:同步写指令, ID:1\2, 目标:4095, 速度=500/s
	SyncWritePos(ID, 1, 2500, 0, 500);
	
	//行程=4095-0=4095, 加减速与积分调节时间约=300ms(负载越大时间越长,不同舵机加减速度不同时间也不同), 总运行时间=8190+300=8490ms
	delay(8490);

	//初始位置(直立)
	ID[0]=1;
	SyncWritePos(ID, 1, 2047, 0, 500);
	ID[0]=2;
	SyncWritePos(ID, 1, 1974, 0, 500);
	ID[0]=3;
	SyncWritePos(ID, 1, 976, 0, 500);
	ID[0]=4;
	SyncWritePos(ID, 1, 1234, 0, 500);
	ID[0]=5;
	SyncWritePos(ID, 1, 2555, 0, 500);
	ID[0]=6;
	SyncWritePos(ID, 1, 1261, 0, 500);
	ID[0]=7;
	SyncWritePos(ID, 1, 2264, 0, 500);
	ID[0]=8;
	SyncWritePos(ID, 1, 1160, 0, 500);
	ID[0]=9;
	SyncWritePos(ID, 1, 3072, 0, 500);
	ID[0]=10;
	SyncWritePos(ID, 1, 2048, 0, 500);
	ID[0]=11;
	SyncWritePos(ID, 1, 2300, 0, 500);
	ID[0]=12;
	SyncWritePos(ID, 1, 3146, 0, 500);
}
#endif
void before()
{
	ID[0]=1;
	SyncWritePos(ID, 1, 2047, 0, 520);
	ID[0]=2;
	SyncWritePos(ID, 1, 1974, 0, 350);
	
	ID[0]=4;
	SyncWritePos(ID, 1, 1234, 0, 520);
	ID[0]=5;
	SyncWritePos(ID, 1, 2555, 0, 350);
	
	ID[0]=7;
	SyncWritePos(ID, 1, 2264, 0, 520);
	ID[0]=8;
	SyncWritePos(ID, 1, 1160, 0, 350);
	
	ID[0]=10;
	SyncWritePos(ID, 1, 2048, 0, 520);
	ID[0]=11;
	SyncWritePos(ID, 1, 2300, 0, 350);

}

void after()
{
	ID[0]=1;
	SyncWritePos(ID, 1, 2647, 0, 520);
	ID[0]=2;
	SyncWritePos(ID, 1, 1574, 0, 350);
	
	ID[0]=4;
	SyncWritePos(ID, 1, 1834, 0, 520);
	ID[0]=5;
	SyncWritePos(ID, 1, 2955, 0, 350);
	
	ID[0]=7;
	SyncWritePos(ID, 1, 2864, 0, 520);
	ID[0]=8;
	SyncWritePos(ID, 1, 760, 0, 350);
	
	ID[0]=10;
	SyncWritePos(ID, 1, 1448, 0, 520);
	ID[0]=11;
	SyncWritePos(ID, 1, 2700, 0, 350);
}

void initSys(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
  //RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
  //RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
 
	
  // 2 bit for pre-emption priority, 2 bits for subpriority
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	SysTick_Config(SystemCoreClock / 1000);
}

void initPos()
{
	initial_traj_plan(0);
	RegWritePos(12, posi_now[11], 0, 250);
	RegWritePos(11, posi_now[10], 0, 250);
	RegWritePos(10, posi_now[9], 0, 250);
	RegWritePos(9, posi_now[8], 0, 250);
	RegWritePos(8, posi_now[7], 0, 250);
	RegWritePos(7, posi_now[6], 0, 250);
	RegWritePos(6, posi_now[5], 0, 250);
	RegWritePos(5, posi_now[4], 0, 250);
	RegWritePos(4, posi_now[3], 0, 250);
	RegWritePos(3, posi_now[2], 0, 250);
	RegWritePos(2, posi_now[1], 0, 250);
	RegWritePos(1, posi_now[0], 0, 250);
	RegWriteAction();
	delay(2000);
}
void UnderarmPos()
{
	int i = 11;
	int pre_pos[12];
	float speed_now[12];
	pre_pos[11] = posi_now[11];
	pre_pos[10] = posi_now[10];
	pre_pos[9]  = posi_now[9];
	pre_pos[8] = posi_now[8];
	pre_pos[7] = posi_now[7];
	pre_pos[6]  = posi_now[6];
	pre_pos[5] = posi_now[5];
	pre_pos[4] = posi_now[4];
	pre_pos[3]  = posi_now[3];
	pre_pos[2] = posi_now[2];
	pre_pos[1] = posi_now[1];
	pre_pos[0]  = posi_now[0];
	UnderarmPosPlan(0);
	for(;i>=0;i--)
	{
		speed_now[i] = (posi_now[i]-pre_pos[i])/1.5;
		RegWritePos(i+1, posi_now[i], 0, fabs(speed_now[i]));
	}
	RegWriteAction();
	delay(2000);
}

void UpPos()
{
	int i = 11;
	int pre_pos[12];
	float speed_now[12];
	pre_pos[11] = posi_now[11];
	pre_pos[10] = posi_now[10];
	pre_pos[9]  = posi_now[9];
	pre_pos[8] = posi_now[8];
	pre_pos[7] = posi_now[7];
	pre_pos[6]  = posi_now[6];
	pre_pos[5] = posi_now[5];
	pre_pos[4] = posi_now[4];
	pre_pos[3]  = posi_now[3];
	pre_pos[2] = posi_now[2];
	pre_pos[1] = posi_now[1];
	pre_pos[0]  = posi_now[0];
	UpPlan(0);
	
	for(;i>=0;i--)
	{
		speed_now[i] = (posi_now[i]-pre_pos[i])/1.5;
		RegWritePos(i+1, posi_now[i], 0, fabs(speed_now[i]));
	}
	
	RegWriteAction();
	delay(2000);
}

void left_swing()
{
	int i = 0;
	int pre_pos[12];
	
	pre_pos[11] = posi_now[11];
	pre_pos[10] = posi_now[10];
	pre_pos[9]  = posi_now[9];
	pre_pos[8] = posi_now[8];
	pre_pos[7] = posi_now[7];
	pre_pos[6]  = posi_now[6];
	pre_pos[5] = posi_now[5];
	pre_pos[4] = posi_now[4];
	pre_pos[3]  = posi_now[3];
	pre_pos[2] = posi_now[2];
	pre_pos[1] = posi_now[1];
	pre_pos[0]  = posi_now[0];
	
	for(;i<24;)
	{
		first_traj_plan(i);
		ID[0] = 12;
		SyncWritePos(ID, 1, posi_now[11], 0, (posi_now[11]-pre_pos[11])/0.05);
		ID[0] = 11;
		SyncWritePos(ID, 1, posi_now[10], 0, (posi_now[10]-pre_pos[10])/0.05);
		ID[0] = 10;
		SyncWritePos(ID, 1, posi_now[9], 0, (posi_now[9]-pre_pos[9])/0.05);
		ID[0] = 6;
		SyncWritePos(ID, 1, posi_now[5], 0, (posi_now[5]-pre_pos[5])/0.05);
		ID[0] = 5;
		SyncWritePos(ID, 1, posi_now[4], 0, (posi_now[4]-pre_pos[4])/0.05);
		ID[0] = 4;
		SyncWritePos(ID, 1, posi_now[3], 0, (posi_now[3]-pre_pos[3])/0.05);
		
		ID[0] = 9;
		SyncWritePos(ID, 1, posi_now[8], 0, (posi_now[8]-pre_pos[8])/0.05);
		ID[0] = 8;
		SyncWritePos(ID, 1, posi_now[7], 0, (posi_now[7]-pre_pos[7])/0.05);
		ID[0] = 7;
		SyncWritePos(ID, 1, posi_now[6], 0, (posi_now[6]-pre_pos[6])/0.05);

		ID[0] = 3;
		SyncWritePos(ID, 1, posi_now[2], 0, (posi_now[2]-pre_pos[2])/0.05);
		ID[0] = 2;
		SyncWritePos(ID, 1, posi_now[1], 0, (posi_now[1]-pre_pos[1])/0.05);
		ID[0] = 1;
		SyncWritePos(ID, 1, posi_now[0], 0, (posi_now[0]-pre_pos[0])/0.05);
		delay(50);
		i+=2;
	}
}

void right_swing()
{
	int i = 0;
	int pre_pos[12];
	
	
	pre_pos[11] = posi_now[11];
	pre_pos[10] = posi_now[10];
	pre_pos[9]  = posi_now[9];
	pre_pos[8] = posi_now[8];
	pre_pos[7] = posi_now[7];
	pre_pos[6]  = posi_now[6];
	pre_pos[5] = posi_now[5];
	pre_pos[4] = posi_now[4];
	pre_pos[3]  = posi_now[3];
	pre_pos[2] = posi_now[2];
	pre_pos[1] = posi_now[1];
	pre_pos[0]  = posi_now[0];
	
	for(;i<24;)
	{
		second_traj_plan(i);
		ID[0] = 12;
		SyncWritePos(ID, 1, posi_now[11], 0, (posi_now[11]-pre_pos[11])/0.05);
		ID[0] = 11;
		SyncWritePos(ID, 1, posi_now[10], 0, (posi_now[10]-pre_pos[10])/0.05);
		ID[0] = 10;
		SyncWritePos(ID, 1, posi_now[9], 0, (posi_now[9]-pre_pos[9])/0.05);
		ID[0] = 6;
		SyncWritePos(ID, 1, posi_now[5], 0, (posi_now[5]-pre_pos[5])/0.05);
		ID[0] = 5;
		SyncWritePos(ID, 1, posi_now[4], 0, (posi_now[4]-pre_pos[4])/0.05);
		ID[0] = 4;
		SyncWritePos(ID, 1, posi_now[3], 0, (posi_now[3]-pre_pos[3])/0.05);
		
		ID[0] = 9;
		SyncWritePos(ID, 1, posi_now[8], 0, (posi_now[8]-pre_pos[8])/0.05);
		ID[0] = 8;
		SyncWritePos(ID, 1, posi_now[7], 0, (posi_now[7]-pre_pos[7])/0.05);
		ID[0] = 7;
		SyncWritePos(ID, 1, posi_now[6], 0, (posi_now[6]-pre_pos[6])/0.05);

		ID[0] = 3;
		SyncWritePos(ID, 1, posi_now[2], 0, (posi_now[2]-pre_pos[2])/0.05);
		ID[0] = 2;
		SyncWritePos(ID, 1, posi_now[1], 0, (posi_now[1]-pre_pos[1])/0.05);
		ID[0] = 1;
		SyncWritePos(ID, 1, posi_now[0], 0, (posi_now[0]-pre_pos[0])/0.05);
		delay(50);
		i+=2;
	}
}

void start()
{
	
	int i = 0;
	int pre_pos[12];
	float interval_time=0.1;
  pre_pos[11] = posi_now[11];
	pre_pos[10] = posi_now[10];
	pre_pos[9]  = posi_now[9];
	pre_pos[8]  = posi_now[8];
	pre_pos[7]  = posi_now[7];
	pre_pos[6]  = posi_now[6];
	pre_pos[5]  = posi_now[5];
	pre_pos[4]  = posi_now[4];
	pre_pos[3]  = posi_now[3];
	pre_pos[2]  = posi_now[2];
	pre_pos[1]  = posi_now[1];
	pre_pos[0]  = posi_now[0];
	
	for(;i<12;)
	{
		initial_traj_plan(i);
		ID[0] = 12;
		SyncWritePos(ID, 1, posi_now[11], 0, (posi_now[11]-pre_pos[11])/interval_time);
		ID[0] = 11;
		SyncWritePos(ID, 1, posi_now[10], 0, (posi_now[10]-pre_pos[10])/interval_time);
		ID[0] = 10;
		SyncWritePos(ID, 1, posi_now[9], 0, (posi_now[9]-pre_pos[9])/interval_time);
		ID[0] = 9;
		SyncWritePos(ID, 1, posi_now[8], 0, (posi_now[8]-pre_pos[8])/interval_time);
		ID[0] = 8;
		SyncWritePos(ID, 1, posi_now[7], 0, (posi_now[7]-pre_pos[7])/interval_time);
		ID[0] = 7;
		SyncWritePos(ID, 1, posi_now[6], 0, (posi_now[6]-pre_pos[6])/interval_time);
		ID[0] = 6;
		SyncWritePos(ID, 1, posi_now[5], 0, (posi_now[5]-pre_pos[5])/interval_time);
		ID[0] = 5;
		SyncWritePos(ID, 1, posi_now[4], 0, (posi_now[4]-pre_pos[4])/interval_time);
		ID[0] = 4;
		SyncWritePos(ID, 1, posi_now[3], 0, (posi_now[3]-pre_pos[3])/interval_time);	
		ID[0] = 3;
		SyncWritePos(ID, 1, posi_now[2], 0, (posi_now[2]-pre_pos[2])/interval_time);
		ID[0] = 2;
		SyncWritePos(ID, 1, posi_now[1], 0, (posi_now[1]-pre_pos[1])/interval_time);
		ID[0] = 1;
		SyncWritePos(ID, 1, posi_now[0], 0, (posi_now[0]-pre_pos[0])/interval_time);
		delay(80);
		i+=2;
	}
	
}





void LCD_DisplayWindows(void)
{

	//LCD_ShowPicture(0,0,tftlcd_data.width,tftlcd_data.height,(u8 *)gImage_back);
	LCD_Clear(LIGHTBLUE);
	
	LCD_ShowPicture(ICON1_XS,ICON1_YS,ICON_SIZE,ICON_SIZE,(u8 *)gImage_led);
	LCD_ShowStringTrans(ICON1_XS+(ICON_XLEN-3*6)/2,ICON1_YS+ICON_YLEN+(ICON_YSPACE-8)/2,100,20,12,"LED");
	
	LCD_ShowPicture(ICON2_XS,ICON2_YS,ICON_SIZE,ICON_SIZE,(u8 *)gImage_beep);
	LCD_ShowStringTrans(ICON2_XS+(ICON_XLEN-4*6)/2,ICON2_YS+ICON_YLEN+(ICON_YSPACE-8)/2,100,20,12,"BEEP");
	
	LCD_ShowPicture(ICON3_XS,ICON3_YS,ICON_SIZE,ICON_SIZE,(u8 *)gImage_key);
	LCD_ShowStringTrans(ICON3_XS+(ICON_XLEN-3*6)/2,ICON3_YS+ICON_YLEN+(ICON_YSPACE-8)/2,100,20,12,"KEY");
	
	LCD_ShowPicture(ICON4_XS,ICON4_YS,ICON_SIZE,ICON_SIZE,(u8 *)gImage_dac);
	LCD_ShowStringTrans(ICON4_XS+(ICON_XLEN-3*6)/2,ICON4_YS+ICON_YLEN+(ICON_YSPACE-8)/2,100,20,12,"ADC");
	
	LCD_ShowPicture(ICON5_XS,ICON5_YS,ICON_SIZE,ICON_SIZE,(u8 *)gImage_smg);
	LCD_ShowStringTrans(ICON5_XS+(ICON_XLEN-3*6)/2,ICON5_YS+ICON_YLEN+(ICON_YSPACE-8)/2,100,20,12,"SMG");
	
	LCD_ShowPicture(ICON6_XS,ICON6_YS,ICON_SIZE,ICON_SIZE,(u8 *)gImage_ds18b20);
	LCD_ShowStringTrans(ICON6_XS+(ICON_XLEN-5*6)/2,ICON6_YS+ICON_YLEN+(ICON_YSPACE-8)/2,100,20,12,"18B20");
	
	LCD_ShowPicture(ICON7_XS,ICON7_YS,ICON_SIZE,ICON_SIZE,(u8 *)gImage_eeprom);
	LCD_ShowStringTrans(ICON7_XS+(ICON_XLEN-6*6)/2,ICON7_YS+ICON_YLEN+(ICON_YSPACE-8)/2,100,20,12,"EEPROM");
	
	LCD_ShowPicture(ICON8_XS,ICON8_YS,ICON_SIZE,ICON_SIZE,(u8 *)gImage_ired);
	LCD_ShowStringTrans(ICON8_XS+(ICON_XLEN-4*6)/2,ICON8_YS+ICON_YLEN+(ICON_YSPACE-8)/2,100,20,12,"IRED");
	
	LCD_ShowPicture(ICON9_XS,ICON9_YS,ICON_SIZE,ICON_SIZE,(u8 *)gImage_flash);
	LCD_ShowStringTrans(ICON9_XS+(ICON_XLEN-5*6)/2,ICON9_YS+ICON_YLEN+(ICON_YSPACE-8)/2,100,20,12,"FLASH");
	
	LCD_ShowPicture(ICON10_XS,ICON10_YS,ICON_SIZE,ICON_SIZE,(u8 *)gImage_sram);
	LCD_ShowStringTrans(ICON10_XS+(ICON_XLEN-4*6)/2,ICON10_YS+ICON_YLEN+(ICON_YSPACE-8)/2,100,20,12,"SRAM");
	
	LCD_ShowPicture(ICON11_XS,ICON11_YS,ICON_SIZE,ICON_SIZE,(u8 *)gImage_adx345);
	LCD_ShowStringTrans(ICON11_XS+(ICON_XLEN-6*6)/2,ICON11_YS+ICON_YLEN+(ICON_YSPACE-8)/2,100,20,12,"ADX345");
	
	LCD_ShowPicture(ICON12_XS,ICON12_YS,ICON_SIZE,ICON_SIZE,(u8 *)gImage_sd);
	LCD_ShowStringTrans(ICON12_XS+(ICON_XLEN-2*6)/2,ICON12_YS+ICON_YLEN+(ICON_YSPACE-8)/2,100,20,12,"SD");
	
	LCD_ShowPicture(ICON13_XS,ICON13_YS,ICON_SIZE,ICON_SIZE,(u8 *)gImage_rs232);
	LCD_ShowStringTrans(ICON13_XS+(ICON_XLEN-5*6)/2,ICON13_YS+ICON_YLEN+(ICON_YSPACE-8)/2,100,20,12,"RS232");
	
	LCD_ShowPicture(ICON14_XS,ICON14_YS,ICON_SIZE,ICON_SIZE,(u8 *)gImage_rs485);
	LCD_ShowStringTrans(ICON14_XS+(ICON_XLEN-5*6)/2,ICON14_YS+ICON_YLEN+(ICON_YSPACE-8)/2,100,20,12,"RS485");
	
	LCD_ShowPicture(ICON15_XS,ICON15_YS,ICON_SIZE,ICON_SIZE,(u8 *)gImage_can);
	LCD_ShowStringTrans(ICON15_XS+(ICON_XLEN-3*6)/2,ICON15_YS+ICON_YLEN+(ICON_YSPACE-8)/2,100,20,12,"CAN");
	
	LCD_ShowPicture(ICON16_XS,ICON16_YS,ICON_SIZE,ICON_SIZE,(u8 *)gImage_internet);
	LCD_ShowStringTrans(ICON16_XS+(ICON_XLEN-5*6)/2,ICON16_YS+ICON_YLEN+(ICON_YSPACE-8)/2,100,20,12,"Inter");
	
	LCD_ShowPicture(ICON17_XS,ICON17_YS,ICON_SIZE,ICON_SIZE,(u8 *)gImage_map);
	LCD_ShowPicture(ICON18_XS,ICON18_YS,ICON_SIZE,ICON_SIZE,(u8 *)gImage_phone);
	LCD_ShowPicture(ICON19_XS,ICON19_YS,ICON_SIZE,ICON_SIZE,(u8 *)gImage_message);
	
}


int main()
{
	u8 start=0;
		initSys();
	  setup();
	  initPos();
	 
//	  while(1)
//		{
//			UnderarmPos();
//			UpPos();
//		}
	
		//TIM5_Init(9,8);
	   SysTick_Init(72);

//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //中断优先级分组 分2组
//	LED_Init();
//	KEY_Init();
	//TFTLCD_Init();			//LCD初始化
//	TOUCH_Init();
//	
//	EN25QXX_Init();				//初始化EN25QXX 
//	FSMC_SRAM_Init(); 
//	my_mem_init(SRAMIN);		//初始化内部内存池
//	my_mem_init(SRAMEX);		//初始化外部SRAM内存池
//	
//	LCD_DisplayWindows();
//	RTC_Init();
	
	IRED_Test();
	

	


	while(1)
	{	
		UnderarmPos();
		UpPos();
	}
	
}


//int main()
//{

	
/*	
	start();
	while(1)
	{
	left_swing();
	right_swing();
	}
*/
	

//}
