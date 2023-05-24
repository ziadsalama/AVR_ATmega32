/*
 * TIMER1_interface.h
 *
 *  Created on: Apr 8, 2023
 *      Author: ziads
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_




void TIMER1_voidRunServoMotor(void);


void TIMER1_voidSetAngel(u16 Copy_u8Reading);

void TIMER1_voidDelaySync(f64 Copy_f64MilleSecond);

void TIMER1_voidDelayAsync(f64 Copy_f64MilleSecond,void(*PtrToFuncCallBack)(void));


#endif /* TIMER1_INTERFACE_H_ */
