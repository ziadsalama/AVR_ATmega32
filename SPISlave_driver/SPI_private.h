/*
 * SPI_private.h
 *
 *  Created on: Apr 11, 2023
 *      Author: ziads
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_



#define SPCR         (*(volatile u8 *)(0x2D))

#define SPCR_SPR0              0               /*  SPI Clock Rate Select*/
#define SPCR_SPR1              1               /*  */
#define SPCR_CPHA              2               /*  Clock Phase*/
#define SPCR_CPOL              3              /*   Clock Polarity*/
#define SPCR_MSTR              4              /*  Master/Slave Select */
#define SPCR_DORD              5              /*  Data Order*/
#define SPCR_SPE               6              /*   SPI Enable */
#define SPCR_SPIE              7             /*  SPI Interrupt Enable*/





#define SPSR         (*(volatile u8 *)(0x2E))

#define SPSR_SPI2X              0          /*  Double SPI Speed Bit*/
#define SPSR_WCOL               6          /* Write COLlision Flag*/
#define SPSR_SPIF               7         /* SPI Interrupt Flag*/




#define SPDR         (*(volatile u8 *)(0x2F))

#define SPDR_LSB                0
#define SPDR_MSB                7






#endif /* SPI_PRIVATE_H_ */
