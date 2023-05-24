
#include "std_macros.h"
#include "type_defs.h"


#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_CFG.h"

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

#include <util/delay.h>


static u8 i =0;

void LCD_voidLCDInit(void)
{
	DIO_voidSetPinDircetion(LCD_CMD_PORT,RS_PIN,DIO_PIN_OUTPUT); //Rs
	DIO_voidSetPinDircetion(LCD_CMD_PORT,R_or_W_PIN,DIO_PIN_OUTPUT); //R/W
	DIO_voidSetPinDircetion(LCD_CMD_PORT,E_PIN,DIO_PIN_OUTPUT); //E
#if (LCD_MODE ==_8_BIT)
	DIO_voidSetPortDirection(LCD_DATA_PORT,DIO_OUTPUT_PORT); //data
	_delay_ms(40);
	LCD_voidLCDSendCommand(0x38);    //function set
	_delay_us(100);
	LCD_voidLCDSendCommand(0x0F);    //Display on/off
	_delay_us(100);
	LCD_voidLCDSendCommand(0x01);    //Display
#elif (LCD_MODE ==_4_BIT)
	DIO_voidSetPortDirection(LCD_DATA_PORT,DIO_OUTPUT_PORT);
	_delay_ms(30);
	LCD_voidLCDSendCommand(0x20);          //function set
	LCD_voidLCDSendCommand(0x20);
	LCD_voidLCDSendCommand(0xc0);
	_delay_us(100);
	LCD_voidLCDSendCommand(0x00);         //Display on/off
	LCD_voidLCDSendCommand(0xf0);
	_delay_us(100);
	LCD_voidLCDSendCommand(0x00);         //Display
	LCD_voidLCDSendCommand(0x10);

	i =1;

#endif
}

void LCD_voidLCDSendCommand(u8 Copy_u8CMD)
{
//	u8 CMD1 = 0;
//	CMD1=Copy_u8CMD;
	DIO_voidSetPinValue(LCD_CMD_PORT,RS_PIN,DIO_LOW_PIN);
	DIO_voidSetPinValue(LCD_CMD_PORT,R_or_W_PIN,DIO_LOW_PIN);
#if (LCD_MODE == _8_BIT)
	DIO_u8SetPortValue(LCD_DATA_PORT,Copy_u8CMD);

	DIO_voidSetPinValue(LCD_CMD_PORT,E_PIN,DIO_HIGH_PIN);
	_delay_ms(10);
	DIO_voidSetPinValue(LCD_CMD_PORT,E_PIN,DIO_LOW_PIN);
#elif (LCD_MODE == _4_BIT)
	u8 CMD1 = Copy_u8CMD ;
	CMD1=((CMD1)&0xF0);
	DIO_u8SetPortValue(LCD_DATA_PORT,CMD1);
	DIO_voidSetPinValue(LCD_CMD_PORT,E_PIN,DIO_HIGH_PIN);
	_delay_us(100);
	DIO_voidSetPinValue(LCD_CMD_PORT,E_PIN,DIO_LOW_PIN);
	if (i)
	{
		Copy_u8CMD=((Copy_u8CMD<<4)&0xF0);
		DIO_u8SetPortValue(LCD_DATA_PORT,Copy_u8CMD);
		DIO_voidSetPinValue(LCD_CMD_PORT,E_PIN,DIO_HIGH_PIN);
		_delay_us(100);
		DIO_voidSetPinValue(LCD_CMD_PORT,E_PIN,DIO_LOW_PIN);
	}

#endif
}
void LCD_voidLCDSendCharacter(u8 Copy_u8Character)
{
	u8 Character1 = 0;
	Character1=Copy_u8Character;
	DIO_voidSetPinValue(LCD_CMD_PORT,RS_PIN,DIO_HIGH_PIN);
	DIO_voidSetPinValue(LCD_CMD_PORT,R_or_W_PIN,DIO_LOW_PIN);

#if (LCD_MODE == _8_BIT)
	DIO_u8SetPortValue(LCD_DATA_PORT,Copy_u8Character);

	DIO_voidSetPinValue(LCD_CMD_PORT,E_PIN,DIO_HIGH_PIN);
	_delay_ms(10);
	DIO_voidSetPinValue(LCD_CMD_PORT,E_PIN,DIO_LOW_PIN);
#elif (LCD_MODE == _4_BIT)
	(Character1=(Character1)&0xF0);
	DIO_u8SetPortValue(LCD_DATA_PORT,Character1);
	DIO_voidSetPinValue(LCD_CMD_PORT,E_PIN,DIO_HIGH_PIN);
	_delay_us(100);
	DIO_voidSetPinValue(LCD_CMD_PORT,E_PIN,DIO_LOW_PIN);
	Copy_u8Character=((Copy_u8Character<<4)&0xF0);
	DIO_u8SetPortValue(LCD_DATA_PORT,Copy_u8Character);
	DIO_voidSetPinValue(LCD_CMD_PORT,E_PIN,DIO_HIGH_PIN);
	_delay_us(100);
	DIO_voidSetPinValue(LCD_CMD_PORT,E_PIN,DIO_LOW_PIN);
#endif
}

void LCD_voidSendString(u8 Array[])
{
	u8 i=0;
	while(Array[i] != '\0')
	{
		LCD_voidLCDSendCharacter(Array[i]);
		i++;
	}

}

u8 LCD_u8GoToRowCol(u8 Copy_u8Row, u8 Copy_u8Colum)
{
	u8 Local_u8ErrorState =0 ;

	u8 Local_u8DDRAMAddress;

	if( (Copy_u8Row ==0 || Copy_u8Row==1) && ( Copy_u8Colum >=0 && Copy_u8Colum<16))
	{
		if(Copy_u8Row ==0)
		{
			Local_u8DDRAMAddress = Copy_u8Colum ;
		}
		else if(Copy_u8Row ==1)
		{
			Local_u8DDRAMAddress = Copy_u8Colum + 0x40  ;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}

	SET_BIT(Local_u8DDRAMAddress,7);

	LCD_voidLCDSendCommand(Local_u8DDRAMAddress);

	return Local_u8ErrorState  ;
}

void LCD_voidSendSpecialCharacter(u8 * Copy_pu8Pattern , u8 Copy_u8Location , u8 Copy_u8Row , u8 Copy_u8Colum)
{
	/*Local variable to calculate the address of CGRAM location*/

	u8 Local_u8CGRAMAddress;

	u8 Local_u8PatternIterator;

	Local_u8CGRAMAddress = Copy_u8Location *8 ;

	SET_BIT(Local_u8CGRAMAddress,6);
	/*setting address counter to the target location of CGRAM*/
	LCD_voidLCDSendCommand(Local_u8CGRAMAddress);
	for(Local_u8PatternIterator=0;Local_u8PatternIterator<8;Local_u8PatternIterator++)
	{
		LCD_voidLCDSendCharacter(Copy_pu8Pattern[Local_u8PatternIterator]);
	}

	LCD_u8GoToRowCol(  Copy_u8Row ,  Copy_u8Colum);

	LCD_voidLCDSendCharacter(Copy_u8Location);
}

void LCD_voidSendNumber(u32 Copy_u32Number)
{
	s8 arr[16];
	sprintf(arr,"%d",Copy_u32Number);
	LCD_voidSendString(arr);
}
void LCD_voidStop(void)
{
	LCD_voidLCDSendCommand(0x01);
}





