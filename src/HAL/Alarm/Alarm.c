#include "Alarm.h"
#include <util/delay.h>


void Alarm_Init(void)
{
    DIO_PinMode(DIO_A3,OUTPUT);
}


void Alarm_ON(void)
{
    DIO_DigitalWritePin(Alarm_Signal,HIGH);
}

void Alarm_OFF(void)
{
    DIO_DigitalWritePin(Alarm_Signal,LOW);
}

void Alarm_Cycle(void)
{
    Alarm_ON();
    _delay_ms(500);
    Alarm_OFF();
    _delay_ms(500);
}