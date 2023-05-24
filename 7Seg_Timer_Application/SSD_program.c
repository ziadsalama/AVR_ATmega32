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
	switch(Copy_Connection)
	{
	case SSD_COMM_CATHODE :

		DIO_voidSetPortDirection(Copy_SSDPort,DIO_PORT_OUTPUT);
		DIO_voidSetPinDirection(Copy_SSDCommonPort,Copy_SSDCommonPin,DIO_PORT_OUTPUT);

		break;
	case SSD_COMM_ANODE :
		DIO_voidSetPortDirection(Copy_SSDPort,DIO_PORT_OUTPUT);
		DIO_voidSetPinDirection(Copy_SSDCommonPort,Copy_SSDCommonPin,DIO_PORT_OUTPUT);
		break;
	}
}

void SSD_voidON(u8 Copy_Connection,u8 Copy_SSDCommonPort, u8 Copy_SSDCommonPin)
	{
	switch(Copy_Connection)
		{
		case SSD_COMM_CATHODE :
			DIO_voidSetPinValue(Copy_SSDCommonPort,Copy_SSDCommonPin,DIO_LOW_PIN );
			break;
		case SSD_COMM_ANODE :
			DIO_voidSetPinValue(Copy_SSDCommonPort,Copy_SSDCommonPin,DIO_HIGH_PIN );
			break;
	}

}


void SSD_voidOFF(u8 Copy_Connection,u8 Copy_SSDCommonPort, u8 Copy_SSDCommonPin)
	{
	switch(Copy_Connection)
		{
		case SSD_COMM_CATHODE :
			DIO_voidSetPinValue(Copy_SSDCommonPort,Copy_SSDCommonPin,DIO_HIGH_PIN );
			break;
		case SSD_COMM_ANODE :
			DIO_voidSetPinValue(Copy_SSDCommonPort,Copy_SSDCommonPin,DIO_LOW_PIN );
			break;
	}


}


void SSD_voidDisplayNumber(u8 Copy_Connection, u8 Copy_SSDPort , u8 Copy_u8DisplayedNumber)
{
	switch(Copy_Connection)
			{
			case SSD_COMM_CATHODE :
				DIO_u8SetPortValue(Copy_SSDPort,Copy_u8DisplayedNumber);
				break;
			case SSD_COMM_ANODE :
				DIO_u8SetPortValue(Copy_SSDPort,Copy_u8DisplayedNumber);
				break;
		}

}


