/*
 * ICU_program.c
 *
 *  Created on: Apr 12, 2023
 *      Author: ziads
 */


#include "std_macros.h"
#include "type_defs.h"

#include "ICU_interface.h"
#include "ICU_private.h"
#include "ICU_cfg.h"


void (* Global_ptrToFuncCallBack)(void)= NULL ;

void TIMER0_voidRunPWMFastNonInverted(void)
{
	/* Set TIMER0 Mode To Fast PWM */
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/*activate Fast PWM Mode Clear on Compare match and set on Top*/
	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);

	/* Setting Prescaler with bit mask --> 8  */
	TCCR0 &= PRESCALER_MASK_TIMER0;
	TCCR0 |= TIMER0_PRESCALER_8;


}

void TIMER_voidSetOCR0Value(u8 Copy_u8OCR0Value)
{

	/*Setting Compare match value to be 250*/
		OCR0 = Copy_u8OCR0Value ;

}

void Timer1_voidRunNormalMode(void(*PtrToFuncCallBack)(void))
{
	/* Set Timer1 on Normal Mode */
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);


	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	CLR_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A,TCCR1A_COM1B0);
	CLR_BIT(TCCR1A,TCCR1A_COM1B1);

	/* Set Input Capture Rising */
	SET_BIT(TCCR1B,TCCR1B_ICES1);

	/* Set interrupt Enable */
	SET_BIT(TIMSK,TIMSK_TICIE1);

	if(PtrToFuncCallBack != NULL)
	{
		Global_ptrToFuncCallBack=PtrToFuncCallBack;
	}
	else
	{
		/* do nothing */
	}

	/* Set Prescaler -> 8*/
		TCCR1B &= CLR_MASK_TIMER1 ;
		TCCR1B |= PRESCALER_MASK_TIMER1_8 ;

}


u16 TIMER1_u16GetReading()
{

	return ICR1;

}


void __vector_6(void)__attribute((signal));
void __vector_6(void)
{

	if(Global_ptrToFuncCallBack != NULL)
	{
		Global_ptrToFuncCallBack();
	}
	else
	{
		/* do nothing */
	}
}
