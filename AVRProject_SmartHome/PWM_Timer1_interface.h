/*
 * PWM_Timer1_interface.h
 *
 *  Created on: Apr 8, 2023
 *      Author: moham
 */

#ifndef PWM_TIMER1_INTERFACE_H_
#define PWM_TIMER1_INTERFACE_H_

#define OUTPUT_COMPARE_A   0
#define OUTPUT_COMPARE_B   1

/*PWM mode Initialization*/
void PWM_Timer1voidInit(u8 Copy_u16Channel);
/*Setting frequency of PWM*/
void Set_PWM_Timer1_voidFrequency(u32 Copy_u32Frequency);
/*Set Duty Cycle for PWM */
void Set_Duty_Cycle_PWM_Timer1_void(u8 Copy_u16Channel,u16 Copy_u16Percent);
/*PWM Start*/
void PWM_Timer1voidStart(void);



#endif /* PWM_TIMER1_INTERFACE_H_ */
