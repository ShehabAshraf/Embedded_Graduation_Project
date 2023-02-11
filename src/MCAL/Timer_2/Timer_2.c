#include "Timer_2.h"


void Timer_2_INIT_With_OCV(u8 WAVEFORM_MODE, u8 TIMER_2_OUTPUT_COMPARE_MODE, u8 TIMER_2_OCV)
{

    SET_BIT(TIFR,TOV2);
    SET_BIT(TIFR,OCF2);

    /*Selecting WaveForm Mode*/
    switch (WAVEFORM_MODE)
    {
    case Normal:
        CLR_BIT(TCCR2,WGM20);
        CLR_BIT(TCCR2,WGM21);
        break;
    case PWM:
        SET_BIT(TCCR2,WGM20);
        CLR_BIT(TCCR2,WGM21);
    break;
    case CTC:
        CLR_BIT(TCCR2,WGM20);
        SET_BIT(TCCR2,WGM21);
    break;
    case FAST:
        SET_BIT(TCCR2,WGM20);
        SET_BIT(TCCR2,WGM21);
     break;
    default:
        break;
    }

    /*Setting Prescaler (/1024)*/
    SET_BIT(TCCR2,CS20);
    SET_BIT(TCCR2,CS21);
    SET_BIT(TCCR2,CS22);

    /*Selecting Output compare mode*/
    switch (TIMER_2_OUTPUT_COMPARE_MODE)
    {
        case OCV_2_Normal:
            CLR_BIT(TCCR2,COM20);
            CLR_BIT(TCCR2,COM21);
            break;
        case OCV_2_Toggle:
            if (WAVEFORM_MODE == CTC)
            {
                SET_BIT(TCCR2,COM20);
                CLR_BIT(TCCR2,COM21);
            }
            break;
        case OCV_2_Clear:
            CLR_BIT(TCCR2,COM20);
            SET_BIT(TCCR2,COM21);
            break;
        case OCV_2_Set:
            SET_BIT(TCCR2,COM20);
            SET_BIT(TCCR2,COM21);
            break;
        default:
            break;
    }

    /*Make Output Compare Reg = Value Needed*/
    OCR2 = TIMER_2_OCV;


    /*Clearing TCNT2 Reg to start Counting*/
    TCNT2 = 200;

}


void Timer_2_OverFlow_Int_Enable(void)
{
    GIE_voidEnable();
    SET_BIT(TIMSK,TOIE2);
    SET_BIT(TIFR,TOV2);
}

void Timer_2_Output_Compare_Int_Enable(void)
{
    GIE_voidEnable();
    SET_BIT(TIMSK,OCIE2);
    SET_BIT(TIFR,OCF2);
}

void Timer_2_OverFlow_Int_Disable(void)
{
    GIE_voidDisable();
    CLR_BIT(TIMSK,TOIE2);
    CLR_BIT(TIFR,TOV2);
}

void Timer_2_Output_Compare_Int_Disable(void)
{
    GIE_voidDisable();
    CLR_BIT(TIMSK,OCIE2);
    CLR_BIT(TIFR,OCF2);
}


void Timer_2_PWM   (u8 Timer_2_OCV)
{
    OCR2 = Timer_2_OCV;
}



void (*Timer_2_OV_Genptr) (void) = NULL_PTR;

void Timer_2_OverFlow_CallBack(void(*ptrfcn)(void))
{
    if (ptrfcn != NULL_PTR)
    {
        Timer_2_OV_Genptr = ptrfcn;
    }
}

void __vector_5(void)
{
    SET_BIT(TIFR,TOV2);
    Timer_2_OV_Genptr();
}



void (*Timer_2_OC_Genptr) (void) = NULL_PTR;

void Timer_2_Output_Compare_CallBack(void(*ptrfcn)(void))
{
    if (ptrfcn != NULL_PTR)
    {
        Timer_2_OC_Genptr = ptrfcn;
    }
}

void __vector_4(void)
{
    SET_BIT(TIFR,OCF2);
    Timer_2_OC_Genptr();
}