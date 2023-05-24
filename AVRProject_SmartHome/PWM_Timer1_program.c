#include "std_macros.h"
#include "type_defs.h"

#include "DIO_interface.h"

#include "PWM_Timer1_interface.h"
#include "PWM_Timer1_private.h"
#include "PWM_Timer1_config.h"

void PWM_Timer1voidInit(u8 Copy_u16Channel)
{
	switch (Copy_u16Channel)
	{
	case OUTPUT_COMPARE_A :
#if    (PWM_MODE == NON_INVERTING)

		SET_BIT(TCCR1A,COM1A1);
		CLR_BIT(TCCR1A,COM1A0);

#elif  (PWM_MODE == INVERTING)

		SET_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);

#endif
		break;

	case OUTPUT_COMPARE_B :

#if    (PWM_MODE == NON_INVERTING)

		SET_BIT(TCCR1B,COM1B1);
		CLR_BIT(TCCR1B,COM1B0);

#elif  (PWM_MODE == INVERTING)

		SET_BIT(TCCR1B,COM1B0);
		SET_BIT(TCCR1B,COM1B1);

#endif
		break;
	}



	/*choose mode 14*/
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	CLR_BIT(TCCR1A,WGM10);

}
void Set_PWM_Timer1_voidFrequency(u32 Copy_u32Frequency)
{
	ICR1L = (( (CRYSTAL_FREQ * 1000000) / (PRESCALAR_VALUE * Copy_u32Frequency) ) -1);
}
void PWM_Timer1voidStart(void)
{
		/*Set PreScaler*/
		TCCR1B &=PRESCALER_MASK ;
		TCCR1B |=PRESCALE_MODE ;
}
void Set_Duty_Cycle_PWM_Timer1_void(u8 Copy_u16Channel,u16 Copy_u16Percent)
{
	u16 T_on = 0;
	T_on = ICR1L  - ( (100-Copy_u16Percent) * (ICR1L/100) );
	switch(Copy_u16Channel)
	{
	case OUTPUT_COMPARE_A :
		OCR1AL = T_on ;
		break;
	case OUTPUT_COMPARE_B :
		OCR1BL = T_on ;
		break;
	}
}
