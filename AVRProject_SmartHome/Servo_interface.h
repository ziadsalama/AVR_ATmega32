/*
 * Servo_interface.h
 *
 *  Created on: Apr 9, 2023
 *      Author: moham
 */

#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

void Servo_voidStart(u8 Copy_u16Channel);
void Servo_voidSetAngle( u8 Copy_u16Channel , u16 Copy_u16Angle);
void Servo_voidStop(void);
#endif /* SERVO_INTERFACE_H_ */
