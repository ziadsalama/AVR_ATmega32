/*
 * SSD_interface.h
 *
 *  Created on: Mar 27, 2023
 *      Author: ziads
 */

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_



#define SSD_COMM_CATHODE    0
#define SSD_COMM_ANODE      1

/* common cathode  */
#define SSD_CATH_NUM_0         0b00111111
#define SSD_CATH_NUM_1         0b00000110
#define SSD_CATH_NUM_2         0b01011011
#define SSD_CATH_NUM_3         0b01001111
#define SSD_CATH_NUM_4         0b01100110
#define SSD_CATH_NUM_5         0b01101101
#define SSD_CATH_NUM_6         0b01111101
#define SSD_CATH_NUM_7         0b00000111
#define SSD_CATH_NUM_8         0b01111111
#define SSD_CATH_NUM_9         0b01101111



/*  common Anode */
#define SSD_ANOD_NUM_0         0b11000000
#define SSD_ANOD_NUM_1         0b11111001
#define SSD_ANOD_NUM_2         0b10100100
#define SSD_ANOD_NUM_3         0b10110000
#define SSD_ANOD_NUM_4         0b10011001
#define SSD_ANOD_NUM_5         0b10010010
#define SSD_ANOD_NUM_6         0b10000010
#define SSD_ANOD_NUM_7         0b11111000
#define SSD_ANOD_NUM_8         0b10000000
#define SSD_ANOD_NUM_9         0b10010000




#define SSD_MODE_COMMON_CATHODE 0
#define SSD_MODE_COMMON_ANODE 1

#define COMMON_CATHODE_NUMBER0 0b00111111
#define COMMON_CATHODE_NUMBER1 0b00000110
#define	COMMON_CATHODE_NUMBER2 0b01011011
#define COMMON_CATHODE_NUMBER3 0b01001111
#define COMMON_CATHODE_NUMBER4 0b01100110
#define COMMON_CATHODE_NUMBER5 0b01101101
#define COMMON_CATHODE_NUMBER6 0b01111101
#define COMMON_CATHODE_NUMBER7 0b00000111
#define COMMON_CATHODE_NUMBER8 0b01111111
#define COMMON_CATHODE_NUMBER9 0b01101111

#define COMMON_ANODE_NUMBER0 0b11000000
#define COMMON_ANODE_NUMBER1 0b11111001
#define COMMON_ANODE_NUMBER2 0b10100100
#define COMMON_ANODE_NUMBER3 0b10110000
#define COMMON_ANODE_NUMBER4 0b10011001
#define COMMON_ANODE_NUMBER5 0b10010010
#define COMMON_ANODE_NUMBER6 0b10000010
#define COMMON_ANODE_NUMBER7 0b11111000
#define COMMON_ANODE_NUMBER8 0b10000000
#define COMMON_ANODE_NUMBER9 0b10010000

/*********************************************************************************************/
/***********************************Functions' prototypes*************************************/
/*********************************************************************************************/

void SSD_voidInit(u8 Copy_Connection,u8 Copy_SSDPort,u8 Copy_SSDCommonPort, u8 Copy_SSDCommonPin);
void SSD_voidON(u8 Copy_Connection,u8 Copy_SSDCommonPort, u8 Copy_SSDCommonPin);

void SSD_voidOFF(u8 Copy_Connection,u8 Copy_SSDCommonPort, u8 Copy_SSDCommonPin);
void SSD_voidDisplayNumber(u8 Copy_Connection, u8 Copy_SSDPort , u8 Copy_u8DisplayedNumber);


/************************************************************************************************/

//This function is to Initialize the Seven Segment Display
void SSD_voidSsdInit(u8 Copy_u8PortID1 , u8 Copy_u8PortID2 , u8 Copy_u8CommonPortID , u8 Copy_u8CommonPin0 , u8 Copy_u8CommonPin1);

//This function is to turn the Seven Segment Display ON
void SSD_voidSsdOn(u8 Copy_u8SsdConnection , u8 Copy_u8CommonPortID , u8 Copy_u8CommonPin);

//This function is to Display the Number on the Seven Segment Display
void SSD_voidSsdDisplayNumber(u8 Copy_u8PortID , u8 Copy_u8SsdNumber);

//This function is to turn the Seven Segment Display OFF
void SSD_voidSsdOff(u8 Copy_u8SsdConnection , u8 Copy_u8CommonPortID , u8 Copy_u8CommonPin);


#endif /* SSD_INTERFACE_H_ */
