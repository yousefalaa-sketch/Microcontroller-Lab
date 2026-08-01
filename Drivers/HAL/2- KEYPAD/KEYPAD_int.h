/************************************************/
/********* Author: Yousef Alaa *****************/
/********* Date  : 31/07/2026   *****************/
/********* File  : Interface File ***************/
/************************************************/
#ifndef   KEYPAD_INTERFACE_H
#define   KEYPAD_INTERFACE_H

#define KPD_NOT_PRESSED     0xFF

void KPD_voidInit(void);
u8   KPD_u8GetPressedKey(void);

#endif