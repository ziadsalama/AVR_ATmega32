/*
 * KYPD_cfg.h
 *
 *  Created on: Mar 31, 2023
 *      Author: ziads
 */

#ifndef KYPD_CFG_H_
#define KYPD_CFG_H_


/*   configration for the port connected with kypad */
/*  avilable configuration  DIO_PORTA , DIO_PORTB. DIO_PORTC, DIO_PORTD*/
#define KPD_PORT     DIO_PORTC

/**/
#define KPD_ROW0   DIO_PIN0
#define KPD_ROW1   DIO_PIN1
#define KPD_ROW2   DIO_PIN2
#define KPD_ROW3   DIO_PIN3



#define KPD_COL0   DIO_PIN4
#define KPD_COL1   DIO_PIN5
#define KPD_COL2   DIO_PIN6
#define KPD_COL3   DIO_PIN7


#define COL_NUM     4
#define ROW_NUM     4


#define KPD_VALUES   {{'a','b','c','d'},{'e','f','g','h'},{'i','j','k','l'},{'m','n','o','p'}};

#define KPD_NO_PRESSED_KEY  1


#endif /* KYPD_CFG_H_ */
