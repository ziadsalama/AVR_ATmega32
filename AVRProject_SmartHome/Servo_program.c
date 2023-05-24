
#ifndef SERVO_PROGRAM_C_
#define SERVO_PROGRAM_C_

#include "std_macros.h"
#include "type_defs.h"

#include "DIO_interface.h"

#include "Servo_interface.h"
#include "Servo_private.h"
#include "Servo_config.h"

void Servo_voidStart(u8 Copy_u16Channel)
{
	switch(Copy_u16Channel)
	{
	case OUTPUT_COMPARE_A :
		DIO_voidSetPinDircetion(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT);
		break;
	case OUTPUT_COMPARE_B :
		DIO_voidSetPinDircetion(DIO_PORTD,DIO_PIN4,DIO_PIN_OUTPUT);
		break;
	}
}
void Servo_voidSetAngle( u8 Copy_u16Channel , u16 Copy_u16Angle)
{
	u16 MappingValueOfAngle = 0 ;
	MappingValueOfAngle =  ( 750 +  ( (175/18) * Copy_u16Angle) ) ;
	if(Copy_u16Channel == OUTPUT_COMPARE_A)
	{
		OCR1AL = MappingValueOfAngle;
	}
	else if(Copy_u16Channel == OUTPUT_COMPARE_B)
	{
		OCR1BL = MappingValueOfAngle;
	}
}

#endif /* SERVO_PROGRAM_C_ */
