/*
 * main.c
 *
 *  Created on: Apr 6, 2023
 *      Author: ziads
 */


#include <avr/io.h>
#include<util/delay.h>
#include "std_macros.h"
#include "type_defs.h"
#include "DIO_interface.h"
#include "TIMER_interface.h"
#include "SSD_interface.h"

 u8 Global_Ass =0;
 u8 Global_des =9;

 void Application(void);

void main(void)
{

	u8 arr[10]={SSD_CATH_NUM_0, SSD_CATH_NUM_1, SSD_CATH_NUM_2 ,SSD_CATH_NUM_3,
	SSD_CATH_NUM_4, SSD_CATH_NUM_5, SSD_CATH_NUM_6, SSD_CATH_NUM_7 , SSD_CATH_NUM_8 , SSD_CATH_NUM_9};

	u8* ptr=arr;
	SSD_voidInit(SSD_COMM_CATHODE,DIO_PORTA, DIO_PORTB, DIO_PIN0);
	SSD_voidInit(SSD_COMM_CATHODE,DIO_PORTA, DIO_PORTB, DIO_PIN1);

	TIMER0_voidRunTimer0CTCAsync(Application);
	while(1)
	{
		SSD_voidOFF(SSD_COMM_CATHODE, DIO_PORTB, DIO_PIN1);
		SSD_voidON(SSD_COMM_CATHODE, DIO_PORTB, DIO_PIN0);
		SSD_voidDisplayNumber(SSD_COMM_CATHODE,DIO_PORTA, ptr[Global_Ass]);
		_delay_ms(10);

		SSD_voidOFF(SSD_COMM_CATHODE, DIO_PORTB, DIO_PIN0);
		SSD_voidON(SSD_COMM_CATHODE, DIO_PORTB, DIO_PIN1);

		SSD_voidDisplayNumber(SSD_COMM_CATHODE,DIO_PORTA, ptr[Global_des])	;
		_delay_ms(10);

	}

}



void Application(void)
{
	static u16 counter = 0;
	counter++;
	if(counter == 4000)
	{
		Global_Ass++;
		Global_des--;
		if(Global_Ass == 10)
		{
			Global_Ass = 0;
			Global_des = 9;
		}

		/* reset counter*/
		counter=0;
	}
}
