/*
 * UART_interface.h
 *
 *  Created on: Apr 14, 2023
 *      Author: moham
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

typedef struct
{
	u8 Partiy;
	u8 Stop_Bits;
	u8 Mode_Node;
	u8 Data_Size;
	u8 Async_Sync;
}UART_t;



#define No_Parity   0
#define Even_Parity 1
#define Odd_Parity  2

#define One_BIT      0
#define Two_BITS     1

#define Transfer_Only    0
#define Recieve_Only     1
#define Transfer_Recieve 2

#define Five_BITS     0
#define Six_BITS      1
#define Seven_BITS    2
#define Eight_BITS    3
#define Nine_BITS     4

#define Async_Mode    0
#define Sync_Mode     1
/*This function shall Initialize UART peripheral*/
void UART_voidInit( UART_t * PtrToStruct);
/*This function shall transmit data byte*/
void UART_void_TransmitDataSync(u8 * Copy_u8Data);
/*This function shall transmit data byte*/
//void UART_void_TransmitDataAsync(u8 Copy_u8Data , void (*Copy_PtrToFuncTDA)(void));
/*This function shall receive data byte*/
void  UART_void_ReceiveDataSync(u8 * Copy_u8Data);
/*This function shall receive a data byte Async*/
void UART_voidReceiveAsync(u8 * Copy_pu8RecievedData,void (*Copy_ptrToFuncRDA)(void));
/*This function Shall Send String */
void UART_voidSendString(u8 * Copy_u8PtrToStringSS);
/*This function Shall Receive String */
u8 UART_voidReceiveString(u8 * Copy_u8PtrToStringRS);

void UART_voidgetStringFromUser(char* buffer, int bufferLength) ;

u8 USART_u8ReciveSync(void);

void USART_voidReciveString(u8 *Copy_u8String, u8 Copy_u8Size);

#endif /* UART_INTERFACE_H_ */
