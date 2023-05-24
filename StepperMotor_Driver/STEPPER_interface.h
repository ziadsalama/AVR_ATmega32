/*
 * STEPPER_interface.h
 *
 *  Created on: Apr 2, 2023
 *      Author: ziads
 */

#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_


void STEPPER_voidInit();

void STEPPER_voidForward();

void STEPPER_voidBackward();

void STEPPER_voidCWWithAngel(u8 Copy_u8Degree);
void STEPPER_voidCCWWithAngel(u8 Copy_u8Degree);

void STEPPER_voidStop();


#endif /* STEPPER_INTERFACE_H_ */
