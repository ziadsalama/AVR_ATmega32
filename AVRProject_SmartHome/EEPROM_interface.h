/****************************************************************************/
/*Author      : Mohammed Essam										        */
/*File Name   : EEPROM_interface.h                                          */
/*Layer       : HAL	    							  			     	    */
/*Description : This file contains Interfacing parameters of EEPROM module  */
/*Date        : 19 May 2023                                                 */
/****************************************************************************/

/******** Guard *********/
#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

/*************************************************************************/
/*************************Functions' prototypes***************************/
/*************************************************************************/

/*This Function Shall Send Data to EEPROM*/
void EEPROM_voidSendByte(u16 Copy_u16Address,u8 Copy_u8Data);

/*This Function Shall Read Data from EEPROM*/
u8 EEPROM_u8ReceiveByte(u16 Copy_u16Address);

/*This Function Shall Read String From EEPROM*/
void EEPROM_u8ReceiveStr(u16 Copy_u16Address,u8* Copy_u8Str, u8 Copy_strlength);

/*This Function Shall Send String to EEPROM*/
void EEPROM_u8SendStr(u16 Copy_u16Address,u8* Copy_u8Str);

/*This Function Allows user to erase Data location in EEPROM */
void EEPROM_voidEraseDataByte(u16 Copy_u16Address);
/*This Function Allows user to erase Data in locations from a range to another in EEPROM */
void EEPROM_voidEraseData(u16 Copy_u16FirstAddress, u16 Copy_u16SecondAddress);


#endif /* EEPROM_INTERFACE_H_ */
