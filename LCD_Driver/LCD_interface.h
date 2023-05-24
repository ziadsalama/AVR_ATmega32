/*
 * LCD_interface.h
 *
 *  Created on: Mar 28, 2023
 *      Author: ziads
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_



void LCD_void_Init(void);

void LCD_voidSendCommand(u8 command);

void LCD_voidSendCharacter(u8 character);

void LCD_voidSendString(u8 arr[]);


u8 LCD_u8GoToRowCol(u8 copy_u8Row, u8 copy_u8Column);

/*  this function shall display a character on a specific cell on lcd */
void LCD_voidSendSpecialCharacter(u8* copy_pu8pattern, u8 copy_u8location,u8 copy_u8Row, u8 copy_u8Column );


void lcd_write_number(u32 number);


#endif /* LCD_INTERFACE_H_ */
