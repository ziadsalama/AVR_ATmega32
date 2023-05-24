/*
 * PB_interface.h
 *
 *  Created on: Mar 31, 2023
 *      Author: ziads
 */

#ifndef PB_INTERFACE_H_
#define PB_INTERFACE_H_




void PB_voidInit(u8 Copy_u8PBPortID , u8 Copy_u8PBPin , u8 Copy_u8PBConnection );

u8  PB_u8GetStatus(u8 Copy_u8PBPortID , u8 Copy_u8PBPin , u8 Copy_u8PBConnection );

#endif /* PB_INTERFACE_H_ */
