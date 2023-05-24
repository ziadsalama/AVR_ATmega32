/*
 * std_macros.h
 *
 *  Created on: Mar 21, 2023
 *      Author: ziads
 */

#ifndef STD_MACROS_H_
#define STD_MACROS_H_


#define SET_BIT(REG,BIT) REG|=(1<<BIT)
#define CLR_BIT(REG,BIT) REG&=~(1<<BIT)
#define TOGGLE_BIT(REG,BIT) REG^=(1<<BIT)
#define READ_BIT(REG,BIT)   ((REG>>BIT)&1)
#define WRITE_BIT(REG,BIT,VALUE) REG=(VALUE<<BIT) | (REG&=~(1<<BIT))


#endif /* STD_MACROS_H_ */
