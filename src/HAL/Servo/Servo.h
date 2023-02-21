#include "../../MCAL/Timer_1/Timer_1.h"
#include "../../MCAL/Timer_2/Timer_2.h"
#include "../../Memory_Map/MEM_MAP.h"
#include "../../UTILS/BitMath.h"
#include "../../UTILS//STD_Types.h"
#include "../../MCAL/DIO/DIO.h"

#ifndef SERVO_H
#define SERVO_H

#define Servo_Signal    DIO_D7


void Servo_INIT(void);

void Servo_Open_Door (void);
void Servo_Close_Door (void);

#endif