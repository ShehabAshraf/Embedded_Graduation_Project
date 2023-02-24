#ifndef AIRCOND_H_INCLUDED
#define AIRCOND_H_INCLUDED
//#include "../../MCAL/PWM/PWM.h"

#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/ADC/ADC.h"
#include "AIRCOND_Config.h"

void Air_conditioner_on(u8 OMega);
void Air_conditioner_off();
int Air_conditionar_check();
void ending_sequance();
void Intialise_smart_home();

#endif
