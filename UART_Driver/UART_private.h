/*
 * UART_private.h
 *
 *  Created on: Apr 10, 2023
 *      Author: ziads
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_


#define UDR               (*(volatile u8 *)(0x2C))           /* Data Register */

#define UCSRA             (*(volatile u8 *)(0x2B))

#define UCSRA_MPCM                0
#define UCSRA_U2X                 1
#define UCSRA_PE                  2
#define UCSRA_DOR                 3                /**/
#define UCSRA_FE                  4                /**/
#define UCSRA_UDRE                5                /**/
#define UCSRA_TXC                 6                /**/
#define UCSRA_RXC                 7                /**/



#define UCSRB             (*(volatile u8 *)(0x2A))

#define UCSRB_TXB8                          0
#define UCSRB_RXB8                          1
#define UCSRB_UCSZ2                         2         /* character size */
#define UCSRB_TXEN                          3       /* Transmitter enable */
#define UCSRB_RXEN                          4       /* Reciever  enable */
#define UCSRB_UDRIE                         5
#define UCSRB_TXCIE                         6
#define UCSRB_RXCIE                         7


#define UCSRC             (*(volatile u8 *)(0x40))

#define UCSRC_UCPOL                 0         /*Clock Polarity 0->Rising & 1->Falling   */
#define UCSRC_UCSZ0                 1         /*Character size 0-9 bits  */
#define UCSRC_UCSZ1                 2         /* 0,1,2,3 --> _5_6_7_8 Bits & 7 for 9_bits */
#define UCSRC_USBS                  3             /*Stop bit select 0 for 1_bit & 1 for 2_bits  */
#define UCSRC_UPM0                  4         /* Parity Mode 0 for disabled 1 for Reserved  */
#define UCSRC_UPM1                  5         /* Parity Mode 2 for even parity and 3 for odd parity   */
#define UCSRC_UMSEL                 6         /* Mode Select 0 for Async & 1 for Sync */
#define UCSRC_URSEL                 7             /* register select between UCSRC ( 1) and UBRRH  */


#define UBRRL             (*(volatile u8 *)(0x29))


#define UBRRH             (*(volatile u8 *)(0x40))

#define SREG      (*(volatile u8 *)(0x5f))
#define SREG_I              7

#endif /* UART_PRIVATE_H_ */
