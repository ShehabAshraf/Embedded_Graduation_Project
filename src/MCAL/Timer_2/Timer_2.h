#include "../../Memory_Map/MEM_MAP.h"
#include "../General_Interrupt/General_Interrupt.h"
#include "../Ext_Interrupt/EXT_Interrupt.h"
#include "../../UTILS/BitMath.h"
#include "../../UTILS/STD_Types.h"

#ifndef TIMER_2_H
#define TIMER_2_H


// #define WaveForm_Mode 0
/*WaveForm Modes (Default = Normal)*/
#define Normal 0
#define PWM    1
#define CTC    2
#define FAST   3

// #define Timer_2_Output_Compare_Mode 0
/*Timer 2 Output_Compare Modes (Default = Normal)*/
#define OCV_2_Normal  0
#define OCV_2_Toggle  1
#define OCV_2_Clear   2
#define OCV_2_Set     3

/*Vector Table (P 44)*/
void __vector_5(void) __attribute__((signal, used)); //OverFlow 
void __vector_4(void) __attribute__((signal, used)); //Compare match




/*Functions*/
void Timer_2_INIT_With_OCV(u8 WAVEFORM_MODE, u8 TIMER_2_OUTPUT_COMPARE_MODE, u8 TIMER_2_OCV);

void Timer_2_OverFlow_Int_Enable(void);
void Timer_2_Output_Compare_Int_Enable(void);

void Timer_2_OverFlow_Int_Disable(void);
void Timer_2_Output_Compare_Int_Disable(void);

void Timer_2_PWM   (u8 Timer_2_OCV);    //Changes OCV in OCR


void Timer_2_OverFlow_CallBack(void(*ptrfcn)(void));
void Timer_2_Output_Compare_CallBack(void(*ptrfcn)(void));

#endif

