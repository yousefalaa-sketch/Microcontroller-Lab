/************************************************/
/********* Author: Yousef Alaa *****************/
/********* Date  : 05/08/2026   *****************/
/********* File  : Interface File ***************/
/************************************************/

#ifndef DCMOTOR_INT_H
#define DCMOTOR_INT_H

/* Description : Sets the motor pins as OUTPUT and STOP state
 *               Must be called once before any other function */
void DCMOTOR_voidInitialization(void);

/* Description : Moves the elevator cabin UP    (IN1=1 , IN2=0) */
void DCMOTOR_voidMoveUp(void);

/* Description : Moves the elevator cabin DOWN  (IN1=0 , IN2=1) */
void DCMOTOR_voidMoveDown(void);

/* Description : Stops the motor                (IN1=0 , IN2=0) */
void DCMOTOR_voidStop(void);

#endif
