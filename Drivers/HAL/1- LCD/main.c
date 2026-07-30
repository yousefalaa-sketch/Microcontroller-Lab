#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "LCD_int.h"
#include <util/delay.h>

int main(void)
{
	DIO_voidInitialization();
	LCD_voidLCDInit();
	while(1)
	{
			LCD_voidSendData('5');
			LCD_voidWriteString("Mohamed");
			LCD_voidWriteNumber(225);
	}
	return 0;
}