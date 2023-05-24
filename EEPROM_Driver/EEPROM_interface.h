/*
 * EEPROM_interface.h
 *
 *  Created on: Apr 26, 2023
 *      Author: ziads
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_




void EEPROM_voidWriteDataByte(u8 Copy_u8DataByte , u16 Copy_u16ByteAddress);

void EEPROM_voidReadDataByte(u8* Copy_u8PDataByte , u16 Copy_u16ByteAddress);

#endif /* EEPROM_INTERFACE_H_ */
