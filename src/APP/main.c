/* smart Home */
#include "../Memory_Map/MEM_MAP.h"
#include "../UTILS/BitMath.h"
#include "../UTILS/STD_Types.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/Ext_Interrupt/EXT_Interrupt.h"
#include "../MCAL/General_Interrupt/General_Interrupt.h"
#include "../MCAL/Timer_0/Timer_0.h"
#include "../MCAL/Timer_1/Timer_1.h"
#include "../MCAL/Timer_2/Timer_2.h"
#include "../HAL/Kit_config.h"
#include "../HAL/Alarm/Alarm.h"
#include "../HAL/Keypad/KeyPad.h"
#include "../HAL/Keypad/KeyPad_Config.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/LCD/LCD_Config.h"
#include "../HAL/Servo/Servo.h"
#include "../HAL/LED/LEDs.h"
#include "../HAL/LED/LEDs_Config.h"
#include "../HAL/AirCond/AIRCOND.h"
#include "../HAL/AirCond/AIRCOND_Config.h"
#include "../MCAL/EEPROM/EEPROM.h"
#include "../HAL/Dimmer/Dimmer.h"
#include "../MCAL/USART/USART.h"
#include "../HAL/Bluetooth/Bluetooth.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/******************************************/
// Keypad 0 ==> Trigger Alarm 
// Keypad 1 ==> Led On
// Keypad 2 ==> Led Off
// Keypad 3 ==> Open Door 
// Keypad 4 ==> Close Door
// Keypad 5 ==> Air Cond check
// Keypad 6 ==> Air Cond Off
// Keypad 9 ==> Dimmer on 
// Keypad 7 ==> Dimmer Level 1 
// Keypad B ==> Dimmer Level 2
// Keypad 8 ==> Dimmer Level 3
// Keypad A ==> 
// Keypad C ==> 
// Keypad D ==>
// Keypad * ==>
// Keypad # ==>
/******************************************/

/******************************************/
// Keypad Reading must be taken by interrupt
// 
//
//
/******************************************/







// int main()
// {
// LCD_Init();
// Servo_INIT();
// KeyPad_Init();
// Alarm_Init();
// GIE_voidEnable();
// Intialise_smart_home();
// LED_InitLED(LED0);
// LED_InitLED(LED1);
// LED_InitLED(LED2);
// toggleuart_blue();
// /*Ext Int makes conflict with alarm*/
// EXT_INT0_void_INIT(); 
// EXT_INT0_void_Enable();


// // /*Initialize Timer 1 for servo*/
// // // Timer_1_INIT_With_OCV(FAST,OCV_1_Clear,OCV_1_Clear,1000,1000);  // Init in servo.c   

// // /**/




//     while (1)
//     {
//         // enter username 
//         // check usernames prev
//         // enter pass
//         // check
//         // change variable if admin
//         // 
//         //Recieveeddata_onitor(KeyPad_GetRead());
//         //Recieveeddata_onitor(UART_RX());

//         if((KeyPad_GetRead() == '0') || (UART_RX() == '0'))
//         {
//             Alarm_TOG();
//             LCD_GoTo(0,0);
//             LCD_WriteString("Alarm Toggled");
//         }
//         if((KeyPad_GetRead() == '1') || (UART_RX() == '1'))
//         {
//             LED_SetLED(LED0);
//             LED_SetLED(LED1);
//             LCD_GoTo(0,0);
//             LCD_WriteString("LEDs ON");
//         }
//         if((KeyPad_GetRead() == '2') || (UART_RX() == '2'))
//         {
//             LED_ClearLED(LED0);
//             LED_ClearLED(LED1);
//             LCD_GoTo(0,0);
//             LCD_WriteString("LEDs OFF");
//         }
//         if((KeyPad_GetRead() == '4') || (UART_RX() == '3'))
//         {
//             // if admin ==>
//             // if not admin lcd print no access
//             Servo_Open_Door();
//             LCD_GoTo(0,0);
//             LCD_WriteString("Door Opens");
//         }
//         if((KeyPad_GetRead() == '4') || (UART_RX() == '4'))
//         {
//             Servo_Close_Door();
//             LCD_GoTo(0,0);
//             LCD_WriteString("Door Closes");
//         }
//         if((KeyPad_GetRead() == '5') || (UART_RX() == '5'))
//         {
//             /*Checking temp*/
//             Air_conditionar_check();
//             LCD_GoTo(0,0);
//             LCD_WriteString(Air_conditionar_check());
//         }
//         if((KeyPad_GetRead() == '6') || (UART_RX() == '6'))
//         {
//             ending_sequance();
//             LCD_GoTo(0,0);
//             LCD_WriteString("Air Conditionar Off");
//         }
//         if(KeyPad_GetRead() == '7')
//         {
            
//         }
//         if(KeyPad_GetRead() == '8')
//         {
            
//         }
//         if(KeyPad_GetRead() == '9')
//         {
            
//         }
//         if(KeyPad_GetRead() == '1')
//         {
            
//         }
//         if(KeyPad_GetRead() == '1')
//         {
            
//         }
//         if(KeyPad_GetRead() == '1')
//         {
            
//         }
//         if(KeyPad_GetRead() == '1')
//         {
            
//         }
//         if(KeyPad_GetRead() == '1')
//         {
            
//         }
//         if(KeyPad_GetRead() == '1')
//         {
            
//         }
//     }
// }

typedef struct user
{
    u8   username[20];
    u8   password[20];
    bool isAdmin;
}user;



int main()
{

    LCD_Init();
    KeyPad_Init();
    user User_list[5] ={0};

    for (int i = 0; i < 5; i++)
    {
        if ( (!strcmp(User_list[i].username , "")) )
        {
            
            User_list[i].username[0] = KeyPad_GetRead();
            User_list[i].password[0] = KeyPad_GetRead();
            break;
        }
        else
        {

        }
    }
    
}