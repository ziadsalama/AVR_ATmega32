/*
 * UART_private.h
 *
 *  Created on: Apr 10, 2023
 *      Author: moham
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define UCSRA   *((volatile u8 *)(0x2b))

#define MPCM 0
#define U2X  1
#define PE   2
#define DOR  3
#define FE   4
#define UDRE 5
#define TXC  6
#define RXC  7

#define UCSRB   *((volatile u8 *)(0x2a))

#define TXB8    0
#define RXB8    1
#define UCSZ2   2
#define TXEN    3
#define RXEN    4
#define UDRIE   5
#define TXCIE   6
#define RXCIE   7

#define UCSRC   *((volatile u8 *)(0x40)) //In Order to write in this Register URSEL must be HIGH

#define URSEL    7
#define UMSEL    6
#define UPM1     5
#define UPM0     4
#define USBS     3
#define UCSZ1    2
#define UCSZ0    1
#define UCPOL    0

#define UBRRH   *((volatile u8 *)(0x40))

#define UBRRL   *((volatile u8 *)(0x29))

#define UDR     *((volatile u8 *)(0x2c))

//#define UCSRC_VALUE  0b11000110

#define BaudRate    51






#endif /* UART_PRIVATE_H_ */
