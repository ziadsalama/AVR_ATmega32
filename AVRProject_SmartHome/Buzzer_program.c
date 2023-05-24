
#include "std_macros.h"
#include "type_defs.h"

#include "DIO_interface.h"

#include <util/delay.h>

#include "Buzzer_inteface.h"
#include "Buzzer_Config.h"
#include "Buzzer_private.h"


void Buzzer_voidInit(u8 Copy_u8Port_ID , u8 Copy_u8Pin_ID)
{
	DIO_voidSetPinDircetion(Copy_u8Port_ID,Copy_u8Pin_ID,DIO_PIN_OUTPUT);
}

void Buzzer_voidToneSelector(u32 Copy_u8Tone,u8 Copy_u8Port_ID , u8 Copy_u8Pin_ID)
{
  switch(Copy_u8Tone)
  {
  case DO1 :
	  DIO_voidSetPinValue(Copy_u8Port_ID,Copy_u8Pin_ID,DIO_HIGH_PIN);
	  _delay_ms(DO1);
	  DIO_voidSetPinValue(Copy_u8Port_ID,Copy_u8Pin_ID,DIO_LOW_PIN);
	  break;
  case RE :
	  DIO_voidSetPinValue(Copy_u8Port_ID,Copy_u8Pin_ID,DIO_HIGH_PIN);
	  _delay_ms(RE);
	  DIO_voidSetPinValue(Copy_u8Port_ID,Copy_u8Pin_ID,DIO_LOW_PIN);
	  break;
  case MI:
	  DIO_voidSetPinValue(Copy_u8Port_ID,Copy_u8Pin_ID,DIO_HIGH_PIN);
	  _delay_ms(MI);
	  DIO_voidSetPinValue(Copy_u8Port_ID,Copy_u8Pin_ID,DIO_LOW_PIN);
	  break;
  case FA:
	  DIO_voidSetPinValue(Copy_u8Port_ID,Copy_u8Pin_ID,DIO_HIGH_PIN);
	  _delay_ms(FA);
	  DIO_voidSetPinValue(Copy_u8Port_ID,Copy_u8Pin_ID,DIO_LOW_PIN);
	  break;
  case SO:
	  DIO_voidSetPinValue(Copy_u8Port_ID,Copy_u8Pin_ID,DIO_HIGH_PIN);
	  _delay_ms(SO);
	  DIO_voidSetPinValue(Copy_u8Port_ID,Copy_u8Pin_ID,DIO_LOW_PIN);
	  break;
  case LA:
	  DIO_voidSetPinValue(Copy_u8Port_ID,Copy_u8Pin_ID,DIO_HIGH_PIN);
	  _delay_ms(LA);
	  DIO_voidSetPinValue(Copy_u8Port_ID,Copy_u8Pin_ID,DIO_LOW_PIN);
	  break;
  case TI:
	  DIO_voidSetPinValue(Copy_u8Port_ID,Copy_u8Pin_ID,DIO_HIGH_PIN);
	  _delay_ms(TI);
	  DIO_voidSetPinValue(Copy_u8Port_ID,Copy_u8Pin_ID,DIO_LOW_PIN);
	  break;
  case DO2:
	  DIO_voidSetPinValue(Copy_u8Port_ID,Copy_u8Pin_ID,DIO_HIGH_PIN);
	  _delay_ms(DO2);
	  DIO_voidSetPinValue(Copy_u8Port_ID,Copy_u8Pin_ID,DIO_LOW_PIN);
	  break;
  }
}
void Buzzer_voidSafetyAlarm(u8 Copy_u8Port_ID , u8 Copy_u8Pin_ID)
{
	DIO_voidSetPinValue(Copy_u8Port_ID,Copy_u8Pin_ID,DIO_HIGH_PIN);
	_delay_ms(3000);
	DIO_voidSetPinValue(Copy_u8Port_ID,Copy_u8Pin_ID,DIO_LOW_PIN);
}

void Buzzer_voidSuccessAlarm(u8 Copy_u8Port_ID , u8 Copy_u8Pin_ID)
{
	DIO_voidSetPinValue(Copy_u8Port_ID,Copy_u8Pin_ID,DIO_HIGH_PIN);
	_delay_ms(100);
	DIO_voidSetPinValue(Copy_u8Port_ID,Copy_u8Pin_ID,DIO_LOW_PIN);
	_delay_ms(50);
//	DIO_voidSetPinValue(Copy_u8Port_ID,Copy_u8Pin_ID,DIO_HIGH_PIN);
//	_delay_ms(50);
//	DIO_voidSetPinValue(Copy_u8Port_ID,Copy_u8Pin_ID,DIO_LOW_PIN);
//	_delay_ms(50);
}
