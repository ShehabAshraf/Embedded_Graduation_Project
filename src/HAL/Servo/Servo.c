#include "Servo.h"

/*Connecting Servo D7 to Timer 1 OCRB D4*/


void Servo_INIT(void)
{
    /*Make Servo pin Output*/
    DIO_PinMode(Servo_Signal,OUTPUT);

    /*General Int Enable*/
    GIE_voidEnable();

    /*Timer 1 INTs Enable*/
    Timer_1_Input_Capture_Int_Enable();
    Timer_1_OverFlow_Int_Enable();
    Timer_1_Output_Compare_A_Int_Enable();
    Timer_1_Output_Compare_B_Int_Enable();

    /*Timer 1 Mode ==> Fast PWM*/
    /*NON Inverting Mode*/
    /*Ton = Toff = 1 ms*/
    Timer_1_INIT_With_OCV(FAST,OCV_1_Clear,OCV_1_Clear,1000,1000);

    /*Timer 1 periodic Time = 20 ms*/
    Timer_1_ICR(20000);

}

void Servo_Open_Door (void)
{
    Timer_1_OCR1B(1500);    //Angle = 0
}


void Servo_Close_Door (void)
{
    Timer_1_OCR1B(1000);    //Angle = 90
}
