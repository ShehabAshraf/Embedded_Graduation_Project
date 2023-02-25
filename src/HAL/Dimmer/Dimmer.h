#include "../../MCAL/DIO/DIO.h"
#include "../../Memory_Map/MEM_MAP.h"
#include "../../UTILS/BitMath.h"
#include "../../UTILS/STD_Types.h"
#include "../../MCAL/Timer_0/Timer_0.h"
#include "../../MCAL/ADC/ADC.h"

#ifndef DIMMER_H
#define DIMMER_H

void Dimmer_INIT(void);
void Dimmer_Level_1(void);
void Dimmer_Level_2(void);
void Dimmer_Level_3(void);
void Dimmer_Off(void);
void Dimmer_POT_Control(void);

#endif

