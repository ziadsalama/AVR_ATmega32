/*
 * UART_interface.h
 *
 *  Created on: Apr 10, 2023
 *      Author: ziads
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_voidInit(void);
/* Function To Transmit Data Synchronous */
void UART_voidTransimitData(u8 Copy_u8TransimittedData);
/* Function To Transmit Data Asynchronous */
void UART_voidTransimitDataAsync(u8 Copy_u8TransimittedData,void(*PtrToFuncTx)(void));

/* Function To Receive Data Synchronous */
void UART_voidReceiveData(u8* Ptr_ReceivedData);                    /*u8* Ptr_ReceivedData*/

/* Function To Receive Data Asynchronous */
void UART_voidReceiveDataAsync(u8* Copy_Pu8ReceiveData, void(*Copy_ptrToFunc)(void));

/* Function To Send String  */
void UART_voidSendString(char * Copy_String);

/* Function To Receive  String  */
void UART_voidReceiveString(char * Copy_String);


#endif /* UART_INTERFACE_H_ */
