/************************************************/
/********* Author: Yousef Alaa *****************/
/********* Date  : 3/08/2026   *****************/
/********* File: Program File  *****************/
/********* File: Program File  *****************/
/************************************************/

#include "Std_Types.h"
#include "Bit_Math.h"

#include "GIE_int.h"
#include "GIE_private.h"
#include "GIE_config.h"



void GIE_voidEnable(void)
{
	SET_BIT(SREG, I_BIT);
}


void GIE_voidDisable(void)
{
	CLR_BIT(SREG, I_BIT);
}