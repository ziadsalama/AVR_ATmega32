/*
 * SPI_interface.h
 *
 *  Created on: Apr 11, 2023
 *      Author: ziads
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

/*Master Init */
void SPI_voidMasterInit();


/*Slave Init */
void SPI_voidSlaveInit();


u8 SPI_u8Transceive(u8 Copy_TransmittedByte);




#define SPI_PRESGALER_4                      0
#define SPI_PRESGALER_16                     1
#define SPI_PRESGALER_64                     2
#define SPI_PRESGALER_128                    3
#define SPI_PRESGALER_DOUBLE_4               4
#define SPI_PRESGALER_DOUBLE_16              5
#define SPI_PRESGALER_DOUBLE_64              6
#define SPI_PRESGALER_DOUBLE_128             7

#endif /* SPI_INTERFACE_H_ */
