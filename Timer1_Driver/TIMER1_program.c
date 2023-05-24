/*
 * TIMER1_program.c
 *
 *  Created on: Apr 8, 2023
 *      Author: ziads
 */


#include "std_macros.h"
#include "type_defs.h"

#include "TIMER1_interface.h"
#include "TIMER1_private.h"
#include "TIMER1_cfg.h"

void (* Global_ptrCallBack)(void)= NULL;

u16* Global_u8Reading = NULL;


void TIMER1_voidDelaySync(f64 Copy_f64MilleSecond)
{
	/* Set Timer1 Mode -> CTC */
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

	/* setting Timer1 to be Normal */
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	CLR_BIT(TCCR1A,TCCR1A_COM1A1);


	/* Setting Compare value at OCR */
	OCR1A = (Copy_f64MilleSecond * ( 125UL / 16));

	/*Setting the prescaler -> 1024*/
	TCCR1B &= CLR_MASK ;
	TCCR1B |= PRESCALER_MASK_1024 ;

     /*checking  the flag */
	while((READ_BIT(TIFR, TIFR_OCF1A)) == 0);
	SET_BIT(TIFR,TIFR_OCF1A);
}


void TIMER1_voidDelayAsync(f64 Copy_f64MilleSecond,void(*PtrToFuncCallBack)(void))
{
	/* Set Timer1 Mode -> CTC */
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

	/* setting Timer1 to be Normal */
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	CLR_BIT(TCCR1A,TCCR1A_COM1A1);



	/* Setting Compare value at OCR */
	OCR1A = (Copy_f64MilleSecond * ( 125UL / 16));

	/*enable interrupt*/
	SET_BIT(TIMSK,TIMSK_OCIE1A);

	if(PtrToFuncCallBack != NULL)
		{
			Global_ptrCallBack=PtrToFuncCallBack;
		}
		else
		{
			/* do nothing */
		}
	/*Setting the prescaler -> 1024*/
	TCCR1B &= CLR_MASK ;
	TCCR1B |= PRESCALER_MASK_1024 ;

}

void __vector_7(void)__attribute((signal));
void __vector_7(void)
{

	if(Global_ptrCallBack !=NULL)
	{
		Global_ptrCallBack();
	}
	else
	{
		/* do nothing */
	}
}





void TIMER1_voidRunServoMotor(void)
{
	/*  SET Mode Fast PWM */
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);

	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);

   ICR1 = 20000;
	/*  SET Prescaler */
	TCCR1B &=CLR_MASK;
	TCCR1B |= PRESCALER_MASK_8;

}


void TIMER1_voidSetAngel(u16 Copy_u8Reading)
{

	//OCR1 = Copy_u8Reading;
	OCR1A = Copy_u8Reading;

}



