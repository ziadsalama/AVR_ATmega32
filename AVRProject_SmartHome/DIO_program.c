
#include "std_macros.h"
#include "type_defs.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_CFG.h"

/**************************************************************************/
/***********************Functions_Implementation********************************/
/**************************************************************************/

void DIO_voidSetPinDircetion(u8 Copy_u8PortID ,u8 Copy_u8Pin ,u8 Copy_u8PinDirection )
{
	/*switching over ports*/
	switch(Copy_u8PortID)
	{
	/*in case of setting the direction of a pin in PORT A*/
	case DIO_PORTA :
		/*in case of setting the direction of a pin in port A*/
		switch(Copy_u8PinDirection)
		{
		/*in case of setting the pin to be output*/
		case DIO_PIN_OUTPUT :
			SET_BIT(DDRA , Copy_u8Pin);
			break;

			/*in case of setting the pin to be input float*/
		case DIO_PIN_INPUT_FLOAT :
			CLR_BIT(DDRA,Copy_u8Pin);
			break;

			/*in case of setting the pin to be input pull up*/
		case DIO_PIN_INPUT_PULLUP :
			CLR_BIT(DDRA,Copy_u8Pin);
			SET_BIT(PORTA , Copy_u8Pin);
			break;
		}
		break;
		/*in case of setting the direction of a pin in PORT B*/
		case DIO_PORTB :
			switch(Copy_u8PinDirection)
			{
			/*in case of setting the pin to be output*/
			case DIO_PIN_OUTPUT :
				SET_BIT(DDRB , Copy_u8Pin);
				break;

				/*in case of setting the pin to be input float*/
			case DIO_PIN_INPUT_FLOAT :
				CLR_BIT(DDRB,Copy_u8Pin);
				break;

				/*in case of setting the pin to be input pull up*/
			case DIO_PIN_INPUT_PULLUP :
				CLR_BIT(DDRB,Copy_u8Pin);
				SET_BIT(PORTB , Copy_u8Pin);
				break;
			}
			break;
			/*in case of setting the direction of a pin in PORT C*/
			case DIO_PORTC :
				switch(Copy_u8PinDirection)
				{
				/*in case of setting the pin to be output*/
				case DIO_PIN_OUTPUT :
					SET_BIT(DDRC , Copy_u8Pin);
					break;

					/*in case of setting the pin to be input float*/
				case DIO_PIN_INPUT_FLOAT :
					CLR_BIT(DDRC,Copy_u8Pin);
					break;

					/*in case of setting the pin to be input pull up*/
				case DIO_PIN_INPUT_PULLUP :
					CLR_BIT(DDRC,Copy_u8Pin);
					SET_BIT(PORTC, Copy_u8Pin);
					break;
				}
				break;
				/*in case of setting the direction of a pin in PORT D*/
				case DIO_PORTD :
					switch(Copy_u8PinDirection)
					{
					/*in case of setting the pin to be output*/
					case DIO_PIN_OUTPUT :
						SET_BIT(DDRD , Copy_u8Pin);
						break;

						/*in case of setting the pin to be input float*/
					case DIO_PIN_INPUT_FLOAT :
						CLR_BIT(DDRD,Copy_u8Pin);
						break;

						/*in case of setting the pin to be input pull up*/
					case DIO_PIN_INPUT_PULLUP :
						CLR_BIT(DDRD,Copy_u8Pin);
						SET_BIT(PORTD , Copy_u8Pin);
						break;
					}
					break;
	}
}



void DIO_voidSetPinValue(u8 Copy_u8PortID ,u8 Copy_u8Pin ,u8 Copy_u8PinValue)
{
	switch(Copy_u8PortID)
	{
	case DIO_PORTA :
		WRITE_BIT(PORTA,Copy_u8Pin,Copy_u8PinValue);
		break;
	case DIO_PORTB :
		WRITE_BIT(PORTB,Copy_u8Pin,Copy_u8PinValue);
		break;
	case DIO_PORTC :
		WRITE_BIT(PORTC,Copy_u8Pin,Copy_u8PinValue);
		break;
	case DIO_PORTD :
		WRITE_BIT(PORTD,Copy_u8Pin,Copy_u8PinValue);
		break;
	}
}
void DIO_voidSetPortDirection(u8 Copy_u8PortID , u8 Copy_u8PortValue)
{
	switch (Copy_u8PortID)
{
case DIO_PORTA :
	switch(Copy_u8PortValue)
	{
	case DIO_PORT_OUTPUT :
		DDRA =255;
		break;
	case DIO_PORT_INPUT_FLOAT :
		DDRA =0;
		break;
	case DIO_PORT_INPUT_PULLUP:
		DDRA =0;
		PORTA =255;
		break;
	}
	break;
	case DIO_PORTB :
		switch(Copy_u8PortValue)
		{
		case DIO_PORT_OUTPUT :
			DDRB =255;
			break;
		case DIO_PORT_INPUT_FLOAT :
			DDRB =0;
			break;
		case DIO_PORT_INPUT_PULLUP:
			DDRB =0;
			PORTB =255;
			break;
		}
		break;
		case DIO_PORTC :
			switch(Copy_u8PortValue)
			{
			case DIO_PORT_OUTPUT :
				DDRC =255;
				break;
			case DIO_PORT_INPUT_FLOAT :
				DDRC =0;
				break;
			case DIO_PORT_INPUT_PULLUP:
				DDRC =0;
				PORTC =255;
				break;
			}
			break;
			case DIO_PORTD :
				switch(Copy_u8PortValue)
				{
				case DIO_PORT_OUTPUT :
					DDRD =255;
					break;
				case DIO_PORT_INPUT_FLOAT :
					DDRD =0;
					break;
				case DIO_PORT_INPUT_PULLUP:
					DDRD =0;
					PORTD =255;
					break;
				}
				break;
}

}
u8 DIO_u8SetPortValue(u8 Copy_u8PortID , u8 Copy_u8PinValue)
{
	u8 Local_u8ErrorState =0;
	if(Copy_u8PinValue>=0&&Copy_u8PinValue<=255)
	{
		switch(Copy_u8PortID)
		{
		case DIO_PORTA :
			PORTA = Copy_u8PinValue;
			break;
		case DIO_PORTB :
			PORTB = Copy_u8PinValue;
			break;
		case DIO_PORTC :
			PORTC = Copy_u8PinValue;
			break;
		case DIO_PORTD :
			PORTD = Copy_u8PinValue;
			break;
		default:
			Local_u8ErrorState=1;
			break;
		}

	}
	else
	{
		Local_u8ErrorState =2;
	}
	return Local_u8ErrorState;
}
void DIO_voidTooglePin(u8 Copy_u8PortID , u8 Copy_u8Pin)
{
	switch(Copy_u8PortID)
	{
	case DIO_PORTA :
		TOGGLE_BIT(PORTA ,Copy_u8Pin );
		break;
	case DIO_PORTB :
		TOGGLE_BIT(PORTB ,Copy_u8Pin);
		break;
	case DIO_PORTC :
		TOGGLE_BIT(PORTC ,Copy_u8Pin);
		break;
	case DIO_PORTD :
		TOGGLE_BIT(PORTD ,Copy_u8Pin);
		break;
	}

}
u8 DIO_u8GetPinValue(u8 Copy_u8PortID , u8 Copy_u8Pin)
{
	u8 Local_u8PinValue;
	switch(Copy_u8PortID)
	{
	case DIO_PORTA :
		Local_u8PinValue = READ_BIT(PINA ,Copy_u8Pin );
		break;
	case DIO_PORTB :
		Local_u8PinValue = READ_BIT(PINB ,Copy_u8Pin );
		break;
	case DIO_PORTC :
		Local_u8PinValue = READ_BIT(PINC ,Copy_u8Pin );
		break;
	case DIO_PORTD :
		Local_u8PinValue = READ_BIT(PIND ,Copy_u8Pin );
		break;
	}
	return Local_u8PinValue;
}
