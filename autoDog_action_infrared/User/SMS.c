/*
 * SMS.c
 * SMS���ж��Э�����
 * ����: 2018.7.3
 * ����: ̷����
 */

#include "INST.h"
#include "SMS.h"


static uint8_t	Level =1;//������صȼ�
static uint8_t	End = 0;//��������С�˽ṹ

//1��16λ�����Ϊ2��8λ��
//DataLΪ��λ��DataHΪ��λ
void Host2SCS(uint8_t *DataL, uint8_t* DataH, int Data)
{
	if(End){
		*DataL = (Data>>8);
		*DataH = (Data&0xff);
	}else{
		*DataH = (Data>>8);
		*DataL = (Data&0xff);
	}
}

//2��8λ�����Ϊ1��16λ��
//DataLΪ��λ��DataHΪ��λ
int SCS2Host(uint8_t DataL, uint8_t DataH)
{
	int Data;
	if(End){
		Data = DataL;
		Data<<=8;
		Data |= DataH;
	}else{
		Data = DataH;
		Data<<=8;
		Data |= DataL;
	}
	return Data;
}

void writeBuf(uint8_t ID, uint8_t MemAddr, uint8_t *nDat, uint8_t nLen, uint8_t Fun)
{
	uint8_t i;
	uint8_t msgLen = 2;
	uint8_t bBuf[6];
	uint8_t CheckSum = 0;
	bBuf[0] = 0xff;
	bBuf[1] = 0xff;
	bBuf[2] = ID;
	bBuf[4] = Fun;
	if(nDat){
		msgLen += nLen + 1;
		bBuf[3] = msgLen;
		bBuf[5] = MemAddr;
		writeSCS(bBuf, 6);
		
	}else{
		bBuf[3] = msgLen;
		writeSCS(bBuf, 5);
	}
	CheckSum = ID + msgLen + Fun + MemAddr;
	if(nDat){
		for(i=0; i<nLen; i++){
			CheckSum += nDat[i];
		}
		writeSCS(nDat, nLen);
	}
	CheckSum = ~CheckSum;
	writeSCS(&CheckSum, 1);
}

//��ͨдָ��
//���ID��MemAddr�ڴ���ַ��д�����ݣ�д�볤��
int genWrite(uint8_t ID, uint8_t MemAddr, uint8_t *nDat, uint8_t nLen)
{
	flushSCS();
	writeBuf(ID, MemAddr, nDat, nLen, INST_WRITE);
	return Ack(ID);
}

//�첽дָ��
//���ID��MemAddr�ڴ���ַ��д�����ݣ�д�볤��
int regWrite(uint8_t ID, uint8_t MemAddr, uint8_t *nDat, uint8_t nLen)
{
	flushSCS();
	writeBuf(ID, MemAddr, nDat, nLen, INST_REG_WRITE);
	return Ack(ID);
}

//ͬ��дָ��
//���ID[]���飬IDN���鳤�ȣ�MemAddr�ڴ���ַ��д�����ݣ�д�볤��
void snycWrite(uint8_t ID[], uint8_t IDN, uint8_t MemAddr, uint8_t *nDat, uint8_t nLen)
{
	uint8_t i, j;
	uint8_t mesLen = ((nLen+1)*IDN+4);
	uint8_t checkSum = 0;
	uint8_t bBuf[7];
	bBuf[0] = 0xff;
	bBuf[1] = 0xff;
	bBuf[2] = 0xfe;
	bBuf[3] = mesLen;
	bBuf[4] = INST_SYNC_WRITE;
	bBuf[5] = MemAddr;
	bBuf[6] = nLen;
	writeSCS(bBuf, 7);

	checkSum = 0xfe + mesLen + INST_SYNC_WRITE + MemAddr + nLen;
	for(i=0; i<IDN; i++){
		writeSCS(ID+i, 1);
		writeSCS(nDat, nLen);
		checkSum += ID[i];
		for(j=0; j<nLen; j++){
			checkSum += nDat[j];
		}
	}
	checkSum = ~checkSum;
	writeSCS(&checkSum, 1);
}

int writeByte(uint8_t ID, uint8_t MemAddr, uint8_t bDat)
{
	flushSCS();
	writeBuf(ID, MemAddr, &bDat, 1, INST_WRITE);
	return Ack(ID);
}

int writeWord(uint8_t ID, uint8_t MemAddr, uint16_t wDat)
{
	uint8_t buf[2];
	flushSCS();
	Host2SCS(buf+0, buf+1, wDat);
	writeBuf(ID, MemAddr, buf, 2, INST_WRITE);
	return Ack(ID);
}

//��ָ��
//���ID��MemAddr�ڴ���ַ����������nData�����ݳ���nLen
int Read(uint8_t ID, uint8_t MemAddr, uint8_t *nData, uint8_t nLen)
{
	int Size;
	uint8_t bBuf[5];
	flushSCS();
	writeBuf(ID, MemAddr, &nLen, 1, INST_READ);
	if(readSCS(bBuf, 5)!=5){
		return 0;
	}
	Size = readSCS(nData, nLen);
	if(readSCS(bBuf, 1)){
		return Size;
	}
	return 0;
}

//��1�ֽڣ���ʱ����-1
int readByte(uint8_t ID, uint8_t MemAddr)
{
	uint8_t bDat;
	int Size = Read(ID, MemAddr, &bDat, 1);
	if(Size!=1){
		return -1;
	}else{
		return bDat;
	}
}

//��2�ֽڣ���ʱ����-1
int readWord(uint8_t ID, uint8_t MemAddr)
{	
	uint8_t nDat[2];
	int Size;
	uint16_t wDat;
	Size = Read(ID, MemAddr, nDat, 2);
	if(Size!=2)
		return -1;
	wDat = SCS2Host(nDat[0], nDat[1]);
	return wDat;
}

//ָ��Ӧ��
int	Ack(uint8_t ID)
{
	if(ID != 0xfe && Level){
		uint8_t buf[6];
		uint8_t Size = readSCS(buf, 6);
		if(Size!=6){
			return 0;
		}
	}
	return 1;
}
