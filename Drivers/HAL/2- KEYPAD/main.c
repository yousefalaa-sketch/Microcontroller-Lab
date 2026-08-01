/*
 * main.c

 *
 *  Created on: Jul 27, 2026
 *      Author: Dell
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "LCD_int.h"
#include "KEYPAD_int.h"
#include <util/delay.h>

int main(void)
{
	u8 Local_u8PressedKey;
	DIO_voidInitialization();
	LCD_voidLCDInit();
	KPD_voidInit();
	while(1)
	{
		Local_u8PressedKey = KPD_u8GetPressedKey();
		if(Local_u8PressedKey != KPD_NOT_PRESSED)
		{
			LCD_voidSendData(Local_u8PressedKey);
		}
	}
	return 0;
}
