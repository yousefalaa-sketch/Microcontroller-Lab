/************************************************/
/********* Author: Yousef Alaa *****************/
/********* Date  : 05/08/2026   *****************/
/********* File  : DCMOTOR_program.c *************/
/************************************************/
#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_int.h"

#include "DCMOTOR_int.h"
#include "DCMOTOR_private.h"
#include "DCMOTOR_config.h"

void DCMOTOR_voidInitialization(void)
{
	/* Configure the 3 control pins as OUTPUT */
	DIO_voidSetPinDirection(DCMOTOR_IN1, OUTPUT);
	DIO_voidSetPinDirection(DCMOTOR_IN2, OUTPUT);
	DIO_voidSetPinDirection(DCMOTOR_EN,OUTPUT);

	/* Motor must start in the STOP state */
	DIO_voidSetPinValue(DCMOTOR_IN1, LOW);
	DIO_voidSetPinValue(DCMOTOR_IN2,LOW);

	/* Basic version: ENABLE kept permanently HIGH (no PWM speed control yet) */
	DIO_voidSetPinValue(DCMOTOR_EN, HIGH);
}

void DCMOTOR_voidMoveUp(void)
{
	/* IN1 = 1 , IN2 = 0  -> UP */
	DIO_voidSetPinValue(DCMOTOR_IN1, HIGH);
	DIO_voidSetPinValue(DCMOTOR_IN2,LOW);
}

void DCMOTOR_voidMoveDown(void)
{
	/* IN1 = 0 , IN2 = 1  -> DOWN */
	DIO_voidSetPinValue(DCMOTOR_IN1, LOW);
	DIO_voidSetPinValue(DCMOTOR_IN2, HIGH);
}

void DCMOTOR_voidStop(void)
{
	/* IN1 = 0 , IN2 = 0  -> STOP */
	DIO_voidSetPinValue(DCMOTOR_IN1, LOW);
	DIO_voidSetPinValue(DCMOTOR_IN2, LOW);
}
