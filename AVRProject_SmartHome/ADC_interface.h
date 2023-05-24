/*****************************************************************************/
/*Author      : Mohammed Essam										         */
/*File Name   : ADC_interface.h                                              */
/*Layer       : MCAL	    						 			     	     */
/*Description : This file contains functions of ADC module                   */
/*Date        : 19 May 2023                                                  */
/*****************************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC_CHANNEL0		0
#define ADC_CHANNEL1		1
#define ADC_CHANNEL2		2
#define ADC_CHANNEL3		3
#define ADC_CHANNEL4		4
#define ADC_CHANNEL5		5
#define ADC_CHANNEL6		6
#define ADC_CHANNEL7		7





/*this function shall initialize ADC peripheral for 8bit*/
void ADC_voidInit(void);



/*start conversion and return the data*/
void ADC_u8StartConversion(u8 Copy_u8Channel, u8 *Copy_u8Reading);


/*this function shal return the reading using 8bit mode*/
u8 ADC_u8GetChannelReading(u8 Copy_u8Channel);




/*callback*/
void ADC_voidSetCallBack(void(*Copy_ptrToFunction)(void));






#endif
