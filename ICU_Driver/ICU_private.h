/*
 * ICU_private.h
 *
 *  Created on: Apr 12, 2023
 *      Author: ziads
 */

#ifndef ICU_PRIVATE_H_
#define ICU_PRIVATE_H_

#define PRESCALER_MASK_TIMER0       0b11111000

#define CLR_MASK_TIMER1             0b11111000



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



#define TCCR1A                 (*(volatile u8 *)(0x4F))
#define TCCR1A_WGM10                  0
#define TCCR1A_WGM11                  1
#define TCCR1A_FOC1B                  2
#define TCCR1A_FOC1A                  3
#define TCCR1A_COM1B0                 4
#define TCCR1A_COM1B1                 5
#define TCCR1A_COM1A0                 6
#define TCCR1A_COM1A1                 7

#define TCNT1H                 (*(volatile u8 *)(0x4D))


#define TCNT1L                 (*(volatile u8 *)(0x4C))




#define OCR1AH                 (*(volatile u8 *)(0x4B))

#define OCR1AL                 (*(volatile u8 *)(0x4A))

#define OCR1                   (*(volatile u16 *)(0x4A))

#define TCCR1B                 (*(volatile u8 *)(0x4E))
#define TCCR1B_CS10                    0
#define TCCR1B_CS11                    1
#define TCCR1B_CS12                    2
#define TCCR1B_WGM12                   3
#define TCCR1B_WGM13                   4
#define TCCR1B_ICES1                   6
#define TCCR1B_ICNC1                   7




#define OCR1BH                 (*(volatile u8 *)(0x49))

#define OCR1BL                 (*(volatile u8 *)(0x48))



#define ICR1H                 (*(volatile u8 *)(0x47))

#define ICR1L                 (*(volatile u8 *)(0x46))

#define ICR1                   (*(volatile u16 *)(0x46))

#define TIMSK                 (*(volatile u8 *)(0x59))
#define TIMSK_TOIE0                    0
#define TIMSK_OCIE0                    1
#define TIMSK_TOIE1                    2
#define TIMSK_OCIE1B                   3
#define TIMSK_OCIE1A                   4
#define TIMSK_TICIE1                   5
#define TIMSK_TOIE2                    6
#define TIMSK_OCIE2                    7


#endif /* ICU_PRIVATE_H_ */
