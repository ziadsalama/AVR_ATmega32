/*
 * PWM_Timer1_config.h
 *
 *  Created on: Apr 8, 2023
 *      Author: moham
 */

#ifndef PWM_TIMER1_CONFIG_H_
#define PWM_TIMER1_CONFIG_H_

#define CRYSTAL_FREQ   8  //Mhz



#define NON_INVERTING      0
#define INVERTING          1

#define PWM_MODE        NON_INVERTING

#define DIVISION_FACTOR_1024  5
#define DIVISION_FACTOR_256   4
#define DIVISION_FACTOR_64    3
#define DIVISION_FACTOR_8     2
#define DIVISION_FACTOR_1     1

#define PRESCALE_MODE      DIVISION_FACTOR_8

#define PRESCALAR_VALUE   8

#endif /* PWM_TIMER1_CONFIG_H_ */
