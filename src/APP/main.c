// #include "../MCAL/Timer_2/Timer_2.h"
#include "../MCAL/Timer_1/Timer_1.h"
#include "../MCAL/DIO/DIO.h"
#include <util/delay.h>

// // int main()
// // {
//     // while (1)
//     // {
//     //     Alarm_Cycle();
//     // }
//     // Timer_2_INIT_With_OCV(FAST,OCV_2_Set,255);
//     // Timer_1_INIT_With_OCV(FAST,OCV_1_Set,OCV_1_Set,30000,0);


//     // DIO_PinMode(Alarm_Signal,OUTPUT);
//     // DIO_PinMode(DIO_D5,OUTPUT);
//     // DIO_DigitalWritePin(DIO_D3,HIGH);
    
//     // Alarm_Init();
    
//     // while (1)
//     // {
//         // Timer_2_PWM(255);
//         // _delay_ms(1000);
//         // Timer_2_PWM(128);
//         // _delay_ms(1000);
//         // Timer_2_PWM(0);
//         // _delay_ms(1000);
        
//         // Timer_1_PWM_A(15000);
//         // _delay_ms(1000);
//         // Timer_1_PWM_A(7500);
//         // _delay_ms(1000);
//         // Timer_1_PWM_A(0);
//         // _delay_ms(1000);

        
//     // }
    
// // }

// volatile u8 OVFcntr = 0;
// volatile float64 angl = 90;
// volatile float64 angl2 = 180;
// volatile float64 angl3 = 0;

// void OC2IntFn()
// {
//     if (OVFcntr == 0)
//     {
//         OCR2 = 0;
//     }
//     else if (OVFcntr == 1)
//     {
//         OCR2 = MAP(angl, 0, 180, 200, 231.25);
//         // TCNT2 = 200;


//     }
// }
// void OV2IntFn(void)
// {
//     if (OVFcntr == 0)
//     {
//         // OCR2 = 0;
//         OVFcntr = 1;
//         TCNT2 = 0x00;
//     }
//     else if (OVFcntr == 1)
//     {
//         TCNT2 = 200;
//         OVFcntr = 0;
//         // OCR2 = MAP(angl, 0, 180, 200, 231.25);
//     }
// }



// int main()
// {
    
//     DIO_PinMode (DIO_D7,OUTPUT);
    
//     Timer_2_INIT_With_OCV(FAST,OCV_2_Clear,MAP(angl,    0, 180,    200, 231.25));

//     // TCNT2 = 200;     //Not affecting


//     // SET_BIT(TCCR2,CS20);
//     // SET_BIT(TCCR2,CS21);
//     // SET_BIT(TCCR2,CS22);
    
//     Timer_2_OverFlow_Int_Enable();
//     Timer_2_Output_Compare_Int_Enable();

//     Timer_2_OverFlow_CallBack(OV2IntFn);
//     Timer_2_Output_Compare_CallBack(OC2IntFn);

//     Timer_2_INIT_With_OCV(FAST,OCV_2_Clear,MAP(angl2,    0, 180,    200, 231.25));
//     // Timer_2_INIT_With_OCV(FAST,OCV_2_Clear,MAP(angl3,    0, 180,    200, 231.25));



//     while (1)
//     {
//         // angl = 0; _delay_ms(1000);
//         // angl = 60; _delay_ms(1000);
//         // angl = 120; _delay_ms(1000);
//         // angl = 180; _delay_ms(1000);
//     }
    


// }




// void timer1_init() {
//     // Set the mode of Timer 1 to Fast PWM mode with TOP value in OCR1A
//     TCCR1A |= (1 << WGM11) | (1 << WGM10);
//     TCCR1B |= (1 << WGM13) | (1 << WGM12);
    
//     // Set the clock source for Timer 1 to F_CPU/8 (prescaler of 8)
//     TCCR1B |= (1 << CS11);
    
//     // Set the value to compare Timer 1's counter with for PWM period (50 Hz, 20 ms period)
//     OCR1AL = 39999;
    
//     // Set the initial value for the PWM duty cycle (50% duty cycle)
//     OCR1BL = 20000;
    
//     // Set the PWM output on OC1B pin (PD4)
//     DDRD |= (1 << DDD4);
//     TCCR1A |= (1 << COM1B1);

    

// }

// int main() 
// {
//     timer1_init();  // Initialize Timer 1
//     GIE_voidEnable();
//     Timer_1_Output_Compare_A_Int_Enable();
//     Timer_1_Output_Compare_B_Int_Enable();
//     Timer_1_Input_Capture_Int_Enable();
//     Timer_1_OverFlow_Int_Enable();

//     DIO_PinMode (DIO_D7,OUTPUT);
//     DIO_PinMode (DIO_D4,OUTPUT);


//     while (1) {
//         // Change the PWM duty cycle (10% to 90% in steps of 10%)
//         for (int duty_cycle = 10000; duty_cycle <= 36000; duty_cycle += 10000) {
//             OCR1BL = duty_cycle;
//             _delay_ms(1000);
//         }
//     }
//     return 0;
// }

// void OV(void)
// {
//     TCNT1L=0x00;
//     TCNT1H=0x00;
// }
// void OCB(void)
// {
//     OCR1BL= 0;
//     OCR1BH= 0;
// }

// int main()
// {
//     GIE_voidEnable();
//     Timer_1_Output_Compare_A_Int_Enable();
//     Timer_1_Output_Compare_B_Int_Enable();
//     Timer_1_Input_Capture_Int_Enable();
//     Timer_1_OverFlow_Int_Enable();

//     DIO_PinMode(DIO_D7,OUTPUT);

//     Timer_1_INIT_With_OCV(FAST,OCV_1_Clear,OCV_1_Clear,39999,20000);

//     Timer_1_OverFlow_CallBack(OV);
//     Timer_1_Output_Compare_B_CallBack(OCB);


//     while (1)
//     {
//         /* code */
//     }
    
// }


// #include <avr/io.h>
// #include <util/delay.h>

// // BitMath functions
// #define SET_BIT(PORT, BIT) PORT |= (1 << BIT)
// #define CLR_BIT(PORT, BIT) PORT &= ~(1 << BIT)

// void timer1_init() {
//     // Set the mode of Timer 1 to Fast PWM mode with TOP value in OCR1A
//     SET_BIT(TCCR1A, WGM11);
//     SET_BIT(TCCR1A, WGM10);
//     SET_BIT(TCCR1B, WGM13);
//     SET_BIT(TCCR1B, WGM12);
    
//     // Set the clock source for Timer 1 to F_CPU/8 (prescaler of 8)
//     SET_BIT(TCCR1B, CS11);
    
//     // Set the value to compare Timer 1's counter with for PWM period (50 Hz, 20 ms period)
//     OCR1AL = 39999;
    
//     // Set the initial value for the PWM duty cycle (50% duty cycle)
//     OCR1BL = 20000;
    
//     // Set the PWM output on OC1B pin (PD4)
//     // SET_BIT(DDRD, DDD4);
//     DIO_PinMode(DIO_D4,OUTPUT);

//     SET_BIT(TCCR1A, COM1B1);
//     /**/
//     SET_BIT(TCCR1B,COM1B0);
//     SET_BIT(TCCR1B,COM1B1);
//     SET_BIT(TCCR1A,COM1A0);
//     SET_BIT(TCCR1A,COM1A1);
//     /**/
//     // Enable global interrupts
//     GIE_voidEnable();
// }

// void servo_init() {
//     // Set the direction of pin D7 to output
//     // SET_BIT(DDRD, DDD7);
//     DIO_PinMode(DIO_D7,OUTPUT);
// }

// void servo_set_angle(int angle) {
//     // Map the angle value to a PWM duty cycle value
//     int duty_cycle = ((angle * 2000) / 180) + 1000;
//     OCR1BL = duty_cycle;
// }

// int main() {
//     timer1_init();  // Initialize Timer 1
//     servo_init();   // Initialize servo motor control
    
//     while (1) {
//         // Set the servo motor angle to 0 degrees
//         servo_set_angle(0);
//         _delay_ms(1000);
        
//         // Set the servo motor angle to 90 degrees
//         servo_set_angle(90);
//         _delay_ms(1000);
        
//         // Set the servo motor angle to 180 degrees
//         servo_set_angle(180);
//         _delay_ms(1000);
//     }
//     return 0;
// }

void ICR_Fcn(void)
{
    TCNT1L = 0x00;
    TCNT1H = 0x00;
}


int main()
{
    GIE_voidEnable();
    Timer_1_Input_Capture_Int_Enable();
    Timer_1_Output_Compare_A_Int_Enable();
    Timer_1_Output_Compare_B_Int_Enable();
    Timer_1_OverFlow_Int_Enable();
    DIO_PinMode(DIO_D7,OUTPUT);
    // DIO_PinMode(DIO_D4,OUTPUT);
    Timer_1_INIT_With_OCV(FAST,OCV_1_Clear,OCV_1_Clear,1000,1000);
    Timer_1_ICR(20000);
    
    Timer_1_Input_Capture_CallBack(ICR_Fcn);

    while (1)
    {
        _delay_ms(1000);
        Timer_1_OCR1B(1500);
        _delay_ms(1000);
        Timer_1_OCR1B(2000);
        _delay_ms(1000);
        Timer_1_OCR1B(1000);
    }
}