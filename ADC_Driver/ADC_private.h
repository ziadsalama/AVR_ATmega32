/*
 * ADC_private.h
 *
 *  Created on: Apr 4, 2023
 *      Author: ziads
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define MUX_MASK            224          /*  0b11100000 */
#define PRESCALER_MASK       0b11111000

#define SREG      (*(volatile u8 *)(0x5f))
#define SREG_I              7

#define ADMUX     (*(volatile u8 *)(0x27))

#define ADMUX_REFS1         7        //Reference Selection Bits
#define ADMUX_REFS0         6
#define ADMUX_ADLAR         5        //  ADC Left Adjust Result

#define ADCSRA      (*(volatile u8 *)(0x26))           //

#define ADCSRA_ADEN          7             //  ADC Enable
#define ADCSRA_ADSC          6            //   ADC Start Conversion
#define ADCSRA_ADATE         5            //   ADC Auto Trigger Enable
#define ADCSRA_ADIF          4           //  ADC Interrupt Flag
#define ADCSRA_ADIE          3          //   ADC Interrupt Enable
#define ADCSRA_ADPS2         2          // ADC Prescaler Selections
#define ADCSRA_ADPS1         1
#define ADCSRA_ADPS0         0

#define ADCH    (*(volatile u8 *)(0x25))



#define ADCL      (*(volatile u16 *)(0x24))



#define ADCR     *((volatile u16*)(0x24))      //ADC data register for 10 bit resolution

/* Auto Trigger Source */
 // ADATE bin in ADCSRA ==1    Select which source will trigger an ADC conversion  if =0 no effect
#define SFIOR      (*(volatile u8 *)(0x50))
#define SFIOR_ADTS0         5
#define SFIOR_ADTS1         6
#define SFIOR_ADTS2         7





#define _8_BITS              0
#define _10_BITS             1

#endif /* ADC_PRIVATE_H_ */
