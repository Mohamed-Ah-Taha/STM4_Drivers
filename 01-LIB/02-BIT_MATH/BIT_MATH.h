/*************************************/
/* Author  : Mohamed Taha            */
/* Date    : 26 DEC 2020             */
/* Version : V01                     */
/*************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG , BITNUM) REG |=  (1 << (BITNUM))
#define CLR_BIT(REG , BITNUM) REG &= ~(1 << (BITNUM))
#define GET_BIT(REG , BITNUM) ((REG >> (BITNUM)) & 1)
#define TOG_BIT(REG , BITNUM) REG ^=  (1 << (BITNUM))

#endif // BIT_MATH_H
