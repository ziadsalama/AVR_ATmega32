/**************************************************************************/
/*Author      : Ziad Salama										      */
/*File Name   : DIO_program.c                                             */
/*Layer       : MCAL										  		      */
/*Description : This file contains functions' implemetation of DIO module */
/*Date        : 22 March 2023                                             */
/**************************************************************************/



#include "std_macros.h"
#include "type_defs.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_cfg.h"




/******************************************************************************/
/*************************Functions' implementation****************************/
/******************************************************************************/

void DIO_voidSetPinDirection(u8 Copy_u8PortID , u8 Copy_u8Pin , u8 Copy_u8PinDirection)
{
	/*switching over ports*/
	switch(Copy_u8PortID)
	{
		/*in case of setting the direction of a pin in port A*/
		case DIO_PORTA :

			/*switch over different directions*/
			switch(Copy_u8PinDirection)
			{
				/*in case of setting the pin to be output*/
				case DIO_PIN_OUTPUT :
					SET_BIT(DDRA , Copy_u8Pin);
					break ;

				/*in case of setting the pin direction to be input float*/
				case DIO_PIN_INPUT_FLOAT :
					CLR_BIT(DDRA , Copy_u8Pin);
					break ;

				/*in case of setting the pin direction to be input pull up*/
				case DIO_PIN_INPUT_PULLUP :
					CLR_BIT(DDRA , Copy_u8Pin);
					SET_BIT(PORTA , Copy_u8Pin);
					break ;
			}
			break ;

/******************************************************************************/

		/*in case of setting the direction of a pin in port B*/
		case DIO_PORTB :

			/*switch over different directions*/
			switch(Copy_u8PinDirection)
			{
				/*in case of setting the pin to be output*/
				case DIO_PIN_OUTPUT :
					SET_BIT(DDRB , Copy_u8Pin);
					break ;

				/*in case of setting the pin direction to be input float*/
				case DIO_PIN_INPUT_FLOAT :
					CLR_BIT(DDRB , Copy_u8Pin);
					break ;

				/*in case of setting the pin direction to be input pull up*/
				case DIO_PIN_INPUT_PULLUP :
					CLR_BIT(DDRB , Copy_u8Pin);
					SET_BIT(PORTB , Copy_u8Pin);
					break ;
			}

			break ;

/******************************************************************************/

		/*in case of setting the direction of a pin in port C*/
		case DIO_PORTC :

			/*switch over different directions*/
			switch(Copy_u8PinDirection)
			{
				/*in case of setting the pin to be output*/
				case DIO_PIN_OUTPUT :
					SET_BIT(DDRC , Copy_u8Pin);
					break ;

				/*in case of setting the pin direction to be input float*/
				case DIO_PIN_INPUT_FLOAT :
					CLR_BIT(DDRC , Copy_u8Pin);
					break ;

				/*in case of setting the pin direction to be input pull up*/
				case DIO_PIN_INPUT_PULLUP :
					CLR_BIT(DDRC , Copy_u8Pin);
					SET_BIT(PORTC , Copy_u8Pin);
					break ;
			}

			break ;

/******************************************************************************/

		/*in case of setting the direction of a pin in port D*/
		case DIO_PORTD :

			/*switch over different directions*/
			switch(Copy_u8PinDirection)
			{
				/*in case of setting the pin to be output*/
				case DIO_PIN_OUTPUT :
					SET_BIT(DDRD , Copy_u8Pin);
					break ;

				/*in case of setting the pin direction to be input float*/
				case DIO_PIN_INPUT_FLOAT :
					CLR_BIT(DDRD , Copy_u8Pin);
					break ;

				/*in case of setting the pin direction to be input pull up*/
				case DIO_PIN_INPUT_PULLUP :
					CLR_BIT(DDRD , Copy_u8Pin);
					SET_BIT(PORTD , Copy_u8Pin);
					break ;
			}
			break ;
	}
}



void DIO_voidSetPinValue(u8 Copy_u8PortID , u8 Copy_u8Pin , u8 Copy_u8PinValue)
{
	    /*switching over ports*/
		switch(Copy_u8PortID)
		{
			/*in case of setting the direction of a pin in port A*/
			case DIO_PORTA :
				WRITE_BIT(PORTA , Copy_u8Pin , Copy_u8PinValue);
				break ;

			/*in case of setting the direction of a pin in port B*/
			case DIO_PORTB :
				WRITE_BIT(PORTB , Copy_u8Pin , Copy_u8PinValue);
				break ;

			/*in case of setting the direction of a pin in port C*/
			case DIO_PORTC :
				WRITE_BIT(PORTC , Copy_u8Pin , Copy_u8PinValue);
				break ;

			/*in case of setting the direction of a pin in port D*/
			case DIO_PORTD :
				WRITE_BIT(PORTD , Copy_u8Pin , Copy_u8PinValue);
				break ;
		}
}



void DIO_voidSetPortDirection(u8 Copy_u8PortID  , u8 Copy_u8PortDirection)
{
    /*switching over ports*/
	switch(Copy_u8PortID)
	{
			/*in case of setting the direction of port A*/
			case DIO_PORTA :

				switch(Copy_u8PortDirection)
				{
					case DIO_PORT_OUTPUT :
						DDRA = 255 ;
						break ;

					case DIO_PORT_INPUT_FLOAT :
						DDRA = 0 ;
						break ;

					case DIO_PORT_INPUT_PULLUP :
						DDRA = 0 ;
						PORTA = 255 ;
						break ;
				}
				break ;

			/*in case of setting the direction of port B*/
			case DIO_PORTB :

				switch(Copy_u8PortDirection)
				{
					case DIO_PORT_OUTPUT :
						DDRB = 255 ;
						break ;

					case DIO_PORT_INPUT_FLOAT :
						DDRB = 0 ;
						break ;

					case DIO_PORT_INPUT_PULLUP :
						DDRB = 0 ;
						PORTB = 255 ;
						break ;
				}
				break ;

			/*in case of setting the direction of port C*/
			case DIO_PORTC :
				switch(Copy_u8PortDirection)
				{
					case DIO_PORT_OUTPUT :
						DDRC = 255 ;
						break ;

					case DIO_PORT_INPUT_FLOAT :
						DDRC = 0 ;
						break ;

					case DIO_PORT_INPUT_PULLUP :
						DDRC  = 0 ;
						PORTC = 255 ;
						break ;
				}
				break ;

			/*in case of setting the direction of port D*/
			case DIO_PORTD :
				switch(Copy_u8PortDirection)
				{
					case DIO_PORT_OUTPUT :
						DDRD = 255 ;
						break ;

					case DIO_PORT_INPUT_FLOAT :
						DDRD = 0 ;
						break ;

					case DIO_PORT_INPUT_PULLUP :
						DDRD  = 0 ;
						PORTD = 255 ;
						break ;
				}

				break ;
	}

}

u8 DIO_u8SetPortValue(u8 Copy_u8PortID  , u8 Copy_u8PortValue)
{
	 /*this local variable is for error reporting*/
	 /*initially = 0 (ok)*/
	 u8 Local_u8ErrorState = 0 ;

	/*checking for valid port value range*/
	if(Copy_u8PortValue >= 0 && Copy_u8PortValue <=255)
	{
		/*switching over ports*/
		switch(Copy_u8PortID)
		{
			/*in case of setting the direction of a pin in port A*/
			case DIO_PORTA :
				PORTA = Copy_u8PortValue ;
				break ;

			/*in case of setting the direction of a pin in port B*/
			case DIO_PORTB :
				PORTB = Copy_u8PortValue ;
				break ;

			/*in case of setting the direction of a pin in port C*/
			case DIO_PORTC :
				PORTC = Copy_u8PortValue ;
				break ;

			/*in case of setting the direction of a pin in port D*/
			case DIO_PORTD :
				PORTD = Copy_u8PortValue ;
				break ;

			default :
				/*in case of invalid port ID*/
				Local_u8ErrorState = 1 ;
				break ;
		}
	}

	else
	{
		/*in case of port value out of valid range*/
		Local_u8ErrorState = 2 ;
	}

	/*return the error state*/
	return Local_u8ErrorState ;

}

void DIO_voidTogglePin(u8 Copy_u8PortID , u8 Copy_u8Pin)
{
	/*switching over ports*/
		switch(Copy_u8PortID)
		{
			case DIO_PORTA :
				TOGGLE_BIT(PORTA,Copy_u8Pin);
				break;
			case DIO_PORTB :
				TOGGLE_BIT(PORTB,Copy_u8Pin);
				break;
			case DIO_PORTC :
				TOGGLE_BIT(PORTC,Copy_u8Pin);
				break;
			case DIO_PORTD :
				TOGGLE_BIT(PORTD,Copy_u8Pin);
				break;
		}
}
u8 DIO_u8GetPinValue(u8 Copy_u8PortID , u8 Copy_u8Pin)
{
	u8 Local_u8PinValue;

	switch(Copy_u8PortID)
	{
	case DIO_PORTA :
		Local_u8PinValue = READ_BIT(PINA,Copy_u8Pin);
		break;
	case DIO_PORTB :
		Local_u8PinValue = READ_BIT(PINB,Copy_u8Pin);
		break;
	case DIO_PORTC :
		Local_u8PinValue = READ_BIT(PINC,Copy_u8Pin);
		break;
	case DIO_PORTD :
		Local_u8PinValue = READ_BIT(PIND,Copy_u8Pin);
		break;
	}
	return Local_u8PinValue;
}
