/*
 * EXTI_interface.h
 *
 *  Created on: Apr 2, 2023
 *      Author: ziads
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*  Avilable Signal to Choose  LOW_LEVEL - ON_CHANGE - FALLING_EDGE - RISING_EDGE   */
#define SENSED_SIGNAL              LOW_LEVEL





void Enable_Interrupt(u8 Copy_u8IntId);

void Disable_Interrupt(u8 Copy_u8IntId);

void Set_Sense_Signal_INT0(u8 Copy_u8Signal);

void Set_Sense_Signal_INT1(u8 Copy_u8Signal);
void Set_Sense_Signal_INT2(u8 Copy_u8Signal);

/*External Interrupt Initialization RunTime*/
void EXTI_voidINT0Init(u8 Copy_u8SenseSignal);
void EXTI_voidINT1Init(u8 Copy_u8SenseSignal);
void EXTI_voidINT2Init(u8 Copy_u8SenseSignal);

/*External Interrupt Initialization Pre Build*/
void EXTI_voidINT0InitPreBuild(u8 Copy_u8SenseSignal);
void EXTI_voidINT1InitPreBuild(u8 Copy_u8SenseSignal);
void EXTI_voidINT2InitPreBuild(u8 Copy_u8SenseSignal);



void EXTI_voidInt1Init(void);
/* call back*/
void EXTI_voidSetCallBackINT1(void(*Copy_ptrToFunc)(void));

void EXTI_voidSetCallBackINT0(void(*Copy_ptrToFunc)(void));

void EXTI_voidSetCallBackINT2(void(*Copy_ptrToFunc)(void));



#endif /* EXTI_INTERFACE_H_ */
