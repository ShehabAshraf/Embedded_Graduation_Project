#include "EXT_Interrupt.h"

void EXT_INT0_void_INIT(void)
{
    //MCUCR ==> MCU Control Register
    
    //Selecting mode
    if (SENSE_MODE == EXT_FALLING)
    {
        CLR_BIT(MCUCR,ISC00);
        SET_BIT(MCUCR,ISC01);
    }
    else if (SENSE_MODE == EXT_RISING)
    {
        SET_BIT(MCUCR,ISC01);
        SET_BIT(MCUCR,ISC00);
    }
    else if (SENSE_MODE == EXT_LOW)
    {
        CLR_BIT(MCUCR,ISC01);
        CLR_BIT(MCUCR,ISC00);
    }
    else if (SENSE_MODE == EXT_ANY_LC)
    {
        SET_BIT(MCUCR,ISC00);
        CLR_BIT(MCUCR,ISC01);
    }
    else{/*Diable interupt*/}

    /*Enabling Int 0*/
    SET_BIT(GICR,INT0);

    /*Clearing Int 0 flag*/
    CLR_BIT(GIFR,INTF0);

}

void EXT_INT0_void_Enable(void)
{
    SET_BIT(GICR,INT0);
}

void EXT_INT0_void_Disable(void)
{
    CLR_BIT(GICR,INT0);
}

void (*Genptr_0) (void) = NULL_PTR;


void EXT_INT0_CallBackFunction(void(*ptrfcn)(void))
{
    if (ptrfcn != NULL_PTR)
    {
        Genptr_0 = ptrfcn;
    }
    
}

void __vector_1(void)
{
    Genptr_0();
}