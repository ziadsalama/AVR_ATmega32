/*
 * SERVO_program.c
 *
 *  Created on: Apr 12, 2023
 *      Author: ziads
 */

#include "std_macros.h"
#include "type_defs.h"

#include "PWM_interface.h"
#include "SERVO_interface.h"
#include "SERVO_private.h"
#include "SERVO_cfg.h"


void SERVO_voidStartServo(u8 Copy_u8Channel)
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

		ICR1 = FREQUENCY_50 ;
		/*Setting Prescaler 8 */
		TCCR1B &= CLR_MASK ;
		TCCR1B |= PRESCALER_MASK_8;

}





void SERVO_voidRotateServo(u8 Copy_u8Channel, u8 Copy_u8Angel)
{

		if(Copy_u8Channel==TIMER1_CHANNEL_A)
		{
			//OCR1A = (Copy_u8Angel*10)+750;
			OCR1A = ((175UL * (f64)Copy_u8Angel) / 18UL) + 750UL ;
		}
		else if(Copy_u8Channel==TIMER1_CHANNEL_B)
		{
			OCR1B = ((175UL * (f64)Copy_u8Angel) / 18UL) + 750UL ;

		}


}

