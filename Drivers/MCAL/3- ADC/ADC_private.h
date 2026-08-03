/************************************************/
/********* Author: Yousef Alaa *****************/
/********* Date  : 2/08/2026   *****************/
/********* File  : Private File *****************/
/************************************************/

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define ADMUX     (*(volatile u8*)0x27)   /* Mux + Reference + Adjust  */
#define ADCSRA    (*(volatile u8*)0x26)   /* Control & Status Reg A    */
#define ADCH      (*(volatile u8*)0x25)   /* Data Register - High byte */
#define ADCL      (*(volatile u8*)0x24)   /* Data Register - Low byte  */
#define SFIOR     (*(volatile u8*)0x50)   /* Holds ADTS2:0 (trigger src)*/

/* ------------- ADMUX Register Bits ------------- */
#define REFS1     7
#define REFS0     6
#define ADLAR     5
#define MUX4      4
#define MUX3      3
#define MUX2      2
#define MUX1      1
#define MUX0      0

/* ------------- ADCSRA Register Bits ------------- */
#define ADEN      7     /* ADC Enable            */
#define ADSC      6     /* ADC Start Conversion   */
#define ADATE     5     /* ADC Auto Trigger Enable*/
#define ADIF      4     /* ADC Interrupt Flag     */
#define ADIE      3     /* ADC Interrupt Enable   */
#define ADPS2     2
#define ADPS1     1
#define ADPS0     0
/* ------------- SFIOR Register Bits (Trigger Source select) ------------- */
#define ADTS2     7
#define ADTS1     6
#define ADTS0     5
/* ------------- Configuration Options ------------- */
#define LEFT_ADJUSTMENT    1
#define RIGHT_ADJUSTMENT   0
#define FREE_RUNNING       0

#ifndef NULL
#define NULL ((void*)0)
#endif
#endif