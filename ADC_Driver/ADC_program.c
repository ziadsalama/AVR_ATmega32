/*
 * ADC_program.c
 *
 *  Created on: Apr 4, 2023
 *      Author: ziads
 */




#include "std_macros.h"
#include "type_defs.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_cfg.h"

/* global pointer to function to set end of conversion interrupt call back */
void(*Global_ptrEndOfConversion)(void) = NULL;
/*pointer to get Readings */
u8* Global_u8Reading = NULL;

/*this function shall initialize ADC peripheral*/
void ADC_voidInit()
{

	SET_BIT(ADMUX,ADMUX_REFS0);           //   AVCC external reference voltage
	CLR_BIT(ADMUX,ADMUX_REFS1);          //  AVCC external reference voltage


	//SET_BIT(ADMUX,ADMUX_ADLAR);          //  8 bit  set left adjustment
	/*Set bit Adjust*/
	#if ADJUST == _8_BIT
		SET_BIT(ADMUX, ADMUX_ADLAR);

	#elif ADJUST == _10_BIT
		/*Set Right Adjustment*/
		CLEAR_BIT(ADMUX,ADMUX_ADLAR);
	#endif

	/* set clock Prescaler --> 128 */
	SET_BIT(ADCSRA,ADCSRA_ADPS0);       // prescaler 128
	SET_BIT(ADCSRA,ADCSRA_ADPS1);       // prescaler 128
	SET_BIT(ADCSRA,ADCSRA_ADPS2);      // prescaler 128

	SET_BIT(ADCSRA,ADCSRA_ADEN);         // Enable ADC


}



/*start conversion and return the data*/
void ADC_voidStartConversion(u8 Copy_u8Channel ,u8* Copy_u8Reading)
{
	SET_BIT(ADCSRA,ADCSRA_ADIE);         // Interrupt enable Enable end of converstion interrupt
	/* Enable Global Interrupt */
	SET_BIT(SREG,SREG_I);

	/*  Set ADC Channel */
	ADMUX &= MUX_MASK;
	ADMUX |= Copy_u8Channel ;

	/* Assign global variable to get the reading  */
	Global_u8Reading= Copy_u8Reading;

	SET_BIT(ADCSRA,ADCSRA_ADSC);         // Start Conversion


}

void ADC_voidStartConversionSync(u8 Copy_u8Channel ,u8* Copy_u8Reading)
{
	/*  Set ADC Channel */
	ADMUX &= MUX_MASK;
	ADMUX |= Copy_u8Channel ;

	SET_BIT(ADCSRA,ADCSRA_ADSC);         // Start Conversion

	while(READ_BIT(ADCSRA,ADCSRA_ADIF));        /* Polling to raise flag */

	SET_BIT(ADCSRA,ADCSRA_ADSC);                    /* clear flag */


	/* Assign global variable to get the reading  */
	Global_u8Reading = Copy_u8Reading;

	//*Copy_u8Reading = ADCH;
}



void ADC_voidSetCallBack(void(*Copy_ptrToFunction)(void))
{
	if(Copy_ptrToFunction != NULL)
	{
		Global_ptrEndOfConversion = Copy_ptrToFunction;
	}
	else
	{

	}

}


void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	if(Global_ptrEndOfConversion != NULL)
	{
#if LADJUST == _8_BITS
		*Global_u8Reading = ADCH;
#elif LADJUST == _10_BITS
		*Global_u8Reading = (ADCL | ADCH << 8);

#endif

		Global_ptrEndOfConversion();
	}
	else
	{

	}
}



void ADC_voidInitWithPrescaler(u8 Copy_u8Prescaler)
{
	SET_BIT(ADMUX,ADMUX_REFS0);           //   AVCC external reference voltage
	CLR_BIT(ADMUX,ADMUX_REFS1);          //  AVCC external reference voltage
	SET_BIT(ADMUX,ADMUX_ADLAR);          //  8 bit  set left adjustment

	/*  Set Prescaler */
	ADCSRA &= PRESCALER_MASK;
	ADCSRA |= Copy_u8Prescaler ;

	SET_BIT(ADCSRA,ADCSRA_ADEN);         // Enable ADC

}







