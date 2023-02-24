#ifndef AIRCOND_H_INCLUDED
#define AIRCOND_H_INCLUDED

#include "../../MCAL/DIO/DIO.h"
//#include "../../MCAL/PWM/PWM.h"
#include "../../MCAL/ADC/ADC.h"

#include "AIRCOND_Config.h"
void Air_conditioner_on(u8 OMega)
{
DIO_DigitalWritePin(DIO_B7,HIGH);
//Analog_W(DIO_B7,OMega)
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void Air_conditioner_off(){
DIO_DigitalWritePin(DIO_B7,LOW);//relay
//disable timer
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int Air_conditionar_check(){
float64 Il=0, TEMP_senseor_reading, TEMP_senseor_readingavg=0;
for(;Il<1001;){
TEMP_senseor_reading=ADC_Read(TEMPADC);
TEMP_senseor_readingavg += Vrefrence*TEMP_senseor_reading/1023.00/LMfactor;
Il++;
}
TEMP_senseor_readingavg=TEMP_senseor_readingavg/1000.00;

if (TEMP_senseor_readingavg >(21))
{
Air_conditioner_on(TEMP_senseor_readingavg*1023/40);
}
else if (TEMP_senseor_readingavg <(20))
 {Air_conditioner_off();}
 return TEMP_senseor_readingavg ;
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void Intialise_smart_home(){
ADC_Init(7);//air conditioner prescaller 128

DIO_PinMode(DIO_B7,OUTPUT);
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void ending_sequance(){
Air_conditioner_off();
ADC_Disable();	
}

#endif















