/*
 * UART_program.c
 *
 *  Created on: Apr 10, 2023
 *      Author: ziads
 */


#include "std_macros.h"
#include "type_defs.h"
#include "UART_interface.h"
#include "UART_private.h"
#include "UART_cfg.h"



void (*Global_RxPtrToFuncCallBack)(void)=NULL;

void (*Global_TxPtrToFuncCallBack)(void)=NULL;

u8* Global_u8ReciveData=NULL;

void UART_voidInit(void)
{
	/*Enable Tx & Rx to Full Duplex Operation */
	SET_BIT(UCSRB,UCSRB_TXEN);
	SET_BIT(UCSRB,UCSRB_RXEN);

		/* Boud Rate 9600 */
		UBRRL = 51;
}

void UART_voidTransimitData(u8 Copy_u8TransimittedData)
{
	while(READ_BIT(UCSRA,UCSRA_UDRE) == 0);
	/* Assign Data to the Register */
	UDR= Copy_u8TransimittedData;

	while(READ_BIT(UCSRA,UCSRA_TXC) == 0);        /* stuck to end Transimit  */
	SET_BIT(UCSRA,UCSRA_TXC);               /* Clear Flag */
}

void UART_voidTransimitDataAsync(u8 Copy_u8TransimittedData,void(*PtrToFuncTx)(void))
{
	/* chech UDRE buffer register is empty  */
	while( READ_BIT(UCSRA,UCSRA_UDRE) == 0);
	/* Enable the interrupt*/
	SET_BIT(UCSRB,UCSRB_TXCIE);
	/* Send Data */
	UDR = Copy_u8TransimittedData ;
	if(PtrToFuncTx != NULL)
	{
		Global_TxPtrToFuncCallBack = PtrToFuncTx;

	}
}

void UART_voidReceiveData(u8* Ptr_ReceivedData)                    /*u8* Ptr_ReceivedData*/
{
	/*  data is completely recieved */
	while(READ_BIT(UCSRA,UCSRA_RXC) == 0);
	*Ptr_ReceivedData = UDR ;
	// return UDR;
}


void UART_voidReceiveDataAsync(u8* Copy_Pu8ReceiveData, void(*Copy_ptrToFunc)(void))
{
	/* Enable receive complete interrupt */
	SET_BIT(UCSRB,UCSRB_RXCIE);

	/*Enable Global interrupt*/
	SET_BIT(SREG,SREG_I);

	if(Copy_ptrToFunc !=NULL)
	{
		Global_RxPtrToFuncCallBack =Copy_ptrToFunc;
	}

	/*Passing the address of the location to store the recieved data to be global*/
		/*Received data is done by ISR*/
	Global_u8ReciveData = Copy_Pu8ReceiveData;
}

/* ISR For Receiving  */
void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
	/*Getting the recieved data*/
	*Global_u8ReciveData = UDR;

	/*Call the application ISR*/
	Global_RxPtrToFuncCallBack();
}


/* ISR For Transimitting  */
void __vector_15(void) __attribute__((signal));
void __vector_15(void)
{

	Global_TxPtrToFuncCallBack();

}


void UART_voidSendString(char * Copy_String)
 {

		u8 Local_u8Iterator=0;

				 while(Copy_String[Local_u8Iterator]	!=	'#')
				 {
				 UART_voidTransimitData(Copy_String[Local_u8Iterator]);
					 Local_u8Iterator++;
				 }


 }


void UART_voidReceiveString(char * Copy_String)
 {

		u8 Local_u8Iterator=0;

		 // Copy_String[Local_u8Iterator] = UART_voidReceiveData();

				while(Copy_String[Local_u8Iterator] != '#' )
				{
					//Local_u8Iterator++;
					 UART_voidReceiveData(&Copy_String[Local_u8Iterator] );
					 Local_u8Iterator++;
				}

				Copy_String[Local_u8Iterator]='\0';
 }
