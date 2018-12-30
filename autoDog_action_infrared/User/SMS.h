/*
 * SMS.h
 * ���ش��ж��ͨ��Э�����
 * ����: 2018.7.3
 * ����: ̷����
 */

#ifndef _SMS_H
#define _SMS_H

extern int genWrite(uint8_t ID, uint8_t MemAddr, uint8_t *nDat, uint8_t nLen);//��ͨдָ��
extern int regWrite(uint8_t ID, uint8_t MemAddr, uint8_t *nDat, uint8_t nLen);//�첽дָ��
extern void snycWrite(uint8_t ID[], uint8_t IDN, uint8_t MemAddr, uint8_t *nDat, uint8_t nLen);//ͬ��дָ��
extern int writeByte(uint8_t ID, uint8_t MemAddr, uint8_t bDat);//д1���ֽ�
extern int writeWord(uint8_t ID, uint8_t MemAddr, uint16_t wDat);//д2���ֽ�
extern int Read(uint8_t ID, uint8_t MemAddr, uint8_t *nData, uint8_t nLen);//��ָ��
extern int readByte(uint8_t ID, uint8_t MemAddr);//��1���ֽ�
extern int readWord(uint8_t ID, uint8_t MemAddr);//��2���ֽ�
extern int Ack(uint8_t ID);//Ӧ��
extern void writeBuf(uint8_t ID, uint8_t MemAddr, uint8_t *nDat, uint8_t nLen, uint8_t Fun);
extern void Host2SCS(uint8_t *DataL, uint8_t* DataH, int Data);//1��16λ�����Ϊ2��8λ��
extern int SCS2Host(uint8_t DataL, uint8_t DataH);//2��8λ�����Ϊ1��16λ��

//Ӳ���ӿں���
extern int writeSCS(uint8_t *nDat, int nLen);
extern int readSCS(uint8_t *nDat, int nLen);
extern void flushSCS(void);

#endif
