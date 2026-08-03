/************************************************/
/********* Author: Yousef Alaa *****************/
/********* Date  : 2/08/2026   *****************/
/********* File: Program File  *****************/
/********* File: Program File  *****************/
/************************************************/

#include "Std_Types.h"
#include "Bit_Math.h"

#include "ADC_int.h"
#include "ADC_private.h"
#include "ADC_config.h"


 /* ADC_voidSetCallBack(). */
static pf ADC_CallBack = NULL;


void ADC_voidInit(void)
{
//Disable ADC
CLR_BIT(ADCSRA, ADEN);
//Disable Start Conveerion
CLR_BIT(ADCSRA, ADSC);
//Disable Auto Trigger
CLR_BIT(ADCSRA, ADATE);
//Clear Interrupt Flag
SET_BIT(ADCSRA, ADIF);
//Disable ADC Interrupt
CLR_BIT(ADCSRA, ADIE);
//Select Left or Right Adlustment
if ( REG_ADJ == LEFT_ADJUSTMENT)
		SET_BIT(ADMUX, ADLAR);
	else if( REG_ADJ == RIGHT_ADJUSTMENT)
		CLR_BIT(ADMUX, ADLAR);
// Slect ADC Channel	
ADMUX = (ADMUX & 0xE0) | (ADC_CHANNEL & 0x1F);
// Select Clock Prescaller
SET_BIT(ADCSRA, ADPS2);
SET_BIT(ADCSRA, ADPS1);
SET_BIT(ADCSRA, ADPS0);
}


void ADC_voidADCEnable (void)
{
	SET_BIT(ADCSRA, ADEN);
}
//ADC Enable

void ADC_voidADCDisable(void)
{
	CLR_BIT(ADCSRA, ADEN);
}
//ADC Disable


u16 ADC_u16Read(void)
{
	u16 Local_u16Result = 0;
	#if REG_ADJ == LEFT_ADJUSTMENT
	Local_u16Result = ADCH;
	#elif REG_ADJ == RIGHT_ADJUSTMENT
	Local_u16Result  = ADCL;
	Local_u16Result |= ((u16)ADCH << 8);
	#endif
	return Local_u16Result;
}




void ADC_voidStartConversion(void)
{
	SET_BIT(ADCSRA, ADSC);
}


//Set auto Trigger Enable
// set the source of auto Trigger
void ADC_voidAutoTriggerEnable(void)
{
	SET_BIT(ADCSRA, ADATE);
}
 
 
void ADC_voidAutoTriggerDisable(void)
{
	CLR_BIT(ADCSRA, ADATE);
}



void ADC_voidInterruptEnable(void)
{
	SET_BIT(ADCSRA, ADIE);
}
 
 
void ADC_voidInterruptDisable(void)
{
	CLR_BIT(ADCSRA, ADIE);
}
 

void ADC_voidSetCallBack(pf FunctionAddress)
{
	if (FunctionAddress != NULL)
    {
        ADC_CallBack = FunctionAddress;
    }
}


void __vector_16(void)  __attribute__((signal, used));
void __vector_16(void)
{
	if (ADC_CallBack != NULL)
	{
		ADC_CallBack();
	}
}