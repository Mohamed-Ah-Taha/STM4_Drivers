/*
 * NVIC_program.c
 *
 *  Created on: Jan 5, 2021
 *      Author: Mohamed Taha
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidEnableInterrupt (u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31) /* I don't have to use "Copy_u8IntNumber >= 0 &&" since the value i am passing is already u8 which is unsigned so it must be for sure >0 "Better Programming" */
	{
		NVIC_ISER0 = (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 59) /* I don't have to use "Copy_u8IntNumber >= 32 && " since i already checked its smaller than 31 in the first condition so i don't have to check if it's bigger than 32"Better Programming" */
	{
		Copy_u8IntNumber -= 32 ; /* Since 32 is the interrupt number 32 but its the first bit in the ISER1 Register */
		NVIC_ISER1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		/* Return Error */ /* We make the function return 0(OK) or 1(NOK) "u8" */
	}
}

void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31) /* I don't have to use "Copy_u8IntNumber >= 0 &&" since the value i am passing is already u8 which is unsigned so it must be for sure >0 "Better Programming" */
	{
		NVIC_ICER0 = (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 59) /* I don't have to use "Copy_u8IntNumber >= 32 && " since i already checked its smaller than 31 in the first condition so i don't have to check if it's bigger than 32"Better Programming" */
	{
		Copy_u8IntNumber -= 32 ; /* Since 32 is the interrupt number 32 but its the first bit in the ISER1 Register */
		NVIC_ICER1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		/* Return Error */ /* We make the function return 0(OK) or 1(NOK) "u8" */
	}
}

void MNVIC_voidSetPendingFlag (u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31) /* I don't have to use "Copy_u8IntNumber >= 0 &&" since the value i am passing is already u8 which is unsigned so it must be for sure >0 "Better Programming" */
	{
		NVIC_ISPR0 = (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 59) /* I don't have to use "Copy_u8IntNumber >= 32 && " since i already checked its smaller than 31 in the first condition so i don't have to check if it's bigger than 32"Better Programming" */
	{
		Copy_u8IntNumber -= 32 ; /* Since 32 is the interrupt number 32 but its the first bit in the ISER1 Register */
		NVIC_ISPR1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		/* Return Error */ /* We make the function return 0(OK) or 1(NOK) "u8" */
	}
}

void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31) /* I don't have to use "Copy_u8IntNumber >= 0 &&" since the value i am passing is already u8 which is unsigned so it must be for sure >0 "Better Programming" */
	{
		NVIC_ICPR0 = (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 59) /* I don't have to use "Copy_u8IntNumber >= 32 && " since i already checked its smaller than 31 in the first condition so i don't have to check if it's bigger than 32"Better Programming" */
	{
		Copy_u8IntNumber -= 32 ; /* Since 32 is the interrupt number 32 but its the first bit in the ISER1 Register */
		NVIC_ICPR1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		/* Return Error */ /* We make the function return 0(OK) or 1(NOK) "u8" */
	}
}

u8 MNVIC_u8GetActiveFlag (u8 Copy_u8IntNumber)
{
	u8 Local_u8Result;

	if (Copy_u8IntNumber <= 31) /* I don't have to use "Copy_u8IntNumber >= 0 &&" since the value i am passing is already u8 which is unsigned so it must be for sure >0 "Better Programming" */
	{
		Local_u8Result = GET_BIT(NVIC_IABR0, Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 59) /* I don't have to use "Copy_u8IntNumber >= 32 && " since i already checked its smaller than 31 in the first condition so i don't have to check if it's bigger than 32"Better Programming" */
	{
		Copy_u8IntNumber -= 32 ; /* Since 32 is the interrupt number 32 but its the first bit in the ISER1 Register */
		Local_u8Result = GET_BIT(NVIC_IABR1, Copy_u8IntNumber);
	}
	else
	{
		/* Return Error */ /* We make the function return 0(OK) or 1(NOK) "u8" */
	}

	return Local_u8Result;
}


void MNVIC_voidSetPriority (s8 Copy_s8IntID , u8 Copy_u8GroupPriority , u8 Copy_u8SubGroupPriority , u32 Copy_u32SCBGroup) /*s8 since i have priority in negative Interrupt ID */
{
	u8 Local_u8Priority = Copy_u8SubGroupPriority | (Copy_u8GroupPriority<<((Copy_u32SCBGroup - 0x05FA0300)/256)) ; /*Should Output 0 , 1 , 2*/ /*(Copy_u32SCBGroup - 0x05FA0300) if Copy_u32SCBGroup = 0x05FA0400 -> 0x100 -> 256 decimal*/

	/* First i have to check if its external or internal interrupt any External Interrupt will start from 0 S/W */

	/* Internal Peripheral */
	if(Copy_s8IntID < 0)
	{
		/*No action since NVIC can't set Priorities for Internal Peripherals */
	}

	/* External Peripheral */
	else if(Copy_s8IntID >= 0)
	{
		NVIC_IPR[Copy_s8IntID] = Local_u8Priority << 4 ;
	}
	/* I need to write on LOCK  */
	SCB_AIRCR = Copy_u32SCBGroup;




}





























/* Implementation of Same Enable Function but with the return error feature */
//u8 MNVIC_voidEnableInterrupt (u8 Copy_u8IntNumber)
//{
//	u8 ErrorStatus;
//	if (Copy_u8IntNumber <= 31) /* I don't have to use "Copy_u8IntNumber >= 0 &&" since the value i am passing is already u8 which is unsigned so it must be for sure >0 "Better Programming" */
//	{
//		SET_BIT(NVIC_ISER0 , Copy_u8IntNumber);
//		ErrorStatus = 0;
//	}
//	else if (Copy_u8IntNumber <= 59) /* I don't have to use "Copy_u8IntNumber >= 32 && " since i already checked its smaller than 31 in the first condition so i don't have to check if it's bigger than 32"Better Programming" */
//	{
//		Copy_u8IntNumber -= 32 ; /* Since 32 is the interrupt number 32 but its the first bit in the ISER1 Register */
//		SET_BIT(NVIC_ISER1 , Copy_u8IntNumber);
//		ErrorStatus = 0;
//	}
//	else
//	{
//		ErrorStatus = 1; /* We make the function return 0(OK) or 1(NOK) "u8" */
//	}
//
//	return ErrorStatus; and when i call this function i first check on the function
//}
