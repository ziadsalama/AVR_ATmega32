
#include "std_macros.h"
#include "type_defs.h"

#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"

/*Global Pointer to function to set end of conversion interrupt call back*/
void(*Global_ptrEndOfConversion)(void) = NULL;
/*pointer to read */
u8 *Global_Reading = NULL;

/*this function shall initialize ADC peripheral*/
void ADC_voidInit(void)
{
#if REFRENCE == AVCC
	/*Set reference voltage -> AVCC*/
	SET_BIT(ADMUX, ADMUX_REFS0);
	CLR_BIT(ADMUX, ADMUX_REFS1);
#elif REFRENCE == VAR_AREF
	/*Set refrence voltage -> varAREF*/
	CLR_BIT(ADMUX, ADMUX_REFS0);
	CLR_BIT(ADMUX, ADMUX_REFS1);
#elif REFRENCE == CONST_AREF
	/*Set refrence voltage -> constAREF -> 2.56v*/
	SET_BIT(ADMUX, ADMUX_REFS0);
	SET_BIT(ADMUX, ADMUX_REFS1);
#endif
	/*Set bit Adjust*/
#if ADJUST == _8_BIT
	SET_BIT(ADMUX, ADMUX_ADLAR);

#elif ADJUST == _10_BIT

#endif

	/*Set Clock prescaler -> 128*/
	ADCSRA &= PRESC_MASK;
	ADCSRA |= ADC_PRESC;   //you can change it from config.h


	/*Enable ADC*/
	SET_BIT(ADCSRA, ADCSRA_ADEN);
}



/*start conversion and return the data*/
void ADC_u8StartConversion(u8 Copy_u8Channel, u8 *Copy_u8Reading)
{
	/*Enable end of conversion interrupt*/
	SET_BIT(ADCSRA, ADCSRA_ADIE);

	/*Set ADC Channel*/
	ADMUX &= MUX_MASK;
	ADMUX |= Copy_u8Channel;

	/*Assign global variable to get the reading*/
	Global_Reading = Copy_u8Reading;

	/*Start Conversion*/
	SET_BIT(ADCSRA, ADCSRA_ADSC);

}



u8 ADC_u8GetChannelReading(u8 Copy_u8Channel)
{
	ADMUX &= MUX_MASK;

	ADMUX |= Copy_u8Channel;

	SET_BIT(ADCSRA, ADCSRA_ADSC);
	while ((READ_BIT(ADCSRA, ADCSRA_ADIF)) == 0);

	SET_BIT(ADCSRA, ADCSRA_ADIF);
#if ADJUST == _8_BIT
	return ADCH;
#elif ADJUST == _10_BIT
	return (ADCL | ADCH << 8);
#endif
}



/*callback*/
void ADC_voidSetCallBack(void(*Copy_ptrToFunction)(void))
{
	if (Copy_ptrToFunction != NULL)
	{
		Global_ptrEndOfConversion = Copy_ptrToFunction;
	}
	else
	{
		/*do nothing*/
	}

}


void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	if(Global_ptrEndOfConversion != NULL)
	{
#if ADJUST == _8_BIT
		*Global_Reading = ADCH;
#elif ADJUST == _10_BIT
		*Global_Reading = (ADCL | ADCH << 8);

#endif
		Global_ptrEndOfConversion();
	}
	else
	{
		/*Do Nothing*/
	}

}


