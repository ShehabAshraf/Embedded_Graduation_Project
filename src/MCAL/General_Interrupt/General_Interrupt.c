#include "General_Interrupt.h"

void GIE_voidEnable(void)
{
    SET_BIT(SREG,SREG_I);
}

void GIE_voidDisable(void)
{
    CLEAR_BIT(SREG,SREG_I);
}
