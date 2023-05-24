/*
 * KYPD_program.c
 *
 *  Created on: Mar 31, 2023
 *      Author: ziads
 */


#include "std_macros.h"
#include "type_defs.h"

#include "DIO_interface.h"

#include "KYPD_interface.h"
#include "KYPD_private.h"
#include "KYPD_cfg.h"


void KPD_voidInit(void)
{

DIO_voidSetPinDirection(KPD_PORT ,KPD_ROW0 ,DIO_PIN_INPUT_PULLUP);
DIO_voidSetPinDirection(KPD_PORT ,KPD_ROW1 ,DIO_PIN_INPUT_PULLUP);
DIO_voidSetPinDirection(KPD_PORT ,KPD_ROW2 ,DIO_PIN_INPUT_PULLUP);
DIO_voidSetPinDirection(KPD_PORT ,KPD_ROW3 ,DIO_PIN_INPUT_PULLUP);



DIO_voidSetPinDirection(KPD_PORT ,KPD_COL0 ,DIO_PIN_OUTPUT);
DIO_voidSetPinDirection(KPD_PORT ,KPD_COL1 ,DIO_PIN_OUTPUT);
DIO_voidSetPinDirection(KPD_PORT ,KPD_COL2 ,DIO_PIN_OUTPUT);
DIO_voidSetPinDirection(KPD_PORT ,KPD_COL3 ,DIO_PIN_OUTPUT);

DIO_voidSetPinValue(KPD_PORT ,KPD_COL0 ,DIO_HIGH_PIN);
DIO_voidSetPinValue(KPD_PORT ,KPD_COL1 ,DIO_HIGH_PIN);
DIO_voidSetPinValue(KPD_PORT ,KPD_COL2 ,DIO_HIGH_PIN);
DIO_voidSetPinValue(KPD_PORT ,KPD_COL3 ,DIO_HIGH_PIN);



}









u8 KPD_u8GetPressedKey(void)
{
	/*local variable to check whether the switch is pressed or not*/
	u8 Local_u8State ;

	/*local variable to store the value of the pressed key*/
	u8 Local_u8PressedKey = KPD_NO_PRESSED_KEY ;

	/*local variables to iterate over rows and columns*/
	u8 Local_u8RowIterator ;
	u8 Local_u8ColIterator ;

	u8 Local_au8Cols[COL_NUM]={KPD_COL0 , KPD_COL1 , KPD_COL2 , KPD_COL3};
	u8 Local_au8Rows[ROW_NUM]={KPD_ROW0 , KPD_ROW1 , KPD_ROW2 , KPD_ROW3};


	u8 KPD_ARR[ROW_NUM][COL_NUM] = KPD_VALUES;

	/*looping over columns to activate them*/
	for(Local_u8ColIterator=0 ; Local_u8ColIterator < COL_NUM ; Local_u8ColIterator++)
	{
		/*activate column be column*/
		DIO_voidSetPinValue(KPD_PORT ,Local_au8Cols[Local_u8ColIterator] , DIO_LOW_PIN );

		/*looping over rows to read them*/
		for(Local_u8RowIterator = 0 ; Local_u8RowIterator < ROW_NUM ; Local_u8RowIterator++)
		{
			/*checking whether any switch is pressed or not*/
			Local_u8State = DIO_u8GetPinValue(KPD_PORT ,Local_au8Rows[Local_u8RowIterator]) ;

			/*in case of a pressed key*/
			if(Local_u8State == 0)
			{
				/*getting the value of the pressed key*/
				Local_u8PressedKey = KPD_ARR[Local_u8RowIterator][Local_u8ColIterator];

				/*polling till the user releases the switch*/
				while(Local_u8State==0)
				{
					Local_u8State = DIO_u8GetPinValue(KPD_PORT ,Local_au8Rows[Local_u8RowIterator]) ;
				}

//				/*deactivate the recent column before return*/
//				DIO_voidSetPinValue(KPD_PORT ,Local_au8Cols[Local_u8ColIterator] , DIO_HIGH_PIN);

				/*ending the loop*/
				return Local_u8PressedKey ;
			}
		}

		/*deactivate column be column*/
		DIO_voidSetPinValue(KPD_PORT ,Local_au8Cols[Local_u8ColIterator] , DIO_HIGH_PIN);
	}

	return Local_u8PressedKey ;

}
