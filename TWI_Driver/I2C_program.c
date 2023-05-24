/*
 * I2C_program.c
 *
 *  Created on: Apr 14, 2023
 *      Author: ziads
 */


#include "std_macros.h"
#include "type_defs.h"
#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_cfg.h"


void TWI_voidMasterInit(u8 Copy_u8Address)
{
	/* Set clock to be 400 KHZ*/
	TWBR =2;
	CLR_BIT(TWSR , TWSR_TWPS0);
	CLR_BIT(TWSR , TWSR_TWPS1);

	/* Set Node Address  */
	TWAR = (Copy_u8Address<<1);

	/*Enable Acknowledge Bit*/
	SET_BIT(TWCR,TWCR_TWEA);

	/* Enable TWI Peripheral */
	SET_BIT(TWCR, TWCR_TWEN);
}



void TWI_voidSlaveInit(u8 Copy_u8Address)
{
	/* Set Node Address  */
	TWAR = (Copy_u8Address<<1);

	/*Enable Acknowledge Bit*/
	SET_BIT(TWCR,TWCR_TWEA);

	/* Enable TWI Peripheral */
	SET_BIT(TWCR, TWCR_TWEN);



}

TWI_ErrorState_t TWI_SendStartCondition(void)
{
	TWI_ErrorState_t Local_ErrorState = OK;
	/*Send Start Condition on the Bus */
	SET_BIT(TWCR,TWCR_TWSTA);
	/* Clear interrupt flag to start th previous operation */
	SET_BIT(TWCR,TWCR_TWINT);

	/* pooling over Interrupt Flag till the operation is Done */
	while(READ_BIT(TWCR,TWCR_TWINT)==0);

	if((TWSR & STATUS_MASK) == START_ACK)
	{

	}
	else
	{
		Local_ErrorState= InvalidStartCondition;
	}

	/* Clearing Start Condition Bit */
	CLR_BIT(TWCR,TWCR_TWSTA);
	return Local_ErrorState;
}



TWI_ErrorState_t TWI_SendRepeatedStart(void)
{
	TWI_ErrorState_t Local_ErrorState = OK;
	/*Send Start Condition on the Bus */
	SET_BIT(TWCR,TWCR_TWSTA);
	/* Clear interrupt flag to start th previous operation */
	SET_BIT(TWCR,TWCR_TWINT);

	/* pooling over Interrupt Flag till the operation is Done */
	while(READ_BIT(TWCR,TWCR_TWINT)==0);

	if((TWSR & STATUS_MASK) == REP_START_ACK)
	{

	}
	else
	{
		Local_ErrorState= InvalidRepeatedStart;
	}

	/* Clearing Start Condition Bit */
	CLR_BIT(TWCR,TWCR_TWSTA);
	return Local_ErrorState;

}


TWI_ErrorState_t TWI_SendSlaveAddressWithRead(u8 Copy_u8Address)
{
	TWI_ErrorState_t Local_ErrorState = OK;
	/* Set Value Of Slave Address */
	TWDR = Copy_u8Address<<1;
	/* For Read Request */
	SET_BIT(TWDR, 0);

	/* Clear interrupt flag to start th previous operation */
	SET_BIT(TWCR,TWCR_TWINT);

	/* pooling over Interrupt Flag till the operation is Done */
	while(READ_BIT(TWCR,TWCR_TWINT)==0);

	if((TWSR & STATUS_MASK) == SLAVE_ADD_AND_RD_ACK)
	{

	}
	else
	{
		Local_ErrorState= InvalidSlaveAddressWithRead;
	}


	return Local_ErrorState;

}


TWI_ErrorState_t TWI_SendSlaveAddressWithWrite(u8 Copy_u8Address)
{
	TWI_ErrorState_t Local_ErrorState = OK;
	/* Set Value Of Slave Address */
	TWDR = Copy_u8Address<<1;
	/* For Write Request */
	CLR_BIT(TWDR, 0);

	/* Clear interrupt flag to start th previous operation */
	SET_BIT(TWCR,TWCR_TWINT);

	/* pooling over Interrupt Flag till the operation is Done */
	while(READ_BIT(TWCR,TWCR_TWINT)==0);

	if((TWSR & STATUS_MASK) == SLAVE_ADD_AND_WR_ACK)
	{

	}
	else
	{
		Local_ErrorState= InvalidSlaveAddressWithWrite;
	}


	return Local_ErrorState;
}


TWI_ErrorState_t TWI_SendData(u8 Copy_u8Data)
{
	TWI_ErrorState_t Local_ErrorState = OK;
	/* Set Value Of Transmitted Data  */
	TWDR = Copy_u8Data;

	/* Clear interrupt flag to start the previous operation */
	SET_BIT(TWCR,TWCR_TWINT);

	/* pooling over Interrupt Flag till the operation is Done */
	while(READ_BIT(TWCR,TWCR_TWINT)==0);

	if((TWSR & STATUS_MASK) == MSTR_WR_BYTE_ACK)
	{

	}
	else
	{
		Local_ErrorState= InvalidSendData;
	}


	return Local_ErrorState;


}


TWI_ErrorState_t TWI_ReceiveData(u8* Copy_u8PData)
{
	TWI_ErrorState_t Local_ErrorState = OK;

	/* Polling over the interrupt flag till the end of Receive */
	while(READ_BIT(TWCR,TWCR_TWINT)==1);


	if((TWSR & STATUS_MASK) == MSTR_RD_BYTE_WITH_ACK)
	{
		*Copy_u8PData = TWDR;
	}
	else
	{
		Local_ErrorState= InvalidReceiveData;
	}


	return Local_ErrorState;

}


void TWI_SendStopCondition(void)
{
	/* Enable Stop Condition By Stop Condition Bit  */
	SET_BIT(TWCR,TWCR_TWSTO);

	/* Clear Interrupt Flag to Start the Previous operation */
	SET_BIT(TWCR,TWCR_TWINT);

}
