/*
 * TIMER_interface.h
 *
 *  Created on: Apr 5, 2023
 *      Author: ziads
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define TIMER0_PRESCALER_8       2
#define TIMER0_PRESCALER_64      3

void TIMER0_voidRunTimer0CTCAsync(void(* Copy_pfCompareMatchInterrupt)(void));

void TIMER0_voidRunPWMFastNonInverted(void);


void TIMER_voidSetOCR0Value(u8 Copy_u8OCR0Value);



#endif /* TIMER_INTERFACE_H_ */
