/************************************************/
/********* Author: Yousef Alaa *****************/
/********* Date  : 31/07/2026   *****************/
/********* File: Program File  *****************/
/********* File: Program File  *****************/
/************************************************/
#include "Std_Types.h"
#include "Bit_Math.h"
#include <avr/delay.h>

#include "DIO_int.h"

#include "KEYPAD_config.h"
#include "KEYPAD_private.h"
#include "KEYPAD_interface.h"

//2D array
static const u8 KPD_u8Buttons[KPD_ROW_NUM][KPD_COL_NUM] = KPD_KEYS;

static const u8 KPD_u8RowPins[KPD_ROW_NUM] = {KPD_R0_PIN, KPD_R1_PIN, KPD_R2_PIN, KPD_R3_PIN};
static const u8 KPD_u8ColPins[KPD_COL_NUM] = {KPD_C0_PIN, KPD_C1_PIN, KPD_C2_PIN, KPD_C3_PIN};

void KPD_voidInit(void)
{
	u8 Local_u8Iterator;
	
	/* Initialize Columns as Outputs and set them to HIGH  */
	for(Local_u8Iterator = 0; Local_u8Iterator < KPD_COL_NUM; Local_u8Iterator++)
	{
		DIO_voidSetPinDirection(KPD_PORT, KPD_u8ColPins[Local_u8Iterator], OUTPUT);
		DIO_voidSetPinValue(KPD_PORT, KPD_u8ColPins[Local_u8Iterator], HIGH);
	}
	
	/* Initialize Rows as Inputs and enable Internal Pull-Up Resistors (HIGH) */
	for(Local_u8Iterator = 0; Local_u8Iterator < KPD_ROW_NUM; Local_u8Iterator++)
	{
		DIO_voidSetPinDirection(KPD_PORT, KPD_u8RowPins[Local_u8Iterator], INPUT);
		DIO_voidSetPinValue(KPD_PORT, KPD_u8RowPins[Local_u8Iterator], HIGH);
	}
}
u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8PressedKey = KPD_NOT_PRESSED;
	u8 Local_u8RowIterator, Local_u8ColIterator, Local_u8PinState;
	
	/* 1- Outer Loop: Iterate over Columns (Outputs) */
	for(Local_u8ColIterator = 0; Local_u8ColIterator < KPD_COL_NUM; Local_u8ColIterator++)
	{
		/* Activate the current Column (Apply LOW) */
		DIO_voidSetPinValue(KPD_PORT, KPD_u8ColPins[Local_u8ColIterator], LOW);
		
		/*  Scan Rows (Inputs) */
		for(Local_u8RowIterator = 0; Local_u8RowIterator < KPD_ROW_NUM; Local_u8RowIterator++)
		{
			/* Read Row State */
			Local_u8PinState = DIO_u8GetPinValue(KPD_PORT, KPD_u8RowPins[Local_u8RowIterator]);
			
			/* If LOW a button in this intersection is pressed */
			if(Local_u8PinState == LOW)
			{
				_delay_ms(20);
				
				/* Read again to confirm it's not noise */
				Local_u8PinState = DIO_u8GetPinValue(KPD_PORT, KPD_u8RowPins[Local_u8RowIterator]);
				
				if(Local_u8PinState == LOW)
				{
					/* Store the pressed character */
					Local_u8PressedKey = KPD_u8Buttons[Local_u8RowIterator][Local_u8ColIterator];
					
					
					while(Local_u8PinState == LOW)
					{
						Local_u8PinState = DIO_u8GetPinValue(KPD_PORT, KPD_u8RowPins[Local_u8RowIterator]);
					}
					
					/* Deactivate the Column and return the value directly */
					DIO_voidSetPinValue(KPD_PORT, KPD_u8ColPins[Local_u8ColIterator], HIGH);
					return Local_u8PressedKey;
				}
			}
		}
		
		/* 3- Deactivate the current Column (Apply HIGH) before moving to the next Column */
		DIO_voidSetPinValue(KPD_PORT, KPD_u8ColPins[Local_u8ColIterator], HIGH);
	}
	
	return Local_u8PressedKey;
}