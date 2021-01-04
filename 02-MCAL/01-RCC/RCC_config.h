/***************************************************/
/* Author   : Mohamed Taha                         */
/* Version  : V01                                  */
/* Date     : 26 DEC 2020                          */
/***************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H



/* Options: RCC_HSE_CRYSTAL
            RCC_HSE_RC
            RCC_HSI
            RCC_PLL                 */
#define RCC_CLOCK_TYPE  RCC_HSE_CRYSTAL

/* Options: RCC_PLL_IN_HSI_DIV_2
            RCC_PLL_IN_HSE_DIV_2
            RCC_PLL_IN_HSE          */
/* Note: Select value only if you have PLL as input clock source */
#if RCC_CLOCK_TYPE ==   RCC_PLL
#define RCC_PLL_INPUT   RCC_PLL_IN_HSE_DIV_2
#endif // RCC_CLOCK_TYPE

/* Options PLL_MUL_VAL_2 to PLL_MUL_VAL_16 */
/* Note: Select value only if you have PLL as input clock source */
#if RCC_CLOCK_TYPE ==    RCC_PLL
#define RCC_Pll_MUL_VAL  PLL_MUL_VAL_3
#endif // RCC_CLOCK_TYPE

#endif // RCC_CONFIG_H
