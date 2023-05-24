/*
 * LED_program.c
 *
 *  Created on: Mar 27, 2023
 *      Author: ziads
 */


#include "std_macros.h"
#include "type_defs.h"

#include "DIO_interface.h"


#include "LED_interface.h"
#include "LED_private.h"
#include "LED_cfg.h"




void LED_voidPinLedInit(u8 Copy_u8PortID , u8 Copy_u8Pin)
{
	DIO_voidSetPinDirection(Copy_u8PortID , Copy_u8Pin , DIO_PIN_OUTPUT);
}
void LED_voidPortLedInit(u8 Copy_u8PortID)
{
	DIO_voidSetPortDirection(Copy_u8PortID , DIO_PORT_OUTPUT);
}
void LED_voidLedOn(u8 Copy_u8PortID , u8 Copy_u8Pin)
{
	DIO_voidSetPinValue(Copy_u8PortID , Copy_u8Pin , DIO_HIGH_PIN);
}
void LED_voidLedOff(u8 Copy_u8PortID , u8 Copy_u8Pin)
{
	DIO_voidSetPinValue(Copy_u8PortID , Copy_u8Pin , DIO_LOW_PIN);
}
void LED_voidToggleLed(u8 Copy_u8PortID , u8 Copy_u8Pin)
{
	DIO_voidTogglePin(Copy_u8PortID , Copy_u8Pin);
}



