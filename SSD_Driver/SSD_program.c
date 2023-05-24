/*
 * SSD_program.c
 *
 *  Created on: Mar 27, 2023
 *      Author: ziads
 */



#include "std_macros.h"
#include "type_defs.h"

#include "DIO_interface.h"

#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_cfg.h"



void SSD_voidInit(u8 Copy_Connection,u8 Copy_SSDPort,u8 Copy_SSDCommonPort, u8 Copy_SSDCommonPin)
{



}





//This function is to Initialize the Seven Segment Display
void SSD_voidSsdInit(u8 Copy_u8PortID1 , u8 Copy_u8PortID2 , u8 Copy_u8CommonPortID , u8 Copy_u8CommonPin0 , u8 Copy_u8CommonPin1)
{
	DIO_voidSetPortDirection(Copy_u8PortID1 , DIO_PORT_OUTPUT);
	DIO_voidSetPortDirection(Copy_u8PortID2 , DIO_PORT_OUTPUT);
	DIO_voidSetPinDirection(Copy_u8CommonPortID , Copy_u8CommonPin0 , DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(Copy_u8CommonPortID , Copy_u8CommonPin1 , DIO_PIN_OUTPUT);
}

//This function is to turn the Seven Segment Display ON
void SSD_voidSsdOn(u8 Copy_u8SsdConnection , u8 Copy_u8CommonPortID , u8 Copy_u8CommonPin)
{
	DIO_voidSetPinValue(Copy_u8CommonPortID , Copy_u8CommonPin , Copy_u8SsdConnection);
}

//This function is to Display the Number on the Seven Segment Display
void SSD_voidSsdDisplayNumber(u8 Copy_u8PortID , u8 Copy_u8SsdNumber)
{
	DIO_u8SetPortValue(Copy_u8PortID , Copy_u8SsdNumber);
}

//This function is to turn the Seven Segment Display OFF
void SSD_voidSsdOff(u8 Copy_u8SsdConnection , u8 Copy_u8CommonPortID , u8 Copy_u8CommonPin)
{
	DIO_voidSetPinValue(Copy_u8CommonPortID , Copy_u8CommonPin , ~(Copy_u8SsdConnection));
}

