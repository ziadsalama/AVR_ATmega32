/*
 * EEPROM_program.c
 *
 *  Created on: Apr 26, 2023
 *      Author: ziads
 */


#include "std_macros.h"
#include "type_defs.h"
#include "util/delay.h"
#include "TWI_interface.h"


#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_cfg.h"

void EEPROM_voidWriteDataByte(u8 Copy_u8DataByte , u16 Copy_u16ByteAddress)
{
	u8 Local_u8Address ;
		Local_u8Address= ((ADDRESS_MASK)|(A2<<2) | (u8)(Copy_u16ByteAddress>>8));
	/*Start Condition */
		TWI_StartCondition();

	/* Slave Address to write */
		TWI_SendSLAwithWrite(Local_u8Address);

	/* Master Write Data Byte */
		TWI_SendData((u8)Copy_u16ByteAddress);

	/* Master Write Data Byte */
		TWI_SendData(Copy_u8DataByte);

	/* Stop Condition */
		TWI_StopCondition();

	_delay_ms(10);

}



void EEPROM_voidReadDataByte(u8* Copy_u8PDataByte , u16 Copy_u16ByteAddress)
{
	u8 Local_u8Address ;
	Local_u8Address= ((ADDRESS_MASK)|(A2<<2) | (u8)(Copy_u16ByteAddress>>8));
	/*Start Condition */
	TWI_StartCondition();

	/* Slave Address to write */
	TWI_SendSLAwithWrite(Local_u8Address);

	/* Master Write Data Byte */
	TWI_SendData((u8)Copy_u16ByteAddress);

	/* send repeated start to change order from write to Read */
	TWI_RepeatedStart();

	/*Send EEPROM Slave Address with Write*/
	TWI_SendSLAwithRead(Local_u8Address);

	  /* Master Read Data Byte */
	TWI_ReceiveData(Copy_u8PDataByte);

	/* Stop Condition */
	TWI_StopCondition();

	_delay_ms(10);

}
