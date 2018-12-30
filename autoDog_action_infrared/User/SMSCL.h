/*
 * SMSCL.h
 * 飞特SMSCL系列串行舵机应用层程序
 * 日期: 2018.7.3
 * 作者: 谭雄乐
 */

#ifndef _SMSCL_H
#define _SMSCL_H

//波特率定义
#define		SMSCL_1M			0
#define		SMSCL_0_5M		1
#define		SMSCL_250K		2
#define		SMSCL_128K		3
#define		SMSCL_115200	4
#define		SMSCL_76800		5
#define		SMSCL_57600		6
#define		SMSCL_38400		7

//内存表定义
//-------EPROM(只读)--------
#define SMSCL_VERSION_L 0
#define SMSCL_VERSION_H 1
#define SMSCL_MODEL_L 3
#define SMSCL_MODEL_H 4

//-------EPROM(读写)--------
#define SMSCL_ID 5
#define SMSCL_BAUD_RATE 6
#define SMSCL_RETURN_DELAY_TIME 7
#define SMSCL_RETURN_LEVEL 8
#define SMSCL_MIN_ANGLE_LIMIT_L 9
#define SMSCL_MIN_ANGLE_LIMIT_H 10
#define SMSCL_MAX_ANGLE_LIMIT_L 11
#define SMSCL_MAX_ANGLE_LIMIT_H 12
#define SMSCL_LIMIT_TEMPERATURE 13
#define SMSCL_MAX_LIMIT_VOLTAGE 14
#define SMSCL_MIN_LIMIT_VOLTAGE 15
#define SMSCL_MAX_TORQUE_L 16
#define SMSCL_MAX_TORQUE_H 17
#define SMSCL_ALARM_LED 19
#define SMSCL_ALARM_SHUTDOWN 20
#define SMSCL_COMPLIANCE_P 21
#define SMSCL_COMPLIANCE_D 22
#define SMSCL_COMPLIANCE_I 23
#define SMSCL_PUNCH_L 24
#define SMSCL_PUNCH_H 25
#define SMSCL_CW_DEAD 26
#define SMSCL_CCW_DEAD 27
#define SMSCL_MAX_CURRENT_L 28
#define SMSCL_MAX_CURRENT_H 29
#define SMSCL_OFS_L 33
#define SMSCL_OFS_H 34
#define SMSCL_MODE 35
#define SMSCL_PROTECT_TORQUE 37
#define SMSCL_PROTECT_TIME 38
#define SMSCL_OVLOAD_TORQUE 39

//-------SRAM(读写)--------
#define SMSCL_TORQUE_ENABLE 40
#define SMSCL_GOAL_POSITION_L 42
#define SMSCL_GOAL_POSITION_H 43
#define SMSCL_GOAL_TIME_L 44
#define SMSCL_GOAL_TIME_H 45
#define SMSCL_GOAL_SPEED_L 46
#define SMSCL_GOAL_SPEED_H 47
#define SMSCL_LOCK 48

//-------SRAM(只读)--------
#define SMSCL_PRESENT_POSITION_L 56
#define SMSCL_PRESENT_POSITION_H 57
#define SMSCL_PRESENT_SPEED_L 58
#define SMSCL_PRESENT_SPEED_H 59
#define SMSCL_PRESENT_LOAD_L 60
#define SMSCL_PRESENT_LOAD_H 61
#define SMSCL_PRESENT_VOLTAGE 62
#define SMSCL_PRESENT_TEMPERATURE 63
#define SMSCL_MOVING 66



extern int WritePos(uint8_t ID, int16_t Position, uint16_t Time, uint16_t Speed);//普通写位置指令
extern int RegWritePos(uint8_t ID, int16_t Position, uint16_t Time, uint16_t Speed);//异步写位置指令
extern void SyncWritePos(uint8_t ID[], uint8_t IDN, int16_t Position, uint16_t Time, uint16_t Speed);//同步写位置指令
extern int WritePWM(uint8_t ID, int16_t Torque);//PWM输出
extern int pwmMode(uint8_t ID);//PWM输出模式
extern int joinMode(uint8_t ID);//普通伺服模式
extern int ReadPos(uint8_t ID, uint8_t *Err);//读位置
extern int EnableTorque(uint8_t ID, uint8_t Enable);//扭力控制指令
extern void RegWriteAction(void);//执行异步写指令
extern int ReadLoad(uint8_t ID);//读当输出负载
extern int ReadVoltage(uint8_t ID);//读电压
extern int ReadTemper(uint8_t ID);//读温度
extern int Ping(uint8_t ID);//Ping指令

//返回0失败,返回1成功
extern int unLockEprom(uint8_t ID);//eprom解锁
extern int LockEprom(uint8_t ID);//eprom加锁
extern int WriteOfs(uint8_t ID, int16_t Ofs);//中位校准
extern int Recovery(uint8_t ID);//恢复舵机参数为默认值
extern int Reset(uint8_t ID);//复位舵机(位置重置为单圈)

#endif
