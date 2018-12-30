/*
 * SMServo.c
 * ���ض��Ӳ���ӿڲ����
 * ����: 2018.7.3
 * ����: ̷����
 */

#include "stm32f10x.h"
#include "uart.h"
#include "wiring.h"

uint32_t IOTimeOut = 2;//���������ʱ

//UART �������ݽӿ�
int readSCS(unsigned char *nDat, int nLen)
{
	int Size = 0;
	int ComData;
	uint32_t t_begin = millis();
	uint32_t t_user;
	while(1){
		ComData = Uart_Read();
		if(ComData!=-1){
			if(nDat){
				nDat[Size] = ComData;
			}
			Size++;
			t_begin = millis();
		}
		if(Size>=nLen){
			break;
		}
		t_user = millis() - t_begin;
		if(t_user>IOTimeOut){
			break;
		}
	}
	return Size;
}

//UART �������ݽӿ�
int writeSCS(unsigned char *nDat, int nLen)
{
	Uart_DmaSend(nDat, nLen);
	return 0;
}

//���ջ�����ˢ��
void flushSCS()
{
	Uart_Flush();
}
