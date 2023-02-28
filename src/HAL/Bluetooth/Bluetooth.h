#ifndef BLUETOOTH_H_INCLUDED
#define BLUETOOTH_H_INCLUDED
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/USART/USART.h"
#include "../../UTILS/STD_Types.h"
#define MUXpin  DIO_B6
#define MUXen  DIO_B6
u8* ptr_pass_name=NULL; // pointer to array for password and name
u8 Rece_Old=0 ; //old data recieved
u8 C_arr=0; // array counter
bool Pas_name=1;    // boolian variable for checking if we are recieving name and password
//void (*Blueptr) (void) =NULLptr;
//void Blue_SetCallBack( void(*ptrFn)(void) );
void toggleuart_blue(); // toggle between tipical uart and bluetooth
void En_Dis_Blue(); // disable and enable rx and tx multiplixer and 
u8 Redata_bu(); // get data from udr
void Recieveeddata_onitor(u8 RECEIDATA);// according to recieved data the system will take action
void Bl_Set_Pointer(u8*bstran);//pass pointer to array of password and name
#endif