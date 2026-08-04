/************************************************/
/********* Author: Yousef Alaa *****************/
/********* Date  : 4/08/2026   *****************/
/********* File  : Private File *****************/
/************************************************/

#ifndef TIM0_PRIVATE_H
#define TIM0_PRIVATE_H

/***** Timer 0 Registers Definition****/
#define TCCR0       *((volatile u8*)0x53)
#define TCNT0       *((volatile u8*)0x52)
#define OCR0        *((volatile u8*)0x5C)
#define TIMSK       *((volatile u8*)0x59)
#define TIFR        *((volatile u8*)0x58)

/* Timer 0 Modes Options */
#define TIM0_NORMAL_MODE          0
#define TIM0_CTC_MODE             1
#define TIM0_FAST_PWM_MODE        2
#define TIM0_PHASE_CORRECT_MODE   3

/* Prescaler Selection Options */
#define TIM0_NO_CLK               0
#define TIM0_PRESCALER_1          1
#define TIM0_PRESCALER_8          2
#define TIM0_PRESCALER_64         3
#define TIM0_PRESCALER_256        4
#define TIM0_PRESCALER_1024       5
#define TIM0_EXT_CLK_FALLING      6
#define TIM0_EXT_CLK_RISING       7

#define NULL                      ((void*)0)

#endif

