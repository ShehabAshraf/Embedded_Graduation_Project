#include "General_Interrupt.h"

void GIE_voidEnable(void)
{
    SET_BIT(SREG,SREG_I);
}

void GIE_voidDisable(void)
{
    CLR_BIT(SREG,SREG_I);
}
