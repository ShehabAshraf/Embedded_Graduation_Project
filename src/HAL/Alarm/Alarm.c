#include "Alarm.h"



float32 i = 0;

void Alarm_Init(void)
{
    DIO_PinMode(DIO_A3,OUTPUT);
    Timer_2_INIT_With_OCV(Normal,OCV_2_Normal,255);
    Timer_2_OverFlow_Int_Enable();
    Timer_2_OverFlow_CallBack(Alarm_Cycle);
}


void Alarm_ON(void)
{
    DIO_DigitalWritePin(Alarm_Signal,HIGH);
}

void Alarm_OFF(void)
{
    DIO_DigitalWritePin(Alarm_Signal,LOW);
}

void Alarm_TOG(void)
{
    DIO_DigitalTogglePin(Alarm_Signal);
}

void Alarm_Cycle(void)
{
    // Timer_2_INIT_With_OCV(Normal,OCV_2_Set,255);
    // Alarm_ON();
    // _delay_ms(500);
    // Alarm_OFF();
    // _delay_ms(500);


    if (i < 183)
    {
        i++;

    }
    else
    {
        i = 0;
        Alarm_TOG();
    }
    

    
}


