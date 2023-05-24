/*
 * Buzzer_inteface.h
 *
 *  Created on: May 17, 2023
 *      Author: moham
 */

#ifndef BUZZER_INTEFACE_H_
#define BUZZER_INTEFACE_H_


#define DO1 100
#define RE  150
#define MI  200
#define FA  250
#define SO  300
#define LA  350
#define TI  400
#define DO2 450

void Buzzer_voidInit(u8 Copy_u8Port_ID , u8 Copy_u8Pin_ID);

void Buzzer_voidToneSelector(u32 Copy_u8Tone,u8 Copy_u8Port_ID , u8 Copy_u8Pin_ID);

void Buzzer_voidSafetyAlarm(u8 Copy_u8Port_ID , u8 Copy_u8Pin_ID);

void Buzzer_voidSuccessAlarm(u8 Copy_u8Port_ID , u8 Copy_u8Pin_ID);

#endif /* BUZZER_INTEFACE_H_ */
