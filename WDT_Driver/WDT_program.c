#include "std_macros.h"
#include "type_defs.h"

#include "WDT_interface.h"
#include "WDT_private.h"
#include "WDT_config.h"





void WDT_voidEnable(void)
{
	SET_BIT(WDCTR,WDCTR_WDE);


}

void WDT_voidSetSleepTime(u8 Copy_u8SleepTime)
{
	WDCTR &=0b11111000 ;
	WDCTR |= Copy_u8SleepTime;

}

void WDT_voidDisable(void)
{
	/* writting 1 at bits 3,4 at the same operation */
	WDCTR |= 0b00011000;
	/* writing 1 at the bit 3 */
	WDCTR = 0;


}
