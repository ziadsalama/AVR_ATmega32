/*
 * GIE_program.c
 *
 *  Created on: Apr 5, 2023
 *      Author: ziads
 */


#include "std_macros.h"
#include "type_defs.h"

#include "GINT_interface.h"
#include "GINT_private.h"
#include "GINT_cfg.h"




void Global_INT_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);

}

void Global_INT_voidDisable(void)
{
	CLR_BIT(SREG,SREG_I);

}
