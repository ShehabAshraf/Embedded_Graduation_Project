#include "../HAL/Alarm/Alarm.h"
#include "../MCAL/Timer_2/Timer_2.h"
#include "../MCAL/Timer_1/Timer_1.h"
#include <util/delay.h>

// int main()
// {
    // while (1)
    // {
    //     Alarm_Cycle();
    // }
    // Timer_2_INIT_With_OCV(FAST,OCV_2_Set,255);
    // Timer_1_INIT_With_OCV(FAST,OCV_1_Set,OCV_1_Set,30000,0);


    // DIO_PinMode(Alarm_Signal,OUTPUT);
    // DIO_PinMode(DIO_D5,OUTPUT);
    // DIO_DigitalWritePin(DIO_D3,HIGH);
    
    // Alarm_Init();
    
    // while (1)
    // {
        // Timer_2_PWM(255);
        // _delay_ms(1000);
        // Timer_2_PWM(128);
        // _delay_ms(1000);
        // Timer_2_PWM(0);
        // _delay_ms(1000);
        
        // Timer_1_PWM_A(15000);
        // _delay_ms(1000);
        // Timer_1_PWM_A(7500);
        // _delay_ms(1000);
        // Timer_1_PWM_A(0);
        // _delay_ms(1000);

        
    // }
    
// }

volatile u8 OVFcntr = 0;
volatile float64 angl = 90;

void OC2IntFn()
{
    if (OVFcntr == 0)
    {
        OCR2 = 0;
    }
    else if (OVFcntr == 1)
    {
        OCR2 = MAP(angl, 0, 180, 200, 231.25);
        // TCNT2 = 200;


    }
}
void OV2IntFn(void)
{
    if (OVFcntr == 0)
    {
        // OCR2 = 0;
        OVFcntr = 1;
        TCNT2 = 0x00;
    }
    else if (OVFcntr == 1)
    {
        TCNT2 = 200;
        OVFcntr = 0;
        // OCR2 = MAP(angl, 0, 180, 200, 231.25);
    }
}

int main()
{
    
    DIO_PinMode (DIO_D7,OUTPUT);
    
    Timer_2_INIT_With_OCV(FAST,OCV_2_Clear,MAP(angl,    0, 180,    200, 231.25));

    // TCNT2 = 200;     //Not affecting


    // SET_BIT(TCCR2,CS20);
    // SET_BIT(TCCR2,CS21);
    // SET_BIT(TCCR2,CS22);
    
    Timer_2_OverFlow_Int_Enable();
    Timer_2_Output_Compare_Int_Enable();

    Timer_2_OverFlow_CallBack(OV2IntFn);
    Timer_2_Output_Compare_CallBack(OC2IntFn);
    while (1)
    {
        // angl = 0; _delay_ms(1000);
        // angl = 60; _delay_ms(1000);
        // angl = 120; _delay_ms(1000);
        // angl = 180; _delay_ms(1000);
    }
    


}