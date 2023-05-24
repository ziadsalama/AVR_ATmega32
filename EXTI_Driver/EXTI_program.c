/*
 * EXTI_program.c
 *
 *  Created on: Apr 2, 2023
 *      Author: ziads
 */


#include "std_macros.h"
#include "type_defs.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_cfg.h"

/********************************************** Global Pointers  ***************************************/

void(*EXTI_Int1CallBack )(void) = NULL;
void(*EXTI_Int0CallBack )(void) = NULL;
void(*EXTI_Int2CallBack )(void) = NULL;

/*************************** External Interrupt Initialization RunTime *********************************/

void EXTI_voidINT0Init(u8 Copy_u8SenseSignal)
{
	SET_BIT(GICR,GICR_INT0);
	SET_BIT(SREG,SREG_I);
	switch(Copy_u8SenseSignal)
			{
	case LOW_LEVEL :
		CLR_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
		break;
	case ON_CHANGE :
		SET_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
		break;
	case FALLING_EDGE :
		CLR_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
		break;

	case RISING_EDGE :
		SET_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
		break;
	default :
		break;


			}
}


void EXTI_voidINT1Init(u8 Copy_u8SenseSignal)
{
	SET_BIT(GICR,GICR_INT1);
	SET_BIT(SREG,SREG_I);
	switch(Copy_u8SenseSignal)
	{
	case LOW_LEVEL :
		CLR_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
		break;
	case ON_CHANGE :
		SET_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
		break;
	case FALLING_EDGE :
		CLR_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
		break;

	case RISING_EDGE :
		SET_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
		break;
	default :
		break;

	}



}


void EXTI_voidINT2Init(u8 Copy_u8SenseSignal)
{
	SET_BIT(GICR,GICR_INT2);
	SET_BIT(SREG,SREG_I);
	switch(Copy_u8SenseSignal)
	{
	case FALLING_EDGE :
		CLR_BIT(MCUCSR,6);

		break;

	case RISING_EDGE :
		SET_BIT(MCUCSR,6);

		break;
	default :
		break;


	}

}


/**************************** External Interrupt Initialization Pre Build********************************/
void EXTI_voidINT0InitPreBuild(u8 Copy_u8SenseSignal)
{
	SET_BIT(GICR,GICR_INT0);
	SET_BIT(SREG,SREG_I);
#if SENSED_SIGNAL ==LOW_LEVEL
	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
#elif SENSED_SIGNAL ==ON_CHANGE
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
#elif SENSED_SIGNAL ==FALLING_EDGE
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
#elif SENSED_SIGNAL ==RISING_EDGE
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
#endif
}

void EXTI_voidINT1InitPreBuild(u8 Copy_u8SenseSignal)
{
	SET_BIT(GICR,GICR_INT1);
	SET_BIT(SREG,SREG_I);
#if SENSED_SIGNAL ==LOW_LEVEL
	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
#elif SENSED_SIGNAL ==ON_CHANGE
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
#elif SENSED_SIGNAL ==FALLING_EDGE
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
#elif SENSED_SIGNAL ==RISING_EDGE
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
#endif


}


void EXTI_voidINT2InitPreBuild(u8 Copy_u8SenseSignal)
{
	SET_BIT(GICR,GICR_INT2);
	SET_BIT(SREG,SREG_I);

	;
#if SENSED_SIGNAL ==FALLING_EDGE
	CLR_BIT(MCUCSR,6);

#elif SENSED_SIGNAL ==RISING_EDGE
	SET_BIT(MCUCSR,6);

#endif

}



/********************************************** Interrupt Enable ***************************************/

void Enable_Interrupt(u8 Copy_u8IntId)
{
	switch(Copy_u8IntId)
	{
	case INT0 :
		SET_BIT(GICR,6);
		SET_BIT(SREG,7);
		break;
	case INT1 :
		SET_BIT(GICR,7);
		SET_BIT(SREG,7);
		break;
	case INT2 :
		SET_BIT(GICR,5);
		SET_BIT(SREG,7);
		break;
	default :
		break;
	}
}

/********************************************** Disable Interrupt ***************************************/

void Disable_Interrupt(u8 Copy_u8IntId)
{
	switch(Copy_u8IntId)
	{
	case INT0 :
		CLR_BIT(SREG,7);
		CLR_BIT(GICR,6);
		break;
	case INT1 :
		CLR_BIT(SREG,7);
		CLR_BIT(GICR,6);
		break;
	case INT2 :
		CLR_BIT(SREG,7);
		CLR_BIT(GICR,6);
		break;
	default :
		break;
	}

}


/********************************************** Sense Signals  ***************************************/

void Set_Sense_Signal_INT0(u8 Copy_u8Signal)
{
	switch(Copy_u8Signal)
	{
	case LOW_LEVEL :
		CLR_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
		break;
	case ON_CHANGE :
		SET_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
		break;
	case FALLING_EDGE :
		CLR_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
		break;

	case RISING_EDGE :
		SET_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
		break;
	default :
		break;

	}

}


void Set_Sense_Signal_INT1(u8 Copy_u8Signal)
{
	switch(Copy_u8Signal)
	{
	case LOW_LEVEL :
		CLR_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
		break;
	case ON_CHANGE :
		SET_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
		break;
	case FALLING_EDGE :
		CLR_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
		break;

	case RISING_EDGE :
		SET_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
		break;
	default :
		break;

	}


}



void Set_Sense_Signal_INT2(u8 Copy_u8Signal)
{
	switch(Copy_u8Signal)
	{
	case FALLING_EDGE :
		CLR_BIT(MCUCSR,6);

		break;

	case RISING_EDGE :
		SET_BIT(MCUCSR,6);

		break;
	default :
		break;

	}

}





/*******************************************************************************************************/

void EXTI_voidInt1Init(void)
{
	CLR_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);

	SET_BIT(GICR,GICR_INT1);

	SET_BIT(SREG,SREG_I);
}


/********************************************** CallBack Functions ***************************************/
void EXTI_voidSetCallBackINT0(void(*Copy_ptrToFunc)(void))
{
	if(Copy_ptrToFunc != NULL)
	{
		EXTI_Int0CallBack = Copy_ptrToFunc;
	}
	else
	{
		// do nothing
	}

}


void EXTI_voidSetCallBackINT1(void(*Copy_ptrToFunc)(void))
{
	if(Copy_ptrToFunc != NULL)   // & Application
	{
		EXTI_Int1CallBack = Copy_ptrToFunc;     // global pointer == & Application
	}
	else
	{
		// do nothing
	}
}


void EXTI_voidSetCallBackINT2(void(*Copy_ptrToFunc)(void))
{
	if(Copy_ptrToFunc != NULL)   // & Application
	{
		EXTI_Int2CallBack = Copy_ptrToFunc;     // global pointer == & Application
	}
	else
	{
		// do nothing
	}
}


/********************************************** ISRS  ***************************************/
/* ISR for INT0 */
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(EXTI_Int0CallBack != NULL)
	{

		EXTI_Int0CallBack();

	}
	else
	{
		// do nothing
	}


}

/* ISR for INT1 */
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(EXTI_Int1CallBack != NULL)
	{

		EXTI_Int1CallBack();  // call Application function 3n tare2 el pointer bta3ha

	}
	else
	{

	}
}


/* ISR for INT2 */
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if(EXTI_Int2CallBack != NULL)
	{

		EXTI_Int2CallBack();  // call Application function 3n tare2 el pointer bta3ha

	}
	else
	{

	}

}
