#include "../../UTILS/BitMath.h"
#include "../../UTILS/STD_Types.h"
#include "../../Memory_Map/MEM_MAP.h"

#ifndef EXT_INTERRUPT_H
#define EXT_INTERRUPT_H

#define NULL_PTR (void(*)(void))0

void EXT_INT0_void_INIT(void);
void EXT_INT0_void_Enable(void);
void EXT_INT0_void_Disable(void);

void EXT_INT0_CallBackFunction(void(*ptrfcn)(void));

void __vector_1(void) __attribute__((used))__attribute__((signal));

/* Sense Modes */
#define EXT_LOW     0
#define EXT_ANY_LC  1
#define EXT_FALLING 2
#define EXT_RISING  3

#define SENSE_MODE  3       //Make sense mode default ==> Rising



#endif