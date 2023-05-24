/*****************************************************************************/
/*Author      : Mohammed Essam										         */
/*File Name   : ADC_private.h                                                */
/*Layer       : MCAL	    						 			     	     */
/*Description : This file contains private folders of ADC module             */
/*Date        : 19 May 2023                                                  */
/*****************************************************************************/


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_



#define ADMUX    *((volatile u8 *)(0x27))      	 //ADC multiplexer selection register
#define ADMUX_REFS1                    7         //for reference voltage selection bit1
#define ADMUX_REFS0                    6         //for reference voltage selection bit0
#define ADMUX_ADLAR                    5         //Set left adjustment


#define ADCSRA   *((volatile u8 *)(0x26))      //ADC control and status registerA
#define ADCSRA_ADEN                    7         //for ADC enable
#define ADCSRA_ADSC                    6         //for ADC start conversion
#define ADCSRA_ADATE                   5         //for ADC auto trigger enable
#define ADCSRA_ADIF                    4         //for ADC interrupt flag
#define ADCSRA_ADIE                    3         //for ADC interrupt enable
#define ADCSRA_ADP2                    2         //for ADC clock prescaler bit 2
#define ADCSRA_ADP1                    1         //for ADC clock prescaler bit 1
#define ADCSRA_ADP0                    0         //for ADC clock prescaler bit 0

#define ADCH     *((volatile u8 *)(0x25))      //ADC high register
#define ADCL     *((volatile u8 *)(0x24))      //ADC low register

#define SFIOR    *((volatile u8 *)(0x50))      //ADC special function IO register
#define ADCR     *((volatile u16*)(0x24))      //ADC data register for 10 bit resolution

#define MUX_MASK					0b11100000
#define PRESC_MASK					0b11111000

#define DIV_BY_2			1
#define DIV_BY_4			2
#define DIV_BY_8			3
#define DIV_BY_16			4
#define DIV_BY_32			5
#define DIV_BY_64			6
#define DIV_BY_128			7

#define _8_BIT				1
#define _10_BIT				2

#define AVCC				1
#define VAR_AREF			2
#define CONST_AREF			3

#endif
