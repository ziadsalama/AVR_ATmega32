/*
 * SPI_program.c
 *
 *  Created on: Apr 11, 2023
 *      Author: ziads
 */


#include "std_macros.h"
#include "type_defs.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_cfg.h"


void(*Global_PtrToFuncCallBack)(void)=NULL;

void SPI_voidMasterInit()
{
	/* Set to be in Master mode  */
	SET_BIT(SPCR,SPCR_MSTR);

	/*Disable SPI Interrupt */
	CLR_BIT(SPCR,SPCR_SPIE);

	/*Enable SPI*/
	SET_BIT(SPCR,SPCR_SPE);

	/* Data Order--> LSB First  */
	SET_BIT(SPCR,SPCR_DORD);

	/* Clock Polarity --> idle State = LOW */
	CLR_BIT(SPCR,SPCR_CPOL);

	/* Clock Phase --> Sample First  */
	CLR_BIT(SPCR,SPCR_CPHA);

	/* Prescaler --> 16*/
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);

}


void SPI_voidSlaveInit()
{
	/* Set to be in Slave mode  */
		CLR_BIT(SPCR,SPCR_MSTR);

		/*Disable SPI Interrupt */
		CLR_BIT(SPCR,SPCR_SPIE);

		/*Enable SPI*/
		SET_BIT(SPCR,SPCR_SPE);

		/* Data Order--> LSB First  */
		SET_BIT(SPCR,SPCR_DORD);

		/* Clock Polarity --> idle State = LOW */
		CLR_BIT(SPCR,SPCR_CPOL);

		/* Clock Phase --> Sample First  */
		CLR_BIT(SPCR,SPCR_CPHA);


}


u8 SPI_u8Transceive(u8 Copy_TransmittedByte)
{
	/* set the data byte to be transitted*/
	SPDR = Copy_TransmittedByte;
	/*stuck to end transmite */
	while(READ_BIT(SPSR,SPSR_SPIF) == 0);
    /* Received Data  */
	return SPDR ;
}


/*function to transmitted byte and receive a Byte from the slave Async*/
u8 SPI_u8TransceiveAsync(u8 Copy_u8TransmittedByte , void(*PtrToFuncBack)(void))
{
	/*Set the data byte to be transmitted*/
	SPDR=Copy_u8TransmittedByte;

	if(PtrToFuncBack != NULL)
	{
		Global_PtrToFuncCallBack=PtrToFuncBack;
	}
	/*Get the received Data Byte*/
	return SPDR;
}

void __vector_12(void)__attribute__((signal));
void __vector_12(void)
{
	if(Global_PtrToFuncCallBack !=NULL)
	{
		Global_PtrToFuncCallBack();
	}
	else
	{

	}
}
