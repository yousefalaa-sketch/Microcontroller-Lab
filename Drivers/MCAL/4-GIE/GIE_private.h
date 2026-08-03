/************************************************/
/********* Author: Yousef Alaa *****************/
/********* Date  : 3/08/2026   *****************/
/********* File  : Private File *****************/
/************************************************/

#ifndef GIE_PRIVATE_H
#define GIE_PRIVATE_H

/* SREG (Status Register) - Bit 7 is the I-bit (Global Interrupt Enable) */
#define SREG    (*(volatile u8*)0x5F)
#define I_BIT   7

#endif