/*====================================================================================================*/
/*====================================================================================================*/
#include "drivers\stm32f1_system.h"
#include "drivers\stm32f1_usart.h"
#include "algorithms\algorithm_string.h"

#include "module_serial.h"
/*====================================================================================================*/
/*====================================================================================================*/
#define UARTx                       USART1
#define UARTx_CLK_ENABLE()          RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE)
#define UARTx_IRQn                  USART1_IRQn

#define UARTx_TX_PIN                GPIO_Pin_9
#define UARTx_TX_GPIO_PORT          GPIOA

#define UARTx_RX_PIN                GPIO_Pin_10
#define UARTx_RX_GPIO_PORT          GPIOA

#define UARTx_BAUDRATE              115200
#define UARTx_BYTESIZE              USART_WordLength_8b
#define UARTx_STOPBITS              USART_StopBits_1
#define UARTx_PARITY                USART_Parity_No
#define UARTx_HARDWARECTRL          USART_HardwareFlowControl_None
#define UARTx_MODE                  USART_Mode_Rx | USART_Mode_Tx
/*====================================================================================================*/
/*====================================================================================================*
**函數 : Serial_Config
**功能 : Serial Config
**輸入 : None
**輸出 : None
**使用 : Serial_Config();
**====================================================================================================*/
/*====================================================================================================*/
void Serial_Config( void )
{
  GPIO_InitTypeDef GPIO_InitStruct;
  USART_InitTypeDef UART_InitStruct;
//  NVIC_InitTypeDef NVIC_InitStruct;

  /* UART Clk ******************************************************************/
  UARTx_CLK_ENABLE();

  /* UART Pin ******************************************************************/
  GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_AF_PP;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

  GPIO_InitStruct.GPIO_Pin   = UARTx_TX_PIN;
  GPIO_Init(UARTx_TX_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

  GPIO_InitStruct.GPIO_Pin   = UARTx_RX_PIN;
  GPIO_Init(UARTx_RX_GPIO_PORT, &GPIO_InitStruct);

  /* UART IT *******************************************************************/
//  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
//  NVIC_InitStruct.NVIC_IRQChannel                   = UARTx_IRQn;
//  NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x000F;
//  NVIC_InitStruct.NVIC_IRQChannelSubPriority        = 0;
//  NVIC_InitStruct.NVIC_IRQChannelCmd                = ENABLE;
//  NVIC_Init(&NVIC_InitStruct);

  /* UART Init *****************************************************************/
  UART_InitStruct.USART_BaudRate            = UARTx_BAUDRATE;
  UART_InitStruct.USART_WordLength          = UARTx_BYTESIZE;
  UART_InitStruct.USART_StopBits            = UARTx_STOPBITS;
  UART_InitStruct.USART_Parity              = UARTx_PARITY;
  UART_InitStruct.USART_HardwareFlowControl = UARTx_HARDWARECTRL;
  UART_InitStruct.USART_Mode                = UARTx_MODE;
  USART_Init(UARTx, &UART_InitStruct);

  /* UART Enable ***************************************************************/
//  USART_ITConfig(UARTx, USART_IT_RXNE, ENABLE);
  USART_Cmd(UARTx, ENABLE);
  USART_ClearFlag(UARTx, USART_FLAG_TC);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : Serial_SendByte
**功能 : Send Byte
**輸入 : SendByte
**輸出 : None
**使用 : Serial_SendByte('A');
**====================================================================================================*/
/*====================================================================================================*/
void Serial_SendByte( uint8_t sendByte )
{
  UART_SendByte(UARTx, &sendByte);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : Serial_SendData
**功能 : Send Data
**輸入 : *sendData, lens
**輸出 : None
**使用 : Serial_SendData(sendData, lens);
**====================================================================================================*/
/*====================================================================================================*/
void Serial_SendData( uint8_t *sendData, uint16_t lens )
{
  UART_SendData(UARTx, sendData, lens);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : Serial_SendStr
**功能 : Send String
**輸入 : *pWord
**輸出 : None
**使用 : Serial_SendStr("Hellow World!");
**====================================================================================================*/
/*====================================================================================================*/
void Serial_SendStr( char *pWord )
{
  while(*pWord != '\0') {
    UART_SendByte(UARTx, (uint8_t*)pWord++);
  }
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : Serial_SendNum
**功能 : Send Number
**輸入 : type, lens, sendNum
**輸出 : None
**使用 : Serial_SendNum(Type_D, 6, 1024);
**====================================================================================================*/
/*====================================================================================================*/
void Serial_SendNum( StringType type, uint8_t lens, int32_t sendNum )
{
  char tmpStr[32] = {0};
  char *pWord = tmpStr;

  num2Str(type, lens, tmpStr, sendNum);

  while(*pWord != '\0') {
    UART_SendByte(UARTx, (uint8_t*)pWord++);
  }
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : Serial_RecvByte
**功能 : Recv Byte
**輸入 : *recvByte
**輸出 : None
**使用 : recvByte = Serial_RecvByte();
**====================================================================================================*/
/*====================================================================================================*/
uint8_t Serial_RecvByte( void )
{
  uint8_t recvByte = 0;
  UART_RecvByte(UARTx, &recvByte);
  return recvByte;
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : Serial_RecvData
**功能 : Recv Data
**輸入 : *recvData, lens
**輸出 : None
**使用 : Serial_RecvData(recvData, lens);
**====================================================================================================*/
/*====================================================================================================*/
void Serial_RecvData( uint8_t *recvData, uint16_t lens )
{
  UART_RecvData(UARTx, recvData, lens);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : Serial_RecvDataWTO
**功能 : Recv Data Wait Timeout
**輸入 : *recvData, lens, timeoutMs
**輸出 : state
**使用 : state = Serial_RecvDataWTO(recvData, lens, timeoutMs);
**====================================================================================================*/
/*====================================================================================================*/
int8_t Serial_RecvDataWTO( uint8_t *recvData, uint16_t lens, int32_t timeoutMs )
{
  return UART_RecvDataWTO(UARTx, recvData, lens, timeoutMs);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : Serial_RecvStr
**功能 : Recv String
**輸入 : *pWord
**輸出 : None
**使用 : Serial_RecvStr(recvStr);
**====================================================================================================*/
/*====================================================================================================*/
void Serial_RecvStr( char *pWord )
{
  do {
    UART_RecvByte(UARTx, (uint8_t*)pWord++);
  } while(*(pWord-1) != '\0');
  *pWord = '\0';
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : Serial_RecvStrWTO
**功能 : Recv String Wait Timeout
**輸入 : *pWord, timeoutMs
**輸出 : State
**使用 : Serial_RecvStrWTO(RecvStr, 200);
**====================================================================================================*/
/*====================================================================================================*/
int8_t Serial_RecvStrWTO( char *pWord, int32_t timeoutMs )
{
  int8_t state = ERROR;

  do {
    state = UART_RecvByteWTO(UARTx, (uint8_t*)pWord++, timeoutMs);
    if(state == ERROR)
      return ERROR;
  } while(*(pWord-1) != '\0');
  *pWord = '\0';

  return SUCCESS;
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : Serial_SendDataMATLAB
**功能 : Send Data to MATLAB 
**輸入 : *sendData, lens
**輸出 : None
**使用 : Serial_SendDataMATLAB(sendData, 10); // int16 * 10 data
**====================================================================================================*/
/*====================================================================================================*/
void Serial_SendDataMATLAB( int16_t *sendData, uint8_t lens )
{
  uint8_t tmpData[32] = {0};  // tmpData lens >= 2 * lens + 4
  uint8_t *ptrData = tmpData;
  uint8_t dataBytes = lens << 1;
  uint8_t dataLens = dataBytes + 4;
  uint8_t count = 0;
  uint16_t tmpSum = 0;

  tmpData[0] = 'S';
  while(count < dataBytes) {
    tmpData[count+1] = Byte8H(sendData[count >> 1]);
    tmpData[count+2] = Byte8L(sendData[count >> 1]);
    count = count + 2;
  }
  for(uint8_t i = 0; i < dataBytes; i++)
    tmpSum += tmpData[i+1];
  tmpData[dataLens - 3] = (uint8_t)(tmpSum & 0x00FF);
  tmpData[dataLens - 2] = '\r';
  tmpData[dataLens - 1] = '\n';

  do {
    Serial_SendByte(*ptrData++);
  } while(--dataLens);
}
/*====================================================================================================*/
/*====================================================================================================*/
int fputc( int ch, FILE *f )
{
  UARTx->DR = ((uint8_t)ch & (uint16_t)0x01FF);
  while(!(UARTx->SR & USART_FLAG_TC));
  return (ch);
}
int fgetc( FILE *f )
{
  while(!(UARTx->SR & USART_FLAG_RXNE));
  return (uint16_t)(UARTx->DR & (uint16_t)0x01FF);
}
/*====================================================================================================*/
/*====================================================================================================*/
