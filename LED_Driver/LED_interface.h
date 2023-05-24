/*
 * LED_interface.h
 *
 *  Created on: Mar 27, 2023
 *      Author: ziads
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_


void LED_voidPinLedInit(u8 Copy_u8PortID , u8 Copy_u8Pin);

void LED_voidPortLedInit(u8 Copy_u8PortID);

void LED_voidLedOn(u8 Copy_u8PortID , u8 Copy_u8Pin);

void LED_voidLedOff(u8 Copy_u8PortID , u8 Copy_u8Pin);

void LED_voidToggleLed(u8 Copy_u8PortID , u8 Copy_u8Pin);

#endif /* LED_INTERFACE_H_ */
