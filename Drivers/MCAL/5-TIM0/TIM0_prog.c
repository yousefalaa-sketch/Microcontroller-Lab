/************************************************/
/********* Author: Yousef Alaa *****************/
/********* Date  : 4/08/2026   *****************/
/********* File: Program File  *****************/
/********* File: Program File  *****************/
/************************************************/

#include "Std_Types.h"
#include "Bit_Math.h"

#include "TIM0_int.h"
#include "TIM0_private.h"
#include "TIM0_config.h"

/* Global CallBack Pointers */
static pf FunctionAddress1 = NULL;
static pf FunctionAddress2 = NULL;


void TIM0_voidinit(void)
{
//Select Prescaller
TCCR0 = (TCCR0 & 0xF8) | (PRESCALLER);
//Select Mode
#if TIM0_MODE == TIM0_NORMAL_MODE
        CLR_BIT(TCCR0, 6); // WGM00
        CLR_BIT(TCCR0, 3); // WGM01
    #elif TIM0_MODE == TIM0_CTC_MODE
        CLR_BIT(TCCR0, 6); // WGM00
        SET_BIT(TCCR0, 3); // WGM01
    #elif TIM0_MODE == TIM0_FAST_PWM_MODE
        SET_BIT(TCCR0, 6); // WGM00
        SET_BIT(TCCR0, 3); // WGM01
    #elif TIM0_MODE == TIM0_PHASE_CORRECT_MODE
        SET_BIT(TCCR0, 6); // WGM00
        CLR_BIT(TCCR0, 3); // WGM01
    #endif
//Clear Bit 4 -5
CLR_BIT(TCCR0, 4);
CLR_BIT(TCCR0, 5);
//disable overflow interrupt
CLR_BIT(TIMSK, 0);
//disable on Compare match interrupt
CLR_BIT(TIMSK, 1);
//Clear overflow flag
SET_BIT(TIFR, 0);
//Clear on Compare match flag
SET_BIT(TIFR, 1);
//Clear TCNT0
TCNT0 = 0;
//Clear OCR
OCR0=0;
}


/********Normal Mode*********/
void TIM0_voidEnableOVInterrupt(void)
{
// to Enable theinterrupt ofOver flow
SET_BIT(TIMSK, 0);
}


void TIM0_voidDisableOVInterrupt(void)
{
// to Disable theinterrupt ofOver flow
CLR_BIT(TIMSK, 0);
}
void TIM0_voidSetOVReg(u8 u8OVRegValue)
{
//to Set the overflow Register(TCNT0) with specificValue
TCNT0 = u8OVRegValue;
}

u8 TIM0_u8ReadOVReg(void)
{
//to read the overflow Register(TCNT0)
return TCNT0;
}


void TIM0_voidOVSetCallBack(pf OVFunctionAddress)
{
	FunctionAddress1 = OVFunctionAddress;
}
//to Set theCall Back Function ofOverflow

//For Overflow
void __vector_11(void)  __attribute__((signal, used));
void __vector_11(void)
{
	if (FunctionAddress1 != NULL)
    {
        FunctionAddress1();
    }
}

/**************CTC Mode***********/
void TIM0_voidEnableCTCInterrupt(void)
{
// to Enable theinterrupt of CTC
SET_BIT(TIMSK, 1);
}
void TIM0_voidDisableCTCInterrupt(void)
{
// to Disable the interrupt of CTC
CLR_BIT(TIMSK, 1);
}
void TIM0_voidSetCTCReg(u8 u8CTCRegValue)
{
//to Set the CTC Register(OCR0) with specificValue
OCR0 = u8CTCRegValue;
}


u8 TIM0_u8ReadCTCReg(void)
{
//to read the CTC Register(OCR0)
return OCR0;
}

void TIM0_voidCTCSetCallBack(pf CTCFunctionAddress)
{
	FunctionAddress2 = CTCFunctionAddress;
}
//to Set theCall Back Function ofOverflow
//for On Compare Match
void __vector_10(void)  __attribute__((signal, used));
void __vector_10(void)
{
	if (FunctionAddress2 != NULL)
    {
        FunctionAddress2();
    }
}