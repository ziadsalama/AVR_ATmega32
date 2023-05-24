
#include "std_macros.h"
#include "type_defs.h"

#include "DIO_interface.h"

#include "GIE_interface.h"
#include "GIE_config.h"
#include "GIE_private.h"

/*This function is to enable general interrupt*/
void GIE_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);
}
/*This function is to disable general interrupt*/
void GIE_voidDisable(void)
{
	CLR_BIT(SREG,SREG_I);
}
