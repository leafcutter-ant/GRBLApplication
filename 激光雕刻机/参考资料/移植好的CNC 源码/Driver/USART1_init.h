#ifndef _USART1_INIT_H_	
#define _USART1_INIT_H_

#ifdef __cplusplus									  //定义对CPP进行C处理
extern "C" {
#endif

#include "Config.h"

#define USART1BaudRate		115200		   			  //定义串口1的波特率
//#define USART1RxRank    	4						  //串口1接收队列深度	最大深度8级 

//#define USART1RXMAXRANK    (0x01<<(USART1RxRank-1))	  //计算最次的接收优先级

	
/*************************************///Grbl_serial
#ifndef RX_BUFFER_SIZE
  #define RX_BUFFER_SIZE 128
#endif
#ifndef TX_BUFFER_SIZE
  #define TX_BUFFER_SIZE 64
#endif

#define SERIAL_NO_DATA 0xff
	
extern uint8_t rx_buffer[RX_BUFFER_SIZE];
extern uint8_t rx_buffer_head;
extern volatile uint8_t rx_buffer_tail;

extern uint8_t tx_buffer[TX_BUFFER_SIZE];
extern uint8_t tx_buffer_head;
extern volatile uint8_t tx_buffer_tail;

void serial_write(uint8_t data);
/****************************************/

//typedef struct                                                          //结构体
//{
// unsigned char RX_Flag;                                                 //接收状态		01248
// unsigned char RX_Len;                                                  //接收到得长度	(二进制模式使用)字符模式使用\0计算
//          char RX_Buffer[60];                                           //接收到得数据缓存
//}UsartRxTypeDef;

//extern UsartRxTypeDef USARTStructure1;	   //串口结构体

char Transchar(char r);

void USART1_Config(void);		  								//串口配置
//void USART1_RX_Buffer_Clear(void); 						//清空接收缓冲区

void USART1_SendByte(u8 Data);								//单字符数据发送
void USART1_SendString(u8* Data,u32 Len);			//多字符发送
void USART1_DMASendString(u8* Data,u32 Len);	//DMA多字符发送


void U1ProtocolAnalysis(void);

uint8_t serial_read(void);
void serial_reset_read_buffer(void);

#ifdef __cplusplus		   //定义对CPP进行C处理 //结束部分
}
#endif

#endif
