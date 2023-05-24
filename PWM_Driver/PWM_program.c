/*
 * PWM_program.c
 *
 *  Created on: Apr 7, 2023
 *      Author: ziads
 */


#include "std_macros.h"
#include "type_defs.h"

#include "PWM_interface.h"
#include "PWM_private.h"
#include "PWM_cfg.h"


void (* Global_pfCTCCallBack)(void)= NULL;



void PWM_voidRunPWM(u8 Copy_u8Channel, u8 Copy_u8Frequency)
{
	/* Select Timer1 Mode 14 -> Fast PWM */
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);

	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);



	if(Copy_u8Channel==TIMER1_CHANNEL_A)
	{
		/* Non Inverted */
			CLR_BIT(TCCR1A,TCCR1A_COM1A0);
			SET_BIT(TCCR1A,TCCR1A_COM1A1);

	}
	else if(Copy_u8Channel== TIMER1_CHANNEL_B)
	{
		SET_BIT(TCCR1A,TCCR1A_COM1B1);
		CLR_BIT(TCCR1A, TCCR1A_COM1B0);

	}

	ICR1 = Copy_u8Frequency;
	/*Setting Prescaler 8 */
	TCCR1B &= CLR_MASK ;
	TCCR1B |= PRESCALER_MASK_8;
}


void PWM_voidSetDutyCycle(u8 Copy_u8Channel, u8 Copy_u8Frequency,u8 Copy_u8DutyCycle)
{
	if(Copy_u8Channel==TIMER1_CHANNEL_A)
		{
		OCR1A= (Copy_u8Frequency*Copy_u8DutyCycle)/100;

		}
		else if(Copy_u8Channel== TIMER1_CHANNEL_B)
		{
			OCR1B = (Copy_u8Frequency/100)*Copy_u8DutyCycle;

		}

}

void PWM_voidSetServoDutyCycle(u8 Copy_u8Channel, u8 Copy_u8Frequency,u8 Copy_u8DutyCycle)
{
	if((Copy_u8DutyCycle>=750) && (Copy_u8DutyCycle<=2500))
	{
	if(Copy_u8Channel==TIMER1_CHANNEL_A)
			{
			OCR1A= Copy_u8DutyCycle;

			}
			else if(Copy_u8Channel== TIMER1_CHANNEL_B)
			{
				OCR1B = Copy_u8DutyCycle ;
			}
	}
}




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




void TIMER0_voidRunTimer0PWM(void(* Copy_pfCompareMatchInterrupt)(void))
{
	/* Set TIMER0 Mode To CTC */
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/* Disconnecting 0C0 Pin*/
	CLR_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);


	/*Setting Compare match value to be 250*/
	OCR0 = 156.25;
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
	TCCR0 |= TIMER0_PRESCALER_256;

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
