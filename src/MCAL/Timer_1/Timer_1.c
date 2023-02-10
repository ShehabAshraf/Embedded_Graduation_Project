#include "Timer_1.h"





void Timer_1_INIT_With_OCV(u8 WAVEFORM_MODE, u8 TIMER_1_OUTPUT_COMPARE_MODE_A, u8 TIMER_1_OUTPUT_COMPARE_MODE_B, u16 TIMER_1_OCV_A,  u16 TIMER_1_OCV_B)
{

    /*Setting all flags to clear it*/
    SET_BIT(TIFR,TOV1);
    SET_BIT(TIFR,OCF1A);
    SET_BIT(TIFR,OCF1B);
    SET_BIT(TIFR,ICF1);

    /*Selecting WaveForm Mode*/
    switch (WAVEFORM_MODE)
    {
    case Normal:
        CLR_BIT(TCCR1A,WGM10);
        CLR_BIT(TCCR1A,WGM11);
        CLR_BIT(TCCR1B,WGM12);
        CLR_BIT(TCCR1B,WGM13);
        break;
    case PWM:
        CLR_BIT(TCCR1A,WGM10);
        SET_BIT(TCCR1A,WGM11);
        CLR_BIT(TCCR1B,WGM12);
        SET_BIT(TCCR1B,WGM13);
    break;
    case CTC:
        CLR_BIT(TCCR1A,WGM10);
        CLR_BIT(TCCR1A,WGM11);
        SET_BIT(TCCR1B,WGM12);
        SET_BIT(TCCR1B,WGM13);
    break;
    case FAST:
        CLR_BIT(TCCR1A,WGM10);
        SET_BIT(TCCR1A,WGM11);
        SET_BIT(TCCR1B,WGM12);
        SET_BIT(TCCR1B,WGM13);
     break;
    default:
        break;
    }

    /*Setting Prescaler (/1024)*/
    SET_BIT(TCCR1B,CS10);
    SET_BIT(TCCR1B,CS11);
    SET_BIT(TCCR1B,CS12);


    /*Selecting Output compare mode A*/
    switch (TIMER_1_OUTPUT_COMPARE_MODE_A)
    {
        case OCV_1_Normal:
            CLR_BIT(TCCR1A,COM1A0);
            CLR_BIT(TCCR1A,COM1A1);
            break;
        case OCV_1_Toggle:
            if (WAVEFORM_MODE == CTC)       //Not Sure ??????????????????
            {
                SET_BIT(TCCR1A,COM1A0);
                CLR_BIT(TCCR1A,COM1A1);
            }
            break;
        case OCV_1_Clear:
            CLR_BIT(TCCR1A,COM1A0);
            SET_BIT(TCCR1A,COM1A1);
            break;
        case OCV_1_Set:
            SET_BIT(TCCR1A,COM1A0);
            SET_BIT(TCCR1A,COM1A1);
            break;
        default:
            break;
    }

    /*Selecting Output compare mode B*/
    switch (TIMER_1_OUTPUT_COMPARE_MODE_B)
    {
        case OCV_1_Normal:
            CLR_BIT(TCCR1B,COM1B0);
            CLR_BIT(TCCR1B,COM1B1);
            break;
        case OCV_1_Toggle:
            if (WAVEFORM_MODE == CTC)       //Not Sure ??????????????????
            {
                SET_BIT(TCCR1B,COM1B0);
                CLR_BIT(TCCR1B,COM1B1);
            }
            break;
        case OCV_1_Clear:
            CLR_BIT(TCCR1B,COM1B0);
            SET_BIT(TCCR1B,COM1B1);
            break;
        case OCV_1_Set:
            SET_BIT(TCCR1B,COM1B0);
            SET_BIT(TCCR1B,COM1B1);
            break;
        default:
            break;
    }


    /*Clearing TCNTs Regs to start counting*/
    TCNT1H = 0x00;
    TCNT1L = 0x00;


    /*Make Output Compare Reg = Value Needed*/
    // Taking 16 Bits and having 2 (8 bit) Regs 
    // 8 bits right will put in L
    // 8 Bits left will put in H
    OCR1BL = (TIMER_1_OCV_B);      
    OCR1BH = (TIMER_1_OCV_B >>8);
    OCR1AL = (TIMER_1_OCV_A);
    OCR1AH = (TIMER_1_OCV_A >> 8);
    
}


void Timer_1_OverFlow_Int_Enable(void)
{
    GIE_voidEnable();
    SET_BIT(TIMSK,TOIE1);
    SET_BIT(TIFR,TOV1);
}

void Timer_1_Output_Compare_A_Int_Enable(void)
{
    GIE_voidEnable();
    SET_BIT(TIMSK,OCIE1A);
    SET_BIT(TIFR,OCF1A);
}

void Timer_1_Output_Compare_B_Int_Enable(void)
{
    GIE_voidEnable();
    SET_BIT(TIMSK,OCIE1B);
    SET_BIT(TIFR,OCF1B);
}

void Timer_1_OverFlow_Int_Disable(void)
{
    GIE_voidDisable();
    CLR_BIT(TIMSK,TOIE1);
    CLR_BIT(TIFR,TOV1);
}

void Timer_1_Output_Compare_A_Int_Disable(void)
{
    GIE_voidDisable();
    SET_BIT(TIMSK,OCIE1A);
    SET_BIT(TIFR,OCF1A);
}

void Timer_1_Output_Compare_B_Int_Disable(void)
{
    GIE_voidDisable();
    SET_BIT(TIMSK,OCIE1B);
    SET_BIT(TIFR,OCF1B);
}

void Timer_1_Input_Capture_Int_Enable(void)
{
    GIE_voidEnable();
    SET_BIT(TIMSK,TICIE1);
    SET_BIT(TIFR,ICF1);
}

void Timer_1_Input_Capture_Int_Disable(void)
{
    GIE_voidDisable();
    CLR_BIT(TIMSK,TICIE1);
    CLR_BIT(TIFR,ICF1);
}

void Timer_1_PWM_A   (u16 Timer_1_OCV_A)
{
    OCR1AL = (Timer_1_OCV_A);
    OCR1AH = (Timer_1_OCV_A >> 8);
}    //Changes OCV in OCR1

void Timer_1_PWM_B   (u16 Timer_1_OCV_B)
{
    OCR1BL = (Timer_1_OCV_B);      
    OCR1BH = (Timer_1_OCV_B >>8);
}

void (*Timer_1_OV_Genptr) (void) = NULL_PTR;
void (*Timer_1_IC_Genptr) (void) = NULL_PTR;
void (*Timer_1_OC_A_Genptr) (void) = NULL_PTR;
void (*Timer_1_OC_B_Genptr) (void) = NULL_PTR;

void Timer_1_OverFlow_CallBack(void(*ptrfcn)(void))
{
    if (ptrfcn != NULL_PTR)
    {
        Timer_1_OV_Genptr = ptrfcn;
    }
}

void Timer_1_Output_Compare_A_CallBack(void(*ptrfcn)(void))
{
    if (ptrfcn != NULL_PTR)
    {
        Timer_1_OC_A_Genptr = ptrfcn;
    }
}

void Timer_1_Output_Compare_B_CallBack(void(*ptrfcn)(void))
{
    if (ptrfcn != NULL_PTR)
    {
        Timer_1_OC_B_Genptr = ptrfcn;
    }
}

void Timer_1_Input_Capture_CallBack(void(*ptrfcn)(void))
{
    if (ptrfcn != NULL_PTR)
    {
        Timer_1_IC_Genptr = ptrfcn;
    }
}

void __vector_6(void)
{
    Timer_1_IC_Genptr();
}

void __vector_7(void)
{
    Timer_1_OC_A_Genptr();
}

void __vector_8(void)
{
    Timer_1_OC_B_Genptr();
}

void __vector_9(void)
{
    Timer_1_OV_Genptr();
}
