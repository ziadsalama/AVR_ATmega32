/*
 * PB_program.c
 *
 *  Created on: Mar 31, 2023
 *      Author: ziads
 */


#include "type_defs.h"
#include "std_macros.h"

#include "DIO_interface.h"

#include "PB_interface.h"
#include "PB_private.h"
#include "PB_cfg.h"


void PB_voidInit(u8 Copy_u8PBPortID , u8 Copy_u8PBPin , u8 Copy_u8PBConnection )
{
	if(Copy_u8PBConnection == PB_PULL_UP)
	{
		DIO_voidSetPinValue(Copy_u8PBPortID , Copy_u8PBPin , DIO_PIN_INPUT_PULLUP);
	}

	else if(Copy_u8PBConnection == PB_PULL_DOWN)
	{
		DIO_voidSetPinValue(Copy_u8PBPortID , Copy_u8PBPin , DIO_PIN_INPUT_FLOAT);

	}

}

u8  PB_u8GetStatus(u8 Copy_u8PBPortID , u8 Copy_u8PBPin , u8 Copy_u8PBConnection )
{
	u8 Local_ReturnStatus;

	if(Copy_u8PBConnection == PB_PULL_UP)
	{
		Local_ReturnStatus=DIO_u8GetPinValue(Copy_u8PBPortID,Copy_u8PBPin);
		if(Local_ReturnStatus==1)
		{
			Local_ReturnStatus = PB_PU_RELEASED;
		}
		else if(Local_ReturnStatus==0)
		{
			Local_ReturnStatus= PB_PU_PRESSED;
		}
	}

	 if(Copy_u8PBConnection == PB_PULL_DOWN)

	 {
	 		Local_ReturnStatus=DIO_u8GetPinValue(Copy_u8PBPortID,Copy_u8PBPin);
	 		if(Local_ReturnStatus==0)
	 		{
	 			Local_ReturnStatus=  PB_PD_RELEASED;
	 		}
	 		else if(Local_ReturnStatus==1)
	 		{
	 			Local_ReturnStatus =  PB_PD_PRESSED;
	 		}
	 	}


	return Local_ReturnStatus;
}
