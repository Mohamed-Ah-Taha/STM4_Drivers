/***************************************************/
/* Author   : Mohamed Taha                         */
/* Version  : V01                                  */
/* Date     : 26 DEC 2020                          */
/***************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void RCC_voidInitSysClock(void)
{
    #if     RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
        RCC_CR    = 0x00010000; /* Enable HSE with no bypass */
        RCC_CFGR  = 0x00000001;

    #elif   RCC_CLOCK_TYPE == RCC_HSE_RC
        RCC_CR    = 0x00050000; /* Enable HSE with bypass */
        RCC_CFGR  = 0x00000001;

    #elif   RCC_CLOCK_TYPE == RCC_HSI
        RCC_CR    = 0x00000081; /* Enable HSI + Trimming = 0 */
        RCC_CFGR  = 0x00000000;

    #elif   RCC_CLOCK_TYPE == RCC_PLL
        #if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
            RCC_CR    = 0x01000081; /* PLL bit + HSI ON + Trimming = 0 */
            RCC_CFGR  = 0x00000002; /* SW selected PLL */
			RCC_CFGR  |= RCC_Pll_MUL_VAL ; /* Selecting Multiplication value */

        #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
            /*Choosing whether the user choosed Crystal or RC (Bypass) */
            #if   RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
                RCC_CR    = 0x01010000; /* PLL bit + HSE ON /
            #elif RCC_CLOCK_TYPE == RCC_HSE_RC
                RCC_CR    = 0x01050000; /* PLL bit + HSE ON with bypass */
            #endif // RCC_CLOCK_TYPE

            RCC_CFGR  = 0x00030002; /* SW selected PLL + HSE selected + HSE divider */
			RCC_CFGR  |= RCC_Pll_MUL_VAL ; /* Selecting Multiplication value */

        #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
            /*Choosing whether the user choosed Crystal or RC (Bypass) */
            #if   RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
                RCC_CR    = 0x01010000; /* PLL bit + HSE ON /
            #elif RCC_CLOCK_TYPE == RCC_HSE_RC
                RCC_CR    = 0x01050000; /* PLL bit + HSE ON with bypass */
            #endif // RCC_CLOCK_TYPE

            RCC_CFGR  = 0x00010002; /* SW selected PLL + HSE selected */
			RCC_CFGR  |= RCC_Pll_MUL_VAL ; /* Selecting Multiplication value */

        #endif // RCC_PLL_INPUT

    #else
        #error("You chosed Wrong Clock Type")

    #endif // RCC_CLOCK_TYPE
}

void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{   /*Checking on the peripheral number aka Input Validation to make sure the user sent the right arguments*/
    if (Copy_u8PerId <= 31)
    {
        switch (Copy_u8BusId)
        {
            case RCC_AHB   : SET_BIT(RCC_AHBENR  ,Copy_u8PerId);    break;
            case RCC_APB1  : SET_BIT(RCC_APB1ENR ,Copy_u8PerId);    break;
            case RCC_APB2  : SET_BIT(RCC_APB2ENR ,Copy_u8PerId);    break;
        }
    }

    else
    {
        /* Return Error */
    }
}


void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
    if (Copy_u8PerId <= 31)
        switch (Copy_u8BusId)
        {
            case RCC_AHB   : CLR_BIT(RCC_AHBENR  ,Copy_u8PerId);    break;
            case RCC_APB1  : CLR_BIT(RCC_APB1ENR ,Copy_u8PerId);    break;
            case RCC_APB2  : CLR_BIT(RCC_APB2ENR ,Copy_u8PerId);    break;
        }
    }

    else
    {
        /* Return Error */
    }
}
