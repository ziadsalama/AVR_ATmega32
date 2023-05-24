/*
 * TIMER_interface.h
 *
 *  Created on: Apr 5, 2023
 *      Author: ziads
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define TIMER0_PRESCALER_8       2

void TIMER0_voidRunTimer0CTCAsync(void(* Copy_pfCompareMatchInterrupt)(void));

#endif /* TIMER_INTERFACE_H_ */
