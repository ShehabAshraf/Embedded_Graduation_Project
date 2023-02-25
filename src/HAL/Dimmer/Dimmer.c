#include "Dimmer.h"




void Dimmer_INIT(void)
{
    /*Dimmer pin D3 ==> Led 2*/
    DIO_PinMode(DIO_D3,OUTPUT);
    /*Timer Enables*/
    Timers_T0_IntCompMtchEnable();
    Timers_T0_IntOverFlowEnable();
    /*GIE Enable*/
    GIE_voidEnable();
    /*Timer INIT*/
    Timers_T0_Init(TIMERS_T0_CLK_PS_1024,TIMERS_T0_MODE_FASTPWM,TIMERS_T0_OCPIN_NON_INVERTING_MODE,0);


    /*ADC INIT*/
    ADC_DisableAutoTrigger();
    ADC_Init			(ADC_CLK_PS_16);
    // u8 ADC_Reading_Value;
    DIO_PinMode(DIO_A1,INPUT);
}




void Dimmer_Level_3(void)
{
    Timers_T0_WG__PWM_B3			(255);
}

void Dimmer_Level_2(void)
{
    Timers_T0_WG__PWM_B3			(128);
}

void Dimmer_Level_1(void)
{
    Timers_T0_WG__PWM_B3			(64);
}

void Dimmer_Off(void)
{
    Timers_T0_WG__PWM_B3			(0);
}






/*************/
//ADC ps ==> 128
//ADC Read ==> POT pin ADC_CH1
//void ADC_DisableAutoTrigger();
//variable = ADC Read
/*************/

void Dimmer_POT_Control(void)
{
    Timers_T0_WG__PWM_B3(MAP(ADC_Read(ADC_CH1),0,1023,0,255));
}
