/***************************************************/
/* Author   : Mohamed Taha                         */
/* Version  : V01                                  */
/* Date     : 26 DEC 2020                          */
/***************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/* Register Definitions */
#define RCC_CR            *((u32*)0x40021000)
#define RCC_CFGR          *((u32*)0x40021004)
#define RCC_CIR           *((u32*)0x40021008)
#define RCC_APB2RSTR      *((u32*)0x4002100C)
#define RCC_APB1RSTR      *((u32*)0x40021010)
#define RCC_AHBENR        *((u32*)0x40021014)
#define RCC_APB2ENR       *((u32*)0x40021018)
#define RCC_APB1ENR       *((u32*)0x4002101C)
#define RCC_BDCR          *((u32*)0x40021020)
#define RCC_CSR           *((u32*)0x40021024)

/* Clock Types */
#define RCC_HSE_CRYSTAL    0
#define RCC_HSE_RC         1
#define RCC_HSI            2
#define RCC_PLL            3

/* PLL Options */
#define RCC_PLL_IN_HSI_DIV_2  0
#define RCC_PLL_IN_HSE_DIV_2  1
#define RCC_PLL_IN_HSE        2

/* PLL Multiplication Factor */
#define PLL_MUL_VAL_2  ((u32)0x00000000)
#define PLL_MUL_VAL_3  ((u32)0x00040000)
#define PLL_MUL_VAL_4  ((u32)0x00080000)
#define PLL_MUL_VAL_5  ((u32)0x000C0000)
#define PLL_MUL_VAL_6  ((u32)0x00100000)
#define PLL_MUL_VAL_7  ((u32)0x00140000)
#define PLL_MUL_VAL_8  ((u32)0x00180000)
#define PLL_MUL_VAL_9  ((u32)0x001C0000)
#define PLL_MUL_VAL_10 ((u32)0x00200000)
#define PLL_MUL_VAL_11 ((u32)0x00240000)
#define PLL_MUL_VAL_12 ((u32)0x00280000)
#define PLL_MUL_VAL_13 ((u32)0x002C0000)
#define PLL_MUL_VAL_14 ((u32)0x00300000)
#define PLL_MUL_VAL_15 ((u32)0x00340000)
#define PLL_MUL_VAL_16 ((u32)0x00380000)


#endif // RCC_PRIVATE_H
