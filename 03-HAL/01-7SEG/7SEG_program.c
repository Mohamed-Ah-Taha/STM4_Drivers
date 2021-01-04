/*
 * 7SEG_program.c
 *
 *  Created on: Jan 2, 2021
 *      Author: Mohamed Taha
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "7SEG_interface.h"
#include "7SEG_private.h"
#include "7SEG_config.h"


void H7SEG_voidInit(void)
{
	RCC_voidInitSysClock();
	#if H7SEG_PORT == GPIOA
		RCC_voidEnableClock(RCC_APB2,2);
		MGPIO_voidSetPinDirection(GPIOA , PIN0 , OUTPUT_SPEED_10MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOA , PIN1 , OUTPUT_SPEED_10MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOA , PIN2 , OUTPUT_SPEED_10MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOA , PIN3 , OUTPUT_SPEED_10MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOA , PIN4 , OUTPUT_SPEED_10MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOA , PIN5 , OUTPUT_SPEED_10MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOA , PIN6 , OUTPUT_SPEED_10MHZ_PP);

	#elif H7SEG_PORT == GPIOB
		RCC_voidEnableClock(RCC_APB2,3);
		MGPIO_voidSetPinDirection(GPIOB , PIN0 , OUTPUT_SPEED_10MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOB , PIN1 , OUTPUT_SPEED_10MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOB , PIN2 , OUTPUT_SPEED_10MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOB , PIN3 , OUTPUT_SPEED_10MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOB , PIN4 , OUTPUT_SPEED_10MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOB , PIN5 , OUTPUT_SPEED_10MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOB , PIN6 , OUTPUT_SPEED_10MHZ_PP);
	#endif

}

void H7SEG_voidDisplayNumber(u8 Copy_u8Number)
{

		#if H7SEG_TYPE == CATHODE
			switch (Copy_u8Number)
			{
			case 0 : MGPIO_voidSetPinValue(H7SEG_PORT , 0 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 1 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 2 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 3 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 4 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 5 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 6 , GPIO_LOW);
			 	 	 break ;

			case 1 : MGPIO_voidSetPinValue(H7SEG_PORT , 0 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 1 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 2 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 3 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 4 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 5 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 6 , GPIO_LOW);
			 	 	 break ;

			case 2 : MGPIO_voidSetPinValue(H7SEG_PORT , 0 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 1 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 2 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 3 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 4 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 5 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 6 , GPIO_HIGH);
			 	 	 break ;

			case 3 : MGPIO_voidSetPinValue(H7SEG_PORT , 0 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 1 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 2 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 3 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 4 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 5 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 6 , GPIO_HIGH);
			 	 	 break ;

			case 4 : MGPIO_voidSetPinValue(H7SEG_PORT , 0 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 1 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 2 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 3 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 4 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 5 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 6 , GPIO_HIGH);
			 	 	 break ;

			case 5 : MGPIO_voidSetPinValue(H7SEG_PORT , 0 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 1 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 2 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 3 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 4 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 5 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 6 , GPIO_HIGH);
			 	 	 break ;

			case 6 : MGPIO_voidSetPinValue(H7SEG_PORT , 0 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 1 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 2 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 3 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 4 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 5 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 6 , GPIO_HIGH);
			 	 	 break ;

			case 7 : MGPIO_voidSetPinValue(H7SEG_PORT , 0 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 1 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 2 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 3 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 4 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 5 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 6 , GPIO_LOW);
			 	 	 break ;

			case 8 : MGPIO_voidSetPinValue(H7SEG_PORT , 0 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 1 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 2 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 3 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 4 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 5 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 6 , GPIO_HIGH);
			 	 	 break ;

			case 9 : MGPIO_voidSetPinValue(H7SEG_PORT , 0 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 1 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 2 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 3 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 4 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 5 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 6 , GPIO_HIGH);
			 	 	 break ;
			default : break;
			}

		#elif H7SEG_TYPE == ANODE
			switch (Copy_u8Number)
			{
			case 0 : MGPIO_voidSetPinValue(H7SEG_PORT , 0 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 1 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 2 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 3 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 4 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 5 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 6 , GPIO_HIGH);
			 	 	 break ;

			case 1 : MGPIO_voidSetPinValue(H7SEG_PORT , 0 , GPIO_HIG);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 1 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 2 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 3 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 4 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 5 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 6 , GPIO_HIGH);
			 	 	 break ;

			case 2 : MGPIO_voidSetPinValue(H7SEG_PORT , 0 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 1 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 2 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 3 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 4 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 5 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 6 , GPIO_LOW);
			 	 	 break ;

			case 3 : MGPIO_voidSetPinValue(H7SEG_PORT , 0 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 1 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 2 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 3 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 4 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 5 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 6 , GPIO_LOW);
			 	 	 break ;

			case 4 : MGPIO_voidSetPinValue(H7SEG_PORT , 0 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 1 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 2 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 3 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 4 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 5 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 6 , GPIO_LOW);
			 	 	 break ;

			case 5 : MGPIO_voidSetPinValue(H7SEG_PORT , 0 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 1 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 2 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 3 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 4 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 5 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 6 , GPIO_LOW);
			 	 	 break ;

			case 6 : MGPIO_voidSetPinValue(H7SEG_PORT , 0 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 1 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 2 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 3 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 4 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 5 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 6 , GPIO_LOW);
			 	 	 break ;

			case 7 : MGPIO_voidSetPinValue(H7SEG_PORT , 0 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 1 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 2 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 3 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 4 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 5 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 6 , GPIO_HIGH);
			 	 	 break ;

			case 8 : MGPIO_voidSetPinValue(H7SEG_PORT , 0 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 1 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 2 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 3 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 4 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 5 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 6 , GPIO_LOW);
			 	 	 break ;

			case 9 : MGPIO_voidSetPinValue(H7SEG_PORT , 0 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 1 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 2 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 3 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 4 , GPIO_HIGH);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 5 , GPIO_LOW);
			 	 	 MGPIO_voidSetPinValue(H7SEG_PORT , 6 , GPIO_LOW);
			 	 	 break ;
			default : break;
			}


		#endif
}
