#include "std_macros.h"
#include "type_defs.h"

#include <string.h>

#include "DIO_interface.h"

#include "GIE_interface.h"

#include "UART_interface.h"
#include "UART_config.h"
#include "UART_private.h"

void (*GlobalPtrToFuncRDA)(void) =NULL;
u8 * Global_u8ReceivedData =NULL;

void UART_voidInit( UART_t * PtrToStruct)
{
	DIO_voidSetPinDircetion(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT_FLOAT);
	DIO_voidSetPinDircetion(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT);
	u8 UCSRC_VALUE = 0 ;
	if(PtrToStruct -> Mode_Node == Transfer_Only)
	{
		SET_BIT(UCSRB,TXEN);
		CLR_BIT(UCSRB,RXEN);
	}
	else if (PtrToStruct -> Mode_Node == Recieve_Only)
	{
		CLR_BIT(UCSRB,TXEN);
		SET_BIT(UCSRB,RXEN);
	}
	else if (PtrToStruct -> Mode_Node == Transfer_Recieve )
	{
		SET_BIT(UCSRB,TXEN);
		SET_BIT(UCSRB,RXEN);
	}
	if (PtrToStruct -> Data_Size == Nine_BITS)
	{
		SET_BIT(UCSRB,UCSZ2);
	}
	/*Accessing UCSRC Register*/
	SET_BIT(UCSRC_VALUE,URSEL);

	if(PtrToStruct ->Partiy == No_Parity)
	{
		CLR_BIT(UCSRC_VALUE,UPM0);
		CLR_BIT(UCSRC_VALUE,UPM1);
	}
	else if(PtrToStruct ->Partiy == Even_Parity)
	{
		CLR_BIT(UCSRC_VALUE,UPM0);
		SET_BIT(UCSRC_VALUE,UPM1);
	}
	else if(PtrToStruct ->Partiy == Odd_Parity)
	{
		SET_BIT(UCSRC_VALUE,UPM0);
		SET_BIT(UCSRC_VALUE,UPM1);
	}
	if(PtrToStruct ->Stop_Bits == One_BIT)
	{
		CLR_BIT(UCSRC_VALUE,USBS);
	}
	else if(PtrToStruct ->Stop_Bits == Two_BITS)
	{
		SET_BIT(UCSRC_VALUE,USBS);
	}
	if(PtrToStruct -> Data_Size == Five_BITS)
	{
		CLR_BIT(UCSRC_VALUE,UCSZ0);
		CLR_BIT(UCSRC_VALUE,UCSZ1);
	}
	else if (PtrToStruct -> Data_Size == Six_BITS)
	{
		SET_BIT(UCSRC_VALUE,UCSZ0);
		CLR_BIT(UCSRC_VALUE,UCSZ1);
	}
	else if (PtrToStruct -> Data_Size == Seven_BITS)
	{
		CLR_BIT(UCSRC_VALUE,UCSZ0);
		SET_BIT(UCSRC_VALUE,UCSZ1);
	}
	else if (PtrToStruct -> Data_Size == Eight_BITS)
	{
		SET_BIT(UCSRC_VALUE,UCSZ0);
		SET_BIT(UCSRC_VALUE,UCSZ1);
	}
	else if (PtrToStruct -> Data_Size == Nine_BITS)
	{
		SET_BIT(UCSRC_VALUE,UCSZ0);
		SET_BIT(UCSRC_VALUE,UCSZ1);
	}
	if(PtrToStruct -> Async_Sync == Async_Mode)
	{
		CLR_BIT(UCSRC_VALUE,UMSEL);
	}
	else if(PtrToStruct -> Async_Sync ==Sync_Mode)
	{
		SET_BIT(UCSRC_VALUE,UMSEL);
	}
	UCSRC = UCSRC_VALUE;

	UBRRL = BaudRate;
}
void UART_void_TransmitDataSync(u8 * Copy_u8Data)
{
	/*Make sure that UDR is empty*/
	while(READ_BIT(UCSRA,UDRE)==0);
	UDR=*Copy_u8Data;
	/*Polling till the end of transmission*/
	while(READ_BIT(UCSRA,TXC)==0);
	/*Clear end of transmission flag*/
	SET_BIT(UCSRA,TXC);
}
//void UART_void_TransmitDataAsync(u8 Copy_u8Data , void (*Copy_PtrToFuncTDA)(void))
//{
//
//}
void  UART_void_ReceiveDataSync(u8 * Copy_u8Data)
{
	/*make sure that data is completely recieved*/
	while(READ_BIT(UCSRA,RXC)==0);
	*Copy_u8Data = UDR;
}
void UART_voidReceiveAsync(u8 * Copy_pu8RecievedData,void (*Copy_ptrToFuncRDA)(void))
{
	/*Enable Receive Complete Interrupt*/
	SET_BIT(UCSRB,RXCIE);
	/*Enable Global Interrupt*/
	GIE_voidEnable();
	if (Copy_ptrToFuncRDA!=NULL)
	{
		GlobalPtrToFuncRDA = Copy_ptrToFuncRDA;
	}
	/*Passing the Address of the location to store the received  data to be global*/
	/*Received Data is handled by ISR*/
	Global_u8ReceivedData = Copy_pu8RecievedData;
}
void UART_voidSendString(u8 * Copy_u8PtrToStringSS)
{
	while(* Copy_u8PtrToStringSS)
	{
		UART_void_TransmitDataSync(Copy_u8PtrToStringSS++);
	}
//	u8 Local_u8Iterator=0;
//	for(Local_u8Iterator =0 ; Local_u8Iterator < strlen(Copy_u8PtrToStringSS) ; Local_u8Iterator++)
//	{
//		/*Make sure that UDR is empty*/
//		while(READ_BIT(UCSRA,UDRE)==0);
//		/*Send String to UDR*/
//		UDR = Copy_u8PtrToStringSS[Local_u8Iterator];
//	}
}
//u8 UART_voidReceiveString(u8 * Copy_u8PtrToStringRS)
//{
//	u8 i=0;
//
//	Copy_u8PtrToStringRS[i]=UART_void_ReceiveDataSync();
//
//	while(Copy_u8PtrToStringRS[i] != '#')
//	{
//		i++;
//		Copy_u8PtrToStringRS[i]=UART_void_ReceiveDataSync();
//	}
//	Copy_u8PtrToStringRS[i] = '\0';
//}
void UART_voidgetStringFromUser(char* buffer, int bufferLength) {
    int i = 0;
    char c;
    while (i < bufferLength - 1) {
        UART_void_ReceiveDataSync(&c); // Receive a character using UART
        if (c == '\n' || c == '\r') {
            break; // Break if Enter key is pressed
        }
        buffer[i] = c;
        i++;
    }
    buffer[i] = '\0'; // Null-terminate the string
}
void USART_voidReciveString(u8 *Copy_u8String, u8 Copy_u8Size)
{
	u8 Local_u8Itirator = 0;
	char Local_u8Receive;
	while(Local_u8Itirator < Copy_u8Size -1)
	{
		Local_u8Receive = USART_u8ReciveSync();
		if (Local_u8Receive == '\n')
		{
			break;
		}
		Copy_u8String[Local_u8Itirator] = Local_u8Receive;
		Local_u8Itirator++;
	}
}
u8 USART_u8ReciveSync(void)
{
	/*polling*/
	while((READ_BIT(UCSRA, RXC)) == 0);
	return UDR;
}
void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
    /*Getting the received Data*/
	*Global_u8ReceivedData = UDR;

	/*Call the application ISR*/
	GlobalPtrToFuncRDA();
}

