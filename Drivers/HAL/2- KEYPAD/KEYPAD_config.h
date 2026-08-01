/************************************************/
/********* Author: Yousef Alaa *****************/
/********* Date  : 31/07/2026   *****************/
/********* File: Configuration File  *****************/
/************************************************/
#ifndef   KEYPAD_CONFIG_H
#define   KEYPAD_CONFIG_H

#define KPD_PORT        DIO_PORTC
//ROWS
#define KPD_R0_PIN      DIO_PIN0
#define KPD_R1_PIN      DIO_PIN1
#define KPD_R2_PIN      DIO_PIN2
#define KPD_R3_PIN      DIO_PIN3
//COLUMNS
#define KPD_C0_PIN      DIO_PIN4
#define KPD_C1_PIN      DIO_PIN5
#define KPD_C2_PIN      DIO_PIN6
#define KPD_C3_PIN      DIO_PIN7

#define KPD_KEYS        {{'7','8','9','/'}, \
                         {'4','5','6','*'}, \
                         {'1','2','3','-'}, \
                         {'C','0','=','+'}}



#endif