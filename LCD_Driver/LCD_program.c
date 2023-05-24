/*
 * LCD_program.c
 *
 *  Created on: Mar 28, 2023
 *      Author: ziads
 */


#include "std_macros.h"
#include "type_defs.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_cfg.h"

void LCD_void_Init(void)
{
	DIO_voidSetPortDirection(LCD_DATA_PORT, DIO_PORT_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT , RS_PIN , DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT , RW_PIN , DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT , EN_PIN , DIO_PIN_OUTPUT);
	_delay_ms(30);
	LCD_voidSendCommand(0x38);            /*   LCD_voidSendCommand(0x3c);     lw hnsha3'al el 5*10 */
	_delay_ms(100);
	LCD_voidSendCommand(0x0f);
	_delay_ms(100);
	LCD_voidSendCommand(0x01);
}


void LCD_voidSendCommand(u8 command)
{
	DIO_voidSetPinValue(LCD_CONTROL_PORT,RS_PIN,DIO_LOW_PIN);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,RW_PIN,DIO_LOW_PIN);

	DIO_u8SetPortValue(LCD_DATA_PORT,command);

	DIO_voidSetPinValue(LCD_CONTROL_PORT,EN_PIN,DIO_HIGH_PIN);
	_delay_ms(30);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,EN_PIN,DIO_LOW_PIN);


}



void LCD_voidSendCharacter(u8 character)
{

	DIO_voidSetPinValue(LCD_CONTROL_PORT,RS_PIN,DIO_HIGH_PIN);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,RW_PIN,DIO_LOW_PIN);

	DIO_u8SetPortValue(LCD_DATA_PORT,character);

	DIO_voidSetPinValue(LCD_CONTROL_PORT,EN_PIN,DIO_HIGH_PIN);
	_delay_ms(30);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,EN_PIN,DIO_LOW_PIN);



}



void LCD_voidSendString(u8 arr[])
{

u8 i=0;
while(arr[i])
{
	LCD_voidSendCharacter(arr[i]);
	i++;
}

}


u8 LCD_u8GoToRowCol(u8 copy_u8Row, u8 copy_u8Column)
{
u8 local_u8ErrorState = 0 ;
u8 Local_u8DDDRAMAddress;
	if((copy_u8Row==0  || copy_u8Row==1)   && (copy_u8Column>=0  &&  copy_u8Column<=15))
	{
		if(copy_u8Row==0)
		{
			Local_u8DDDRAMAddress=copy_u8Column;
		}

		else if (copy_u8Row==1)
		{
			Local_u8DDDRAMAddress=copy_u8Column + 0x40;
		}
	}

	else
	{
		local_u8ErrorState=1;

	}
	SET_BIT(Local_u8DDDRAMAddress,7);

	LCD_voidSendCommand(Local_u8DDDRAMAddress);
	return local_u8ErrorState;
}



void LCD_voidSendSpecialCharacter(u8* copy_pu8pattern, u8 copy_u8location,u8 copy_u8Row, u8 copy_u8Column )

{	/* local variable to iterating on bytes of pattern */
	u8 Local_u8patternIterator;
	/* local var to calculate the address of the CGRam location */
	u8 Local_u8CGRAMADDRESS;

	Local_u8CGRAMADDRESS= copy_u8location*8;

	SET_BIT(Local_u8CGRAMADDRESS,6);

	/*setting address counter to the target location of CGRam */
	LCD_voidSendCommand(Local_u8CGRAMADDRESS);
	/* sending the pattern to the target location in CGRAM  */
	for(Local_u8patternIterator = 0 ; Local_u8patternIterator < 8 ; Local_u8patternIterator++)
	{
		LCD_voidSendCharacter(copy_pu8pattern[Local_u8patternIterator]);
	}
	/* Turning back to DDRAM */
	LCD_u8GoToRowCol(copy_u8Row,copy_u8Column);

	/* displaying the special character  */
	/* DDRAM jumps to the location of CGRAM to display the pattern  */
	LCD_voidSendCharacter(copy_u8location);
}



void lcd_write_number(u32 number) {
	s8 i=0 ;
	u8 digit[10]={0};
	while(number>0)
	{
		digit[i] = number%10;
	    number = number/10;
	    i++;
	}
	i--;

	while(i>=0)
	{
		LCD_voidSendCharacter(digit[i]+48);
		i--;
	}
}
/*
for(; i>=0 ; i--)
		{
			LCD_voidSendCharacter(digit[i]+48);
		}*/
