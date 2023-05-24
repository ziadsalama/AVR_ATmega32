/*
 * MOTOR_program.c
 *
 *  Created on: Apr 2, 2023
 *      Author: ziads
 */


#include "std_macros.h"
#include "type_defs.h"
#include "DIO_interface.h"

#include "MOTOR_interface.h"
#include "MOTOR_private.h"
#include "MOTOR_cfg.h"


void MOTOR_voidInit()
{
	DIO_voidSetPinDirection(MOTOR_PORT , MOTOR_FORWARD_PIN , DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(MOTOR_PORT , MOTOR_BACK_PIN , DIO_PIN_OUTPUT);
}

void MOTOR_voidForward()
{
	DIO_voidSetPinValue(MOTOR_PORT , MOTOR_FORWARD_PIN ,DIO_HIGH_PIN);
	DIO_voidSetPinValue(MOTOR_PORT , MOTOR_BACK_PIN ,DIO_LOW_PIN);
}

void MOTOR_voidBackward()
{
	DIO_voidSetPinValue(MOTOR_PORT , MOTOR_BACK_PIN ,DIO_HIGH_PIN);
	DIO_voidSetPinValue(MOTOR_PORT , MOTOR_FORWARD_PIN ,DIO_LOW_PIN);

}


void MOTOR_voidStop()
{
	DIO_voidSetPinValue(MOTOR_PORT , MOTOR_FORWARD_PIN ,DIO_LOW_PIN);
	DIO_voidSetPinValue(MOTOR_PORT , MOTOR_BACK_PIN ,DIO_LOW_PIN);
}
