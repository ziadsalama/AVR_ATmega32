/*
 * ICU_interface.h
 *
 *  Created on: Apr 12, 2023
 *      Author: ziads
 */

#ifndef ICU_INTERFACE_H_
#define ICU_INTERFACE_H_

#define TIMER0_PRESCALER_8       2
#define TIMER0_PRESCALER_64      3


#define PRESCALER_MASK_TIMER1_8             2
#define PRESCALER_MASK_TIMER1_64            3
#define PRESCALER_MASK_TIMER1_265           4
#define PRESCALER_MASK_TIMER1_1024          5


void TIMER0_voidRunPWMFastNonInverted(void);

void TIMER_voidSetOCR0Value(u8 Copy_u8OCR0Value);

void Timer1_voidRunNormalMode(void(*PtrToFuncCallBack)(void));


u16 TIMER1_u16GetReading();


#endif /* ICU_INTERFACE_H_ */
