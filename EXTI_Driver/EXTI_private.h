/*
 * EXTI_private.h
 *
 *  Created on: Apr 2, 2023
 *      Author: ziads
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_


#define INT0    0
#define INT1    1
#define INT2    2


#define LOW_LEVEL      0
#define ON_CHANGE      1
#define FALLING_EDGE   2
#define RISING_EDGE    3






#define MCUCR     (*(volatile u8 *)(0x55))

#define MCUCR_ISC00            0
#define MCUCR_ISC01            1
#define MCUCR_ISC10            2
#define MCUCR_ISC11            3

#define SREG      (*(volatile u8 *)(0x5F))           // enable global interrupt
#define SREG_I                 7

#define MCUCSR    (*(volatile u8 *)(0x54))

#define MCUCSR_ISC2            6     // for sense signal for interrupt 2

#define GICR      (*(volatile u8 *)(0x5B))

#define GICR_INT0              6    // enable interrupt 0
#define GICR_INT1              7
#define GICR_INT2              5

#define GIFR      (*(volatile u8 *)(0x5A))

#define GIFR_INTF0             6
#define GIFR_INTF1             7
#define GIFR_INTF2             5

#endif /* EXTI_PRIVATE_H_ */
