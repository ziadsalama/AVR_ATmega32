/*
 * ADC_interface.h
 *
 *  Created on: Apr 4, 2023
 *      Author: ziads
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/*  possible _8_BIT or _10_BIT*/
#define LADJUST              _8_BITS



#define ADC_CHANNEL0             0
#define ADC_CHANNEL1             1
#define ADC_CHANNEL2             2
#define ADC_CHANNEL3             3
#define ADC_CHANNEL4             4
#define ADC_CHANNEL5             5
#define ADC_CHANNEL6             6
#define ADC_CHANNEL7             7




#define PRESCALER_2              1
#define PRESCALER_4              2
#define PRESCALER_8              3
#define PRESCALER_16             4
#define PRESCALER_32             5
#define PRESCALER_64             6
#define PRESCALER_128            7



void ADC_voidInit(void);

void ADC_voidStartConversion(u8 Copy_u8Channel ,u8* Copy_u8Reading);

void ADC_voidStartConversionSync(u8 Copy_u8Channel ,u8* Copy_u8Reading);


void ADC_voidSetCallBack(void(*Copy_ptrToFunction)(void));

void ADC_voidInitWithPrescaler(u8 Copy_u8Prescaler);

#endif /* ADC_INTERFACE_H_ */
