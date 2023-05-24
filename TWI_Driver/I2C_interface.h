/*
 * I2C_interface.h
 *
 *  Created on: Apr 14, 2023
 *      Author: ziads
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

typedef enum {

	OK,
	InvalidStartCondition,
	InvalidRepeatedStart,
	InvalidSlaveAddressWithRead,
	InvalidSlaveAddressWithWrite,
	InvalidSendData,
	InvalidReceiveData

}TWI_ErrorState_t;


void TWI_voidMasterInit(u8 Copy_u8Address);

void TWI_voidSlaveInit(u8 Copy_u8Address);

TWI_ErrorState_t TWI_SendStartCondition(void);

TWI_ErrorState_t TWI_SendRepeatedStart(void);

TWI_ErrorState_t TWI_SendSlaveAddressWithRead(u8 Copy_u8Address);

TWI_ErrorState_t TWI_SendSlaveAddressWithWrite(u8 Copy_u8Address);

TWI_ErrorState_t TWI_SendData(u8 Copy_u8Data);

TWI_ErrorState_t TWI_ReceiveData(u8* Copy_u8PData);

void TWI_SendStopCondition(void);


#endif /* I2C_INTERFACE_H_ */
