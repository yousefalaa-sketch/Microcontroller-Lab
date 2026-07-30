/************************************************/
/********* Author: Yousef Alaa *****************/
/********* Date  : 30/07/2026   *****************/
/********* File: Program File  *****************/
/********* File: Program File  *****************/
/************************************************/
#include "Std_Types.h"
#include "Bit_Math.h"
#include <avr/delay.h>

#include "DIO_int.h"

#include "LCD_config.h"
#include "LCD_private.h"
#include "LCD_int.h"

void LCD_voidLCDInit(void)
{
	/**
	 1- Wait 30ms
	 2- Send Home Command, wait 1 ms
	 3- send Function set8 bit Command wait 1 ms
	 4- send Display on/off Command wait 1ms
	 5- Send Display Clear Command wait 1ms
	 6- Send Enty Mode Command, wait 1ms
	*/
	_delay_ms(35);

LCD_voidSendCommand(LCD_HOME);
_delay_ms(1);

LCD_voidSendCommand(LCD_FUNCTIONSET_8BIT);
_delay_ms(1);

LCD_voidSendCommand(LCD_DISPLAYON);
_delay_ms(1);

LCD_voidSendCommand(LCD_CLEAR);
_delay_ms(2);

LCD_voidSendCommand(LCD_ENTRY_MODE);
_delay_ms(1);
}
static void LCD_voidPutonBus(u8 u8Char)
{
    DIO_voidSetPinValue(LCD_D0, GET_BIT(u8Char, 0));
    DIO_voidSetPinValue(LCD_D1, GET_BIT(u8Char, 1));
    DIO_voidSetPinValue(LCD_D2, GET_BIT(u8Char, 2));
    DIO_voidSetPinValue(LCD_D3, GET_BIT(u8Char, 3));
    DIO_voidSetPinValue(LCD_D4, GET_BIT(u8Char, 4));
    DIO_voidSetPinValue(LCD_D5, GET_BIT(u8Char, 5));
    DIO_voidSetPinValue(LCD_D6, GET_BIT(u8Char, 6));
    DIO_voidSetPinValue(LCD_D7, GET_BIT(u8Char, 7));

    DIO_voidSetPinValue(LCD_EN, HIGH);
    _delay_ms(2);

    DIO_voidSetPinValue(LCD_EN, LOW);
    _delay_ms(2);
}


void LCD_voidSendCommand(u8 u8CMD)
{
	DIO_voidSetPinValue(LCD_RS, 0); // RS = 0 (Command)
    DIO_voidSetPinValue(LCD_RW, 0); // RW = 0 (Write)
    
    LCD_voidPutonBus(u8CMD);
}

void LCD_voidSendData(u8 u8Data)
{
	DIO_voidSetPinValue(LCD_RS, 1); // RS = 1 (Data)
    DIO_voidSetPinValue(LCD_RW, 0); // RW = 0 (Write)
    
    LCD_voidPutonBus(u8Data);
 	
}

void LCD_GotoXY(u8 x, u8 y)
{
	u8 Local_u8Address = 0;
    
    if (y == 0)
    {
        Local_u8Address = x;
    }
    else if (y == 1)
    {
        Local_u8Address = x + 0x40; 
    }
    

    LCD_voidSendCommand(Local_u8Address | LCD_SETCURSOR); 
}

void LCD_voidWriteString(u8 * u8string)
{
	u8 Local_u8Counter = 0;
    
    while (u8string[Local_u8Counter] != '\0')
    {
        LCD_voidSendData(u8string[Local_u8Counter]);
        Local_u8Counter++;
    }
}

void LCD_voidWriteNumber(u8 u8Number)
{
	u8 Local_u8Digits[3]; //mx num is 255
    s8 Local_s8Counter = 0; 
    
    // specific condition
    if (u8Number == 0)
    {
        LCD_voidSendData('0');
        return;
    }
    
    while (u8Number > 0)
    {
        Local_u8Digits[Local_s8Counter] = u8Number % 10;
        u8Number = u8Number / 10;
        Local_s8Counter++;
    }
    
    Local_s8Counter--; //back step
    
    while (Local_s8Counter >= 0)
    {
        LCD_voidSendData(Local_u8Digits[Local_s8Counter] + '0');
        Local_s8Counter--;
    }
}
	