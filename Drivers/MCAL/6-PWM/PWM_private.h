/************************************************/
/********* Author: Yousef Alaa *****************/
/********* Date  : 4/08/2026   *****************/
/********* File  : Private File *****************/
/************************************************/

#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H
/***Registers***/
#define TCCR0   *((volatile u8*)0x53)
#define TCNT0   *((volatile u8*)0x52)
#define OCR0    *((volatile u8*)0x5C)

/***TCCR0 BITS*****/
#define CS00    0
#define CS01    1
#define CS02    2
#define WGM01   3
#define COM00   4
#define COM01   5
#define WGM00   6
#define FOC0    7

/**PWM MODS***/
#define FAST_PWM            1
#define PHASE_CORRECT_PWM   2
/**OUTPUTS***/
#define INVERTED            1
#define NON_INVERTED        2

#define PRESCALER_NO_CLOCK  0
#define PRESCALER_1         1
#define PRESCALER_8         2
#define PRESCALER_64        3
#define PRESCALER_256       4
#define PRESCALER_1024      5

#endif