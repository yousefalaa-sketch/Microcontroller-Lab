/************************************************/
/********* Author: Yousef Alaa *****************/
/********* Date  : 1/08/2026   *****************/
/********* File: interface File  *****************/
/************************************************/

#ifndef ADC_INT_H
#define ADC_INT_H
/* ==================== ADC Channels ==================== */
#define ADC_CHANNEL0     0
#define ADC_CHANNEL1     1
#define ADC_CHANNEL2     2
#define ADC_CHANNEL3     3
#define ADC_CHANNEL4     4
#define ADC_CHANNEL5     5
#define ADC_CHANNEL6     6
#define ADC_CHANNEL7     7

/* Function pointer type used for the Call Back (ISR notification) */
typedef void (*pf)(void);
 
/* Initialize ADC according to ADC_config.h (channel, adjust, trigger source) */
void ADC_voidInit(void);
 
/* Enable / Disable the ADC peripheral (ADEN bit) */
void ADC_voidADCEnable(void);
void ADC_voidADCDisable(void);
 
/* Start a single conversion (ADSC bit) */
void ADC_voidStartConversion(void);
 
/* Enable / Disable Auto Trigger mode (ADATE bit) */
void ADC_voidAutoTriggerEnable(void);
void ADC_voidAutoTriggerDisable(void);
 
/* Enable / Disable ADC Interrupt (ADIE bit) */
void ADC_voidInterruptEnable(void);
void ADC_voidInterruptDisable(void);
 
/* Register a function to be called from the ADC ISR when conversion completes */
void ADC_voidSetCallBack(pf FunctionAddress);
 
/* Read last conversion result (Polling method - blocking) */
u16 ADC_u16Read(void);
 

#endif