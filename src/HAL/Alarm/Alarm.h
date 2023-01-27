/*Alarm means Buzzer*/
#include "../../MCAL/DIO/DIO.h"

#ifndef ALARM_H_
#define ALARM_H_

#define Alarm_Signal    DIO_A3

void Alarm_Init(void);
void Alarm_ON(void);
void Alarm_OFF(void);
void Alarm_Cycle(void);

#endif
