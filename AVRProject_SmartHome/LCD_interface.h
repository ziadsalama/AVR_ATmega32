
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


void LCD_voidLCDInit(void);

void LCD_voidLCDSendCommand(u8 Copy_u8CMD);

void LCD_voidLCDSendCharacter(u8 Copy_u8Character);

void LCD_voidSendString(u8 Array[]);

u8 LCD_u8GoToRowCol(u8 Copy_u8Row, u8 Copy_u8Colum);

void LCD_voidSendSpecialCharacter(u8 * Copy_pu8Pattern , u8 Copy_u8Location , u8 Copy_u8Row , u8 Copy_u8Colum);

void LCD_voidSendNumber(u32 Copy_u32Number);

void LCD_voidStop(void);

#endif
