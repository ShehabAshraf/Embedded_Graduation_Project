#include "../HAL/Alarm/Alarm.h"
#include "../MCAL/Timer_2/Timer_2.h"
#include <util/delay.h>

int main()
{
    // while (1)
    // {
    //     Alarm_Cycle();
    // }
    // Timer_2_INIT_With_OCV(FAST,OCV_2_Set,255);

    DIO_PinMode(DIO_A3,OUTPUT);
    DIO_PinMode(DIO_D7,OUTPUT);
    // DIO_DigitalWritePin(DIO_D3,HIGH);
    
    Alarm_Init();
    
    while (1)
    {
        // Timer_2_PWM(255);
        // _delay_ms(1000);
        // Timer_2_PWM(128);
        // _delay_ms(1000);
        // Timer_2_PWM(0);
        // _delay_ms(1000);

        
    }
    


}