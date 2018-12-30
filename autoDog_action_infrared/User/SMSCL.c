/*
 * SMSCL.c
 * 飞特SMSCL系列串行舵机应用层程序
 * 日期: 2018.7.3
 * 作者: 谭雄乐
 */

#include "INST.h"
#include "SMS.h"
#include "SMSCL.h"

int EnableTorque(uint8_t ID, uint8_t Enable)
{
	return writeByte(ID, SMSCL_TORQUE_ENABLE, Enable);
}

int ReadTorqueEnable(uint8_t ID)
{
	return readByte(ID, SMSCL_TORQUE_ENABLE);
}

int writePos(uint8_t ID, uint16_t Position, uint16_t Time, uint16_t Speed, uint8_t Fun)
{
	uint8_t buf[6];
	flushSCS();

	Host2SCS(buf+0, buf+1, Position);
	Host2SCS(buf+2, buf+3, Time);
	Host2SCS(buf+4, buf+5, Speed);
	writeBuf(ID, SMSCL_GOAL_POSITION_L, buf, 6, Fun);
	return Ack(ID);
}

//写位置指令
//舵机ID，Position位置，运行时间Time，速度Speed
int WritePos(uint8_t ID, int16_t Position, uint16_t Time, uint16_t Speed)
{
	if(Position<0){
		Position = -Position;
		Position |= (1<<15);
	}
	return writePos(ID, Position, Time, Speed, INST_WRITE);
}

//异步写位置指令
//舵机ID，Position位置，运行时间Time，速度Speed
int RegWritePos(uint8_t ID, int16_t Position, uint16_t Time, uint16_t Speed)
{
	if(Position<0){
		Position = -Position;
		Position |= (1<<15);
	}
	return writePos(ID, Position, Time, Speed, INST_REG_WRITE);
}

void RegWriteAction(void)
{
	writeBuf(0xfe, 0, NULL, 0, INST_ACTION);
}

//写位置指令
//舵机ID[]数组，IDN数组长度，Position位置，运行时间Time，速度Speed
void SyncWritePos(uint8_t ID[], uint8_t IDN, int16_t Position, uint16_t Time, uint16_t Speed)
{
	uint8_t buf[6];
	if(Position<0){
		Position = -Position;
		Position |= (1<<15);
	}
	Host2SCS(buf+0, buf+1, Position);
	Host2SCS(buf+2, buf+3, Time);
	Host2SCS(buf+4, buf+5, Speed);
	snycWrite(ID, IDN, SMSCL_GOAL_POSITION_L, buf, 6);
}

//读位置，超时Err=1
int ReadPos(uint8_t ID, uint8_t *Err)
{
	int16_t curPos = readWord(ID, SMSCL_PRESENT_POSITION_L);
	if(curPos==-1){
		if(Err){
			*Err = 1;
		}
		return -1;
	}
	if(curPos&(1<<15)){
		curPos = -(curPos&~(1<<15));
	}
	if(Err){
		*Err = 0;
	}
	
	return curPos;
}

//读输出负载，超时返回-1
int ReadLoad(uint8_t ID)
{	
	return readWord(ID, SMSCL_PRESENT_LOAD_L);
}

//读电压，超时返回-1
 int ReadVoltage(uint8_t ID)
{	
	return readByte(ID, SMSCL_PRESENT_VOLTAGE);
}

//读温度，超时返回-1
int ReadTemper(uint8_t ID)
{	
	return readByte(ID, SMSCL_PRESENT_TEMPERATURE);
}

//Ping指令，返回舵机ID，超时返回-1
int Ping(uint8_t ID)
{
	int Size;
	uint8_t bBuf[6];
	flushSCS();
	writeBuf(ID, 0, NULL, 0, INST_PING);
	Size = readSCS(bBuf, 6);
	if(Size==6){
		return bBuf[2];
	}else{
		return -1;
	}
}

int pwmMode(uint8_t ID)
{
	return writeByte(ID, SMSCL_MODE, 2);		
}

int joinMode(uint8_t ID) 
{
	return writeByte(ID, SMSCL_MODE, 0);	
}

//复位舵机参数为默认值
int Recovery(uint8_t ID)
{
	flushSCS();
	writeBuf(ID, 0, NULL, 0, INST_RECOVERY);
	return Ack(ID);
}

//复位舵机位置为单圈值
int Reset(uint8_t ID)
{
	flushSCS();
	writeBuf(ID, 0, NULL, 0, INST_RESET);
	return Ack(ID);
}

int WriteOfs(uint8_t ID, int16_t Ofs)
{
	if(Ofs<0){
		Ofs = -Ofs;
		Ofs |= (1<<15);
	}
	return writeWord(ID, SMSCL_OFS_L, Ofs);
}

int unLockEprom(uint8_t ID)
{
	return writeByte(ID, SMSCL_LOCK, 0);//打开EPROM保存功能
}

int LockEprom(uint8_t ID)
{
	return writeByte(ID, SMSCL_LOCK, 1);//关闭EPROM保存功能
}

int WritePWM(uint8_t ID, int16_t Torque)
{
	if(Torque<0){
		Torque = -Torque;
		Torque |= (1<<9);
	}
	return writeWord(ID, SMSCL_GOAL_TIME_L, Torque);
}
