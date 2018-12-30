/*
 * uart.c
 * UART�ӿ�
 * ����: 2016.11.11
 * ����: ̷����
 */

#include "stm32f10x.h"
#include "uart.h"

//UART �����ݻ�����
__IO uint8_t uart1Buf[128];
__IO int head1 = 0;
__IO int tail1  = 0;

void Uart_Flush(void)
{
	head1 = tail1 = 0;
}

short Uart_Read(void)
{
	if(head1!=tail1){
		uint8_t Data = uart1Buf[head1];
		head1 =  (head1+1)%128;
		return Data;
	}else{
		return -1;
	}
}

/*---------------
ʹ��USE_USART1_���ó�USART1���˿ڲ���ӳ��(TX)PB6/(RX)PB7
ʹ��DMAͨ��4��ΪTX����ͨ��
------------------*/
#ifdef USE_USART1_
void Uart_Init(uint32_t baudRate)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	DMA_InitTypeDef DMA_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	//UART1 GPIO ����
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;//PA9 UART1_TX
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
    
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//PA10 UART1_RX
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

	//DMA ����
	//UART1	DMA
  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&USART1->DR);
  DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)0;
  DMA_InitStructure.DMA_BufferSize = 0;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
  DMA_Init(DMA1_Channel4, &DMA_InitStructure);
  DMA_Cmd(DMA1_Channel4, ENABLE);
  
	//UART ���ݸ�ʽ����
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Tx|USART_Mode_Rx;
	USART_InitStructure.USART_BaudRate = baudRate;
	USART_Init(USART1, &USART_InitStructure);
	
	//�ж�����
  USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

	//��DMA��UARTʹ�ܿ���
	USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE);
  USART_Cmd(USART1, ENABLE);
}

void USART1_IRQHandler(void)
{
		uart1Buf[tail1] = USART1->DR;
		tail1 = (tail1+1)%128;
}

void Uart_DmaSend(uint8_t *buf , uint8_t len)
{
	USART1->SR &= ~(1<<6);
	DMA1_Channel4->CCR &= ~0x01;
	DMA1_Channel4->CMAR = (uint32_t)buf;
	DMA1_Channel4->CNDTR = len;
	DMA1_Channel4->CCR |= 0x01;
	while(!(USART1->SR&(1<<7)));
	while(!(USART1->SR&(1<<6)));
}
#endif

/*---------------
ʹ��USE_USART2_���ó�USART2���˿�ӳ��(TX)PA2/(RX)PA3
ʹ��DMAͨ��7��ΪTX����ͨ��
------------------*/
#ifdef USE_USART2_
void Uart_Init(uint32_t baudRate)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	DMA_InitTypeDef DMA_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	//UART2 GPIO ����
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;//PA2 UART2_TX
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
    
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;//PA3 UART2_RX
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

	//DMA ����
	//UART2	DMA
  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&USART2->DR);
  DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)0;
  DMA_InitStructure.DMA_BufferSize = 0;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
  DMA_Init(DMA1_Channel7, &DMA_InitStructure);
  DMA_Cmd(DMA1_Channel7, ENABLE);
  
	//UART ���ݸ�ʽ����
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Tx|USART_Mode_Rx;
	USART_InitStructure.USART_BaudRate = baudRate;
	USART_Init(USART2, &USART_InitStructure);
	
	//�ж�����
  USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);
  NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

	//��DMA��UARTʹ�ܿ���
	USART_DMACmd(USART2, USART_DMAReq_Tx, ENABLE);
  USART_Cmd(USART2, ENABLE);
}

void USART2_IRQHandler(void)
{
		uart1Buf[tail1] = USART2->DR;
		tail1 = (tail1+1)%128;
}

void Uart_DmaSend(uint8_t *buf , uint8_t len)
{
	USART2->SR &= ~(1<<6);
	DMA1_Channel7->CCR &= ~0x01;
	DMA1_Channel7->CMAR = (uint32_t)buf;
	DMA1_Channel7->CNDTR = len;
	DMA1_Channel7->CCR |= 0x01;
	while(!(USART2->SR&(1<<7)));
	while(!(USART2->SR&(1<<6)));
}
#endif
