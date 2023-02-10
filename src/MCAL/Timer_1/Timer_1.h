#include "../../Memory_Map/MEM_MAP.h"
#include "../General_Interrupt/General_Interrupt.h"
#include "../Ext_Interrupt/EXT_Interrupt.h"
#include "../../UTILS/BitMath.h"
#include "../../UTILS/STD_Types.h"


#ifndef TIMER_1_H
#define TIMER_1_H

/*Timer 2 Output_Compare Modes (Default = Normal)*/
#define OCV_1_Normal  0
#define OCV_1_Toggle  1
#define OCV_1_Clear   2
#define OCV_1_Set     3

/*WaveForm Modes (Default = Normal)*/
#define Normal 0
#define PWM    1
#define CTC    2
#define FAST   3

void __vector_6(void) __attribute__((signal, used)); //Capture 
void __vector_7(void) __attribute__((signal, used)); //Compare match A
void __vector_8(void) __attribute__((signal, used)); //Compare match B
void __vector_9(void) __attribute__((signal, used)); //OverFlow

void Timer_1_INIT_With_OCV(u8 WAVEFORM_MODE, u8 TIMER_1_OUTPUT_COMPARE_MODE_A, u8 TIMER_1_OUTPUT_COMPARE_MODE_B, u16 TIMER_1_OCV_A,  u16 TIMER_1_OCV_B);


void Timer_1_OverFlow_Int_Enable(void);
void Timer_1_Output_Compare_A_Int_Enable(void);
void Timer_1_Output_Compare_B_Int_Enable(void);

void Timer_1_OverFlow_Int_Disable(void);
void Timer_1_Output_Compare_A_Int_Disable(void);
void Timer_1_Output_Compare_B_Int_Disable(void);

void Timer_1_Input_Capture_Int_Enable(void);
void Timer_1_Input_Capture_Int_Disable(void);

void Timer_1_PWM_A   (u16 Timer_1_OCV_A);    
void Timer_1_PWM_B   (u16 Timer_1_OCV_B);

void Timer_1_OverFlow_CallBack(void(*ptrfcn)(void));
void Timer_1_Output_Compare_A_CallBack(void(*ptrfcn)(void));
void Timer_1_Output_Compare_B_CallBack(void(*ptrfcn)(void));
void Timer_1_Input_Capture_CallBack(void(*ptrfcn)(void));

#endif
