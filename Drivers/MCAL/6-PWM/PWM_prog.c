/************************************************/
/********* Author: Yousef Alaa *****************/
/********* Date  : 4/08/2026   *****************/
/********* File: Program File  *****************/
/********* File: Program File  *****************/
/************************************************/

#include "Std_Types.h"
#include "Bit_Math.h"

#include "PWM_int.h"
#include "PWM_private.h"
#include "PWM_config.h"
#include "DIO_int.h"


void PWM0_voidInit(void)
{
	 DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN3, OUTPUT);
	 
    #if PWM0_MODE == FAST_PWM
        SET_BIT(TCCR0, WGM00);
        SET_BIT(TCCR0, WGM01);
    #elif PWM0_MODE == PHASE_CORRECT_PWM
        SET_BIT(TCCR0, WGM00);
        CLR_BIT(TCCR0, WGM01);
    #endif

    #if PWM0_OUTPUT_MODE == NON_INVERTED
        CLR_BIT(TCCR0, COM00);
        SET_BIT(TCCR0, COM01);
    #elif PWM0_OUTPUT_MODE == INVERTED
        SET_BIT(TCCR0, COM00);
        SET_BIT(TCCR0, COM01);
    #endif
	
	TCCR0 &= 0xF8;  
 
    TCCR0 |= PWM0_PRESCALER;
}

void PWM0_voidSetDutyCycle(u8 Copy_u8DutyCycle)
{
	/**TO Ensure that dutycycle not exceed 100%***/
    if (Copy_u8DutyCycle <= 100)
    {
        #if PWM0_OUTPUT_MODE == NON_INVERTED
           
            OCR0 = (Copy_u8DutyCycle * 255) / 100;
            
        #elif PWM0_OUTPUT_MODE == INVERTED
           
            OCR0 = 255 - ((Copy_u8DutyCycle * 255) / 100);
        #endif
    }
}