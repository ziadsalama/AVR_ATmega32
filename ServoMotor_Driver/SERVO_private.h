/*
 * SERVO_private.h
 *
 *  Created on: Apr 12, 2023
 *      Author: ziads
 */

#ifndef SERVO_PRIVATE_H_
#define SERVO_PRIVATE_H_


#define CLR_MASK             0b11111000

#define PRESCALER_MASK_8          2


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

#define OCR1A                   (*(volatile u16 *)(0x4A))

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

#define OCR1B                   (*(volatile u8 *)(0x48))

#define ICR1H                 (*(volatile u8 *)(0x47))

#define ICR1L                 (*(volatile u8 *)(0x46))

#define ICR1                   (*(volatile u16 *)(0x46))

#endif /* SERVO_PRIVATE_H_ */
