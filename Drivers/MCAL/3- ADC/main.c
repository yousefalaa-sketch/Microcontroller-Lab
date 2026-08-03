/*
 * main.c

 *
 *  Created on: Jul 27, 2026
 *      Author: Dell
 */
#include "Std_Types.h"
#include "Bit_Math.h"
#include "ADC_int.h"

void main(void)
{
    ADC_voidInit();
    ADC_voidADCEnable();

    u16 local_reading = 0;

    while(1)
    {
        ADC_voidStartConversion();

        local_reading = ADC_u16Read();

    }
}
