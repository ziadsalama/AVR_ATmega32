/*
 * STEPPER_program.c
 *
 *  Created on: Apr 2, 2023
 *      Author: ziads
 */

#include "std_macros.h"
#include "type_defs.h"
#include <util/delay.h>
#include "DIO_interface.h"

#include "STEPPER_interface.h"
#include "STEPPER_private.h"
#include "STEPPER_cfg.h"





void STEPPER_voidInit()
{
	DIO_voidSetPinDirection(STEPPER_PORT , STEPPER_PIN1 , DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(STEPPER_PORT , STEPPER_PIN2 , DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(STEPPER_PORT , STEPPER_PIN3 , DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(STEPPER_PORT , STEPPER_PIN4 , DIO_PIN_OUTPUT);


}

void STEPPER_voidForward()
{
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN1 ,DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN2 ,DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN3 ,DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN4 ,DIO_LOW_PIN);
	_delay_ms(100);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN1 ,DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN2 ,DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN3 ,DIO_LOW_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN4 ,DIO_HIGH_PIN);
	_delay_ms(100);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN1 ,DIO_LOW_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN2 ,DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN3 ,DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN4 ,DIO_HIGH_PIN);
	_delay_ms(100);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN1 ,DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN2 ,DIO_LOW_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN3 ,DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN4 ,DIO_HIGH_PIN);
	_delay_ms(100);


}

void STEPPER_voidBackward()
{

	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN1 ,DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN2 ,DIO_LOW_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN3 ,DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN4 ,DIO_HIGH_PIN);
	_delay_ms(100);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN1 ,DIO_LOW_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN2 ,DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN3 ,DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN4 ,DIO_HIGH_PIN);
	_delay_ms(100);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN1 ,DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN2 ,DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN3 ,DIO_LOW_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN4 ,DIO_HIGH_PIN);
	_delay_ms(100);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN1 ,DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN2 ,DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN3 ,DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN4 ,DIO_LOW_PIN);
	_delay_ms(100);


}



void STEPPER_voidCWWithAngel(u8 Copy_u8Degree)
{
	u8 Local_u8Iterator;
	for(Local_u8Iterator=1;Local_u8Iterator<(Copy_u8Degree/0.703125);Local_u8Iterator++)
	{
		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN1 ,DIO_LOW_PIN);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN2 ,DIO_HIGH_PIN);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN3 ,DIO_HIGH_PIN);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN4 ,DIO_HIGH_PIN);
			_delay_ms(2);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN1 ,DIO_HIGH_PIN);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN2 ,DIO_LOW_PIN);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN3 ,DIO_HIGH_PIN);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN4 ,DIO_HIGH_PIN);
			_delay_ms(2);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN1 ,DIO_HIGH_PIN);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN2 ,DIO_HIGH_PIN);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN3 ,DIO_LOW_PIN);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN4 ,DIO_HIGH_PIN);
			_delay_ms(2);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN1 ,DIO_HIGH_PIN);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN2 ,DIO_HIGH_PIN);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN3 ,DIO_HIGH_PIN);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN4 ,DIO_LOW_PIN);
			_delay_ms(2);

	}
}



void STEPPER_voidCCWWithAngel(u8 Copy_u8Degree)
{
	u8 Local_u8Iterator;
	for(Local_u8Iterator=1;Local_u8Iterator<(Copy_u8Degree/0.703125);Local_u8Iterator++)
	{
		    DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN1 ,DIO_HIGH_PIN);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN2 ,DIO_HIGH_PIN);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN3 ,DIO_HIGH_PIN);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN4 ,DIO_LOW_PIN);
			_delay_ms(2);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN1 ,DIO_HIGH_PIN);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN2 ,DIO_HIGH_PIN);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN3 ,DIO_LOW_PIN);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN4 ,DIO_HIGH_PIN);
			_delay_ms(2);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN1 ,DIO_HIGH_PIN);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN2 ,DIO_LOW_PIN);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN3 ,DIO_HIGH_PIN);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN4 ,DIO_HIGH_PIN);
			_delay_ms(2);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN1 ,DIO_LOW_PIN);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN2 ,DIO_HIGH_PIN);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN3 ,DIO_HIGH_PIN);
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN4 ,DIO_HIGH_PIN);
			_delay_ms(2);

	}
}



void STEPPER_voidStop()
{
	DIO_voidSetPinDirection(STEPPER_PORT , STEPPER_PIN1 , DIO_HIGH_PIN);
	DIO_voidSetPinDirection(STEPPER_PORT , STEPPER_PIN2 , DIO_HIGH_PIN);
	DIO_voidSetPinDirection(STEPPER_PORT , STEPPER_PIN3 , DIO_HIGH_PIN);
	DIO_voidSetPinDirection(STEPPER_PORT , STEPPER_PIN4 , DIO_HIGH_PIN);
}
