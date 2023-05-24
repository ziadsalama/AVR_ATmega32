/*
 * TIMER_private.h
 *
 *  Created on: Apr 5, 2023
 *      Author: ziads
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#define PRESCALER_MASK       0b11111000



#define SREG      (*(volatile u8 *)(0x5f))
#define SREG_I                  7

#define TCCR0     (*(volatile u8 *)(0x53))

#define TCCR0_CS00              0
#define TCCR0_CS01              1
#define TCCR0_CS02              2
#define TCCR0_WGM01             3
#define TCCR0_COM00             4
#define TCCR0_COM01             5
#define TCCR0_WGM00             6
#define TCCR0_FOC0              7




#define TCNT0     (*(volatile u8 *)(0x52))

#define OCR0      (*(volatile u8 *)(0x5C))

#define TIMSK      (*(volatile u8 *)(0x59))

#define TIMSK_TOIE0             0
#define TIMSK_OCIE0             1


#define TIFR      (*(volatile u8 *)(0x58))

#define TIFR_TOV0             0
#define TIFR_OCF0             1



#endif /* TIMER_PRIVATE_H_ */
