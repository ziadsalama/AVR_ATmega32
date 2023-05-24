/**************************************************************************/
/*Author:Moammed                                                          */
/*File Name : DIO_interface.h										      */
/*Layer: MCAL                                                             */
/*Description : This file contains interfacing parameters of DIO module   */
/*Date : 22 March 2023                                                    */
/**************************************************************************/

/*preprocessor header file guard*/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/**************************************************************************/
/***********************Interfacing macros********************************/
/**************************************************************************/

/*Possible port IDs*/
#define DIO_PORTA         0
#define DIO_PORTB         1
#define DIO_PORTC         2
#define DIO_PORTD         3

/*Possible pin number */
#define DIO_PIN0          0
#define DIO_PIN1          1
#define DIO_PIN2          2
#define DIO_PIN3          3
#define DIO_PIN4          4
#define DIO_PIN5          5
#define DIO_PIN6          6
#define DIO_PIN7          7

/*Possible pin directions */
#define DIO_PIN_OUTPUT          0
#define DIO_PIN_INPUT_FLOAT     1
#define DIO_PIN_INPUT_PULLUP    2

/*Possible output pins values*/
#define DIO_LOW_PIN             0
#define DIO_HIGH_PIN            1

/*Possible output pins values*/
#define DIO_LOW_PORT             0x00
#define DIO_HIGH_PORT            0xff

/*Possible Port Directions*/
#define DIO_INPUT_PORT             0x00
#define DIO_OUTPUT_PORT            0xff

/*Possible  port directions*/
#define DIO_PORT_OUTPUT           0
#define DIO_PORT_INPUT_FLOAT      1
#define DIO_PORT_INPUT_PULLUP     2
/**************************************************************************/
/***********************Functions prototype********************************/
/**************************************************************************/




/*this function shall set the direction of a specific pin*/
void DIO_voidSetPinDircetion(u8 Copy_u8PortID ,u8 Copy_u8Pin ,u8 Copy_u8PinDirection );

/*this function shall set Value of a specific pin*/
void DIO_voidSetPinValue(u8 Copy_u8PortID ,u8 Copy_u8Pin ,u8 Copy_u8PinValue);

/*this function is to set the value of a specific port*/
void DIO_voidSetPortDirection(u8 Copy_u8PortID , u8 Copy_u8PortDirection);

/*this function is to set the value of a specific port*/
u8 DIO_u8SetPortValue(u8 Copy_u8PortID , u8 Copy_u8PinValue);

/*this function is to toggle the pin value*/
void DIO_voidTooglePin(u8 Copy_u8PortID , u8 Copy_u8Pin);
/*this function is to read value of a certain pin*/
u8 DIO_u8GetPinValue(u8 Copy_u8PortID , u8 Copy_u8Pin);

#endif /* DIO_INTERFACE_H_ */
