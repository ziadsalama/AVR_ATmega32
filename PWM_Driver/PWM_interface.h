/*
 * PWM_interface.h
 *
 *  Created on: Apr 7, 2023
 *      Author: ziads
 */

#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_

/* Timer0  Prescaler */
#define TIMER0_PRESCALER_8       2
#define TIMER0_PRESCALER_64      3
#define TIMER0_PRESCALER_256     4



#define FREQUENCY_20			50000
#define FREQUENCY_40			25000
#define FREQUENCY_50			20000
#define FREQUENCY_100		    10000
#define FREQUENCY_200		    5000
#define FREQUENCY_250	      	4000
#define FREQUENCY_500		    2000
#define FREQUENCY_1000	     	1000
#define FREQUENCY_2000		    500
#define FREQUENCY_2500		    400
#define FREQUENCY_5000		    200
#define FREQUENCY_10000		    100
#define FREQUENCY_20000		    50
#define FREQUENCY_50000		    20

/*
#define TMR1_PRESCALER_8		2
#define TMR1_PRESCALER_64		3
#define TMR1_PRESCALER_256_		4
#define TMR1_PRESCALER_1024		5
*/

/* channel A and B*/
#define TIMER1_CHANNEL_A		1
#define TIMER1_CHANNEL_B		2

void PWM_voidRunPWM(u8 Copy_u8Channel, u8 Copy_u8Frequency);

void PWM_voidSetDutyCycle(u8 Copy_u8Channel, u8 Copy_u8Frequency,u8 Copy_u8DutyCycle);

void PWM_voidSetServoDutyCycle(u8 Copy_u8Channel, u8 Copy_u8Frequency,u8 Copy_u8DutyCycle);



void TIMER0_voidRunTimer0PWM(void(* Copy_pfCompareMatchInterrupt)(void));


void TIMER0_voidRunPWMFastNonInverted(void);


void TIMER_voidSetOCR0Value(u8 Copy_u8OCR0Value);




#endif /* PWM_INTERFACE_H_ */
