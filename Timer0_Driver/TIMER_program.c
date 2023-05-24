/*
 * TIMER_program.c
 *
 *  Created on: Apr 5, 2023
 *      Author: ziads
 */


#include "std_macros.h"
#include "type_defs.h"

#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_cfg.h"

void (* Global_pfCTCCallBack)(void)= NULL;

void TIMER0_voidRunTimer0CTCAsync(void(* Copy_pfCompareMatchInterrupt)(void))
{
	/* Set TIMER0 Mode To CTC */
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/* Disconnecting 0C0 Pin*/
	CLR_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);


	/*Setting Compare match value to be 250*/
	OCR0 = 250;
	/* Enable Compare match interrupt  */
	SET_BIT(TIMSK,TIMSK_OCIE0);

	/* Enable Global Interrupt */
	SET_BIT(SREG,SREG_I);

	if(Copy_pfCompareMatchInterrupt != NULL)
	{
		Global_pfCTCCallBack= Copy_pfCompareMatchInterrupt;

	}

	/* Setting Prescaler with bit mask --> 8  */
	TCCR0 &= PRESCALER_MASK;
	TCCR0 |= TIMER0_PRESCALER_8;

	/* Setting Prescaler */
	//	CLR_BIT(TCCR0,TCCR0_CS00);
	//	SET_BIT(TCCR0,TCCR0_CS01);
	//	CLR_BIT(TCCR0,TCCR0_CS02);



}




void TIMER0_voidRunTimer0CTCPWM(void(* Copy_pfCompareMatchInterrupt)(void))
{
	/* Set TIMER0 Mode To CTC */
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/* Disconnecting 0C0 Pin*/
	CLR_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);


	/*Setting Compare match value to be 250*/
	OCR0 = 125;
	/* Enable Compare match interrupt  */
	SET_BIT(TIMSK,TIMSK_OCIE0);

	/* Enable Global Interrupt */
	SET_BIT(SREG,SREG_I);

	if(Copy_pfCompareMatchInterrupt != NULL)
	{
		Global_pfCTCCallBack= Copy_pfCompareMatchInterrupt;

	}

	/* Setting Prescaler with bit mask --> 64  */
	TCCR0 &= PRESCALER_MASK;
	TCCR0 |= TIMER0_PRESCALER_64;

	/* Setting Prescaler */
	//	CLR_BIT(TCCR0,TCCR0_CS00);
	//	SET_BIT(TCCR0,TCCR0_CS01);
	//	CLR_BIT(TCCR0,TCCR0_CS02);



}



void __vector_10(void)__attribute((signal));
void __vector_10(void)
{

	if(Global_pfCTCCallBack !=NULL)
	{
		Global_pfCTCCallBack();
	}
	else
	{
		/* do nothing */
	}
}






/*****************************************************************************************************/

void TIMER0_voidRunPWMFastNonInverted(void){
	/* Set TIMER0 Mode To Fast PWM */
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/*activate Fast PWM Mode Clear on Compare match and set on Top*/
	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);

	/* Setting Prescaler with bit mask --> 8  */
	TCCR0 &= PRESCALER_MASK;
	TCCR0 |= TIMER0_PRESCALER_8;


}

void TIMER_voidSetOCR0Value(u8 Copy_u8OCR0Value){

	/*Setting Compare match value to be 250*/
		OCR0 = Copy_u8OCR0Value ;

}
