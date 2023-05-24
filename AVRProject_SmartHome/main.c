/*
 * main.c
 *
 *  Created on: May 12, 2023
 *      Author: Ziad
 */
#include "std_macros.h"
#include "type_defs.h"

#include <util/delay.h>
#include <string.h>

#include "DIO_interface.h"
#include "GIE_interface.h"
#include "Servo_interface.h"
#include "PWM_Timer1_interface.h"
#include "LCD_interface.h"
#include "UART_interface.h"
#include "EEPROM_interface.h"
#include "TWI_interface.h"
#include "Buzzer_inteface.h"
#include "ADC_interface.h"



u8 arr[]="  Enter Your ID \r ";
u8 Global_u8Iterator = 0 ;
u8 ID[11] ;
u8 Admin_ID[]="ZiadSalama";
u8 Admin_Pass[5] ;
u8 Admin_Pass_EEPROM[]="1998" ;
u8 Opening_msg[]=" \r Press 1 for Admin Mode or 2 for User Mode ";
u8 EnterAdmin_Pass[]=" \r Enter Admin_Pass = ";
u8 RightAdmin_Pass[]=" \r Right Admin_Pass \r ";
u8 Right_ID[]=" \r Right ID \r ";
u8 Wrong_ID[]=" \r Wrong ID \r ";
u8 Wrong_Pass[]=" \r Wrong Admin_Pass \r  ";
u8 First_Chance[]=" \r Try Entering the Right ID \r ";
u8 Second_Chance[]="  \r Try Entering the Right Admin_Pass \r   ";
u8 Invalid_Access[]=" \r Invalid Access System Closing  \r ";
u8 First_User[6];
u8 User1_Pass[6];
u8 Second_User[6];
u8 User2_Pass[6];
u8 Third_User[6];
u8 User3_Pass[6];
u8 Welcome_msg[]= " \r Welcome To Smart Home System \r ";
u8 Door_Control[]=" \r To Open Door Press 1 \r ";
u8 TV_Control[]=" \r To Open LCD TV Press 2 \r ";
u8 Led_Room[]=" \r To Turn Light ON Press 3 \r ";
u8 AC_Control[]="  \r To Set AC Press 4 \r ";
u8 Door_Close[]="  \r To Close Door Press 5 \r ";
u8 TV_Close[]=" \r To Close LCD TV Press 6 \r  ";
u8 LED_Close[]="  \r To Turn Light OFF Press 7 \r ";
u8 System_Close[]=" \r To  Close System Press 8 \r  ";

u8 Closing_msg[]="  Thank You For Using Smart Home  ";
u8 Global_u8ID_Flag = 0 ;
u8 Global_u8Admin_Pass_Flag =0 ;
u8 User_username[6];
u8 User_Admin_Pass[6];
u8 Control ;
u8 Data_Loaction=0;
u8 Data_Loaction_Remove=0;
u16 temp;
u16 ADC_Reading;


u8 Return_Of_User_ID = 1;
u8 Return_Of_User_Admin_Pass = 1;
u8 Return_Of_User1 = 1;
u8 Return_Of_User2 = 1;
u8 Return_Of_User3 = 1;
u8 Return_Of_User1_Admin_Pass = 1;
u8 Return_Of_User2_Admin_Pass = 1;
u8 Return_Of_User3_Admin_Pass = 1;


u8 User_Chossen_Mode = 0;

u8 Admin_choice_Mode = 0;

void main (void)
{
	GIE_voidEnable();
	ADC_voidInit();
	LCD_voidLCDInit();
	PWM_Timer1voidInit(OUTPUT_COMPARE_A);
	Set_PWM_Timer1_voidFrequency(50);
	Servo_voidStart(OUTPUT_COMPARE_A);
	Buzzer_voidInit(DIO_PORTB,DIO_PIN3);
	DIO_voidSetPinDircetion(DIO_PORTD,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_voidSetPinDircetion(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT);

	DIO_voidSetPinDircetion(DIO_PORTA,DIO_PIN0,DIO_PIN_INPUT_FLOAT);
	DIO_voidSetPinDircetion(DIO_PORTA,DIO_PIN1,DIO_PIN_OUTPUT);

	UART_t UART_Setting ;

	UART_Setting.Partiy=No_Parity;
	UART_Setting.Stop_Bits=One_BIT;
	UART_Setting.Mode_Node=Transfer_Recieve;
	UART_Setting.Data_Size=Eight_BITS;
	UART_Setting.Async_Sync=Async_Mode;

	UART_voidInit(&UART_Setting);

	TWI_voidMasterInit(0);

	EEPROM_u8SendStr(0,"ZiadSalama");
	EEPROM_u8SendStr(15,"1998");
	UART_voidSendString(Opening_msg);
	while(1)
	{
		UART_void_ReceiveDataSync(&User_Chossen_Mode);
		if(User_Chossen_Mode == '1')
		{
			while(Global_u8ID_Flag < 3)
			{
				UART_voidSendString(arr);
				UART_voidgetStringFromUser(ID, sizeof(ID));
				EEPROM_u8ReceiveStr(0,Admin_ID,sizeof(Admin_ID));
				Return_Of_User_ID = strcmp(ID,Admin_ID);
				if(Return_Of_User_ID == 0)
				{
					UART_voidSendString(Right_ID);
					Buzzer_voidSuccessAlarm(DIO_PORTB,DIO_PIN3);
					break;
				}
				else
				{
					_delay_ms(10);
					UART_voidSendString(First_Chance);
					Global_u8ID_Flag++;
				}
				if (Global_u8ID_Flag == 3)
				{
					UART_voidSendString(Invalid_Access);
					_delay_ms(10);
					while(1)
					{
						Buzzer_voidSafetyAlarm(DIO_PORTB,DIO_PIN3);
					}
				}
			}
			while(Global_u8Admin_Pass_Flag < 3)
			{
				UART_voidSendString(EnterAdmin_Pass);
				UART_voidgetStringFromUser(Admin_Pass, sizeof(Admin_Pass));
				EEPROM_u8ReceiveStr(15, Admin_Pass_EEPROM, sizeof(Admin_Pass_EEPROM));
				Return_Of_User_Admin_Pass = strcmp(Admin_Pass,Admin_Pass_EEPROM) ;
				if(Return_Of_User_Admin_Pass == 0)
				{
					UART_voidSendString(RightAdmin_Pass);
					Buzzer_voidSuccessAlarm(DIO_PORTB,DIO_PIN3);
					break;
				}
				else
				{
					_delay_ms(10);
					UART_voidSendString(Second_Chance);
					Global_u8Admin_Pass_Flag++;
				}
				if (Global_u8Admin_Pass_Flag == 3)
				{
					UART_voidSendString(Invalid_Access);
					_delay_ms(10);
					while(1)
					{
						Buzzer_voidSafetyAlarm(DIO_PORTB,DIO_PIN3);
					}
				}
			}
			UART_voidSendString("\r Welcome to Admin Mode \r Press 1 to add New User Name and Users_Pass \r Press 2 to Remove user \r Press 3 to reset Username and User_Pass \r ");
			UART_void_ReceiveDataSync(&Admin_choice_Mode);
			if(Admin_choice_Mode == '1')
			{
				UART_voidSendString("\r which User you a want to Add 1 , 2 ,3 ");
				UART_void_ReceiveDataSync(&Data_Loaction);
				if(Data_Loaction == '1')
				{
					UART_voidSendString("\r Enter User Name \r");
					USART_voidReciveString(First_User,6);
					EEPROM_u8SendStr(20,First_User);
					UART_voidSendString("\r User Name Added \r");
					UART_voidSendString("\r Enter User1_Pass \r");
					USART_voidReciveString(User1_Pass,6);
					EEPROM_u8SendStr(30,User1_Pass);
					UART_voidSendString("\r User1_Pass Added \r");
					UART_voidSendString(Opening_msg);
				}
				if(Data_Loaction == '2')
				{
					UART_voidSendString("\r Enter User Name \r");
					USART_voidReciveString(Second_User,6);
					EEPROM_u8SendStr(40,Second_User);
					UART_voidSendString("\r User Name Added \r");
					UART_voidSendString("\r Enter User2_Pass \r");
					USART_voidReciveString(User2_Pass,6);
					EEPROM_u8SendStr(50,User2_Pass);
					UART_voidSendString("\r User2_Pass Added \r");
					UART_voidSendString(Opening_msg);
				}
				if(Data_Loaction == '3')
				{
					UART_voidSendString("\r Enter User Name \r");
					USART_voidReciveString(Third_User,6);
					EEPROM_u8SendStr(60,Third_User);
					UART_voidSendString("\r User Name Added \r");
					UART_voidSendString("\r Enter User3_Pass \r");
					USART_voidReciveString(User3_Pass,6);
					EEPROM_u8SendStr(70,User3_Pass);
					UART_voidSendString("\r User3_Pass Added \r");
					UART_voidSendString(Opening_msg);
				}
			}
			else if(Admin_choice_Mode == '2')
			{
				UART_voidSendString("\r which User you a want to Remove 1 , 2 ,3 ");
				UART_void_ReceiveDataSync(&Data_Loaction_Remove);
				if(Data_Loaction_Remove == '1')
				{
					EEPROM_voidEraseData(20,37);
					UART_voidSendString("\r User Name and User1_Pass Removed \r");
					UART_voidSendString(Opening_msg);
				}
				if(Data_Loaction_Remove == '2')
				{
					EEPROM_voidEraseData(40,57);
					UART_voidSendString("\r User Name and User2_Pass Removed \r");
					UART_voidSendString(Opening_msg);
				}
				if(Data_Loaction_Remove == '3')
				{
					EEPROM_voidEraseData(60,77);
					UART_voidSendString("\r User Name and User3_Pass Removed \r");
					UART_voidSendString(Opening_msg);
				}
			}
			else if (Admin_choice_Mode == '3')
			{
				EEPROM_voidEraseData(20,90);
				UART_voidSendString("\r All User Name is Removed Make sure to add Username before proceeding \r");
				UART_voidSendString(Opening_msg);
			}
		}
		else if(User_Chossen_Mode == '2')
		{
			while(1)
			{
				UART_voidSendString("\r Enter User Name \r");
				UART_voidgetStringFromUser(User_username,sizeof(User_username));
				Return_Of_User1 = strcmp(User_username,First_User) ;
				Return_Of_User2 = strcmp(User_username,Second_User) ;
				Return_Of_User3 = strcmp(User_username,Third_User) ;
				if(Return_Of_User1 == 0 || Return_Of_User2 == 0 || Return_Of_User3 ==0 )
				{
					UART_voidSendString("\r Valid User Name \r");
					Buzzer_voidSuccessAlarm(DIO_PORTB,DIO_PIN3);
					break;
				}
				else
				{
					UART_voidSendString("\r Enter a Valid User Name : \r");
				}
			}
			while(1)
			{
				UART_voidSendString("\r Enter Admin_Pass \r");
				UART_voidgetStringFromUser(User_Admin_Pass,sizeof(User_Admin_Pass));
				Return_Of_User1_Admin_Pass = strcmp(User_Admin_Pass,User1_Pass) ;
				Return_Of_User2_Admin_Pass = strcmp(User_Admin_Pass,User2_Pass) ;
				Return_Of_User3_Admin_Pass = strcmp(User_Admin_Pass,User3_Pass) ;
				if(Return_Of_User1_Admin_Pass == 0 || Return_Of_User2_Admin_Pass == 0 || Return_Of_User3_Admin_Pass ==0 )
				{
					UART_voidSendString(RightAdmin_Pass);
					Buzzer_voidSuccessAlarm(DIO_PORTB,DIO_PIN3);
					UART_voidSendString(Welcome_msg);
					UART_voidSendString(Door_Control);
					UART_voidSendString(TV_Control);
					UART_voidSendString(Led_Room);
					UART_voidSendString(AC_Control);
					UART_voidSendString(Door_Close);
					UART_voidSendString(TV_Close);
					UART_voidSendString(LED_Close);
					UART_voidSendString(System_Close);
					while(1)
					{
						temp = ADC_u8GetChannelReading(ADC_CHANNEL0);
						ADC_Reading = ((u32)temp * 5000UL) / 1024UL;
						if ((ADC_Reading/10) >= 30)
						{
							DIO_voidSetPinValue(DIO_PORTA, DIO_PIN1, DIO_HIGH_PIN);
						}
						else
						{
							DIO_voidSetPinValue(DIO_PORTA, DIO_PIN1, DIO_LOW_PIN);
						}
						UART_void_ReceiveDataSync(&Control);
						if (Control == '1' )
						{
							Servo_voidSetAngle(OUTPUT_COMPARE_A,180);
							PWM_Timer1voidStart();
						}
						if (Control == '2' )
						{
							LCD_voidSendString("Hello Sir");
							LCD_u8GoToRowCol(1,0);
							LCD_voidSendString("Welcome :)");
						}
						if (Control == '3' )
						{
							DIO_voidSetPinValue(DIO_PORTD,DIO_PIN3,DIO_HIGH_PIN);
						}
						if (Control == '4')
						{

						}
						if (Control == '5')
						{
							Servo_voidSetAngle(OUTPUT_COMPARE_A,0);
							PWM_Timer1voidStart();
							DIO_voidSetPinValue(DIO_PORTC,DIO_PIN1,DIO_HIGH_PIN);
						}
						if (Control == '6')
						{
							LCD_voidLCDSendCommand(0x01);
						}
						if (Control == '7')
						{
							DIO_voidSetPinValue(DIO_PORTD,DIO_PIN3,DIO_LOW_PIN);
						}
						if (Control == '8')
						{
							UART_voidSendString(Closing_msg);
							while(1)
							{

							}
						}
					}
					break;
				}
				else
				{
					UART_voidSendString("\r Enter a Valid Admin_Pass : \r");
				}
			}
		}
		else
		{
			UART_voidSendString("\r Please enter 1 or 2 only  \r");
		}
	}

}



