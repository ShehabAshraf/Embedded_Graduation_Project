#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/USART/USART.h"
#include "../../UTILS/STD_Types.h"
#include "../Kit_config.h"
#include "Bluetooth.h"

void toggleuart_blue()
{ 
    DIO_PinMode(MUXpin,OUTPUT);
    DIO_DigitalTogglePin(MUXpin);
}

void En_Dis_Blue()
{ 
    DIO_PinMode(MUXen,OUTPUT);
    DIO_DigitalTogglePin(MUXen);
}
u8 Redata_bu()
{
u8*ptr_fa=UDR;
return(*ptr_fa);
}
void Recieveeddata_onitor(u8 RECEIDATA)
{ 
 if(RECEIDATA !=Rece_Old) {
    
    
              if(Pas_name=1){
    
       switch (RECEIDATA){
    case '1':
    break;
    case '2':
    break;
    case '3':
    break;
    case '4':
    break;
    case '5':
    break;
    case '6':
    break;
    case '7':
    break;
    case '8':
    break;
    case '9':
    break;
    case '0':
    break;

    
    case '#':
    Pas_name=0;
    UART_TX('p');
    UART_TX('l');
    UART_TX('e');
    UART_TX('a');
    UART_TX('s');
    UART_TX('e');
    UART_TX(' ');
    UART_TX('e');
    UART_TX('n');
    UART_TX('t');
    UART_TX('e');
    UART_TX('r');
    UART_TX('d');
    UART_TX('a');
    UART_TX('t');
    UART_TX('a');
    UART_TX(' ');
    UART_TX('\n');
    Rece_Old= RECEIDATA;
    return;

default:
 //printf("error, no operation registered")
 }}///////////////////else the data will be stored
else if(RECEIDATA =='#' && Pas_name == 0){ Pas_name=1; ptr_pass_name[C_arr]='#';C_arr=0;}//toggle pass name to go back to normal mode and send indication to show that array is complete
if(ptr_pass_name!=NULL && RECEIDATA!=0){
 ptr_pass_name[C_arr]=RECEIDATA;//save data in pt
    UART_TX(RECEIDATA);//echo
 C_arr++;}//increment
    Rece_Old= RECEIDATA;}
}
void Bl_Set_Pointer(u8*bstran){ptr_pass_name=bstran;}//recieve array pointer and set it

























































































// void Blue_SetCallBack( void(*ptrFn)(void) ){
// 	if(ptrFn != NULLptr){	Blueptr = ptrFn;		}
// }
// void INT2_vect			(void){
// 	CLEAR_BIT(GICR, INT2);
// 	Blueptr();
// 	SET_BIT(GICR, INT2);
// }	


//////////////////////////////////////////////////////////////////////////////////////////////////////////////






// void interrupt ISR (void)
// {
//   if (RCIF == 1)
//   {
//     Data_Buffer = RCREG;  // Read The Data received from Buffer
//     clearbit(RCIF);             // Clear The Flag
//   }
// }



// unsigned char UART_RxChar()
// {
// 	while ((UCSRA & (1 << RXC)) == 0);/* Wait till data is received */
// 	return(UDR);			/* Return the byte*/
// }

// void UART_TxChar(char ch)
// {
// 	while (! (UCSRA & (1<<UDRE)));	/* Wait for empty transmit buffer*/
// 	UDR = ch ;
// }

// void UART_SendString(char *str)
// {
// 	unsigned char j=0;
	
// 	while (str[j]!=0)		/* Send string till null */
// 	{
// 		UART_TxChar(str[j]);	
// 		j++;
// 	}
// }

// int main()
// {
// 	char c;
// 	UART_init(9600);
	
// 	UART_SendString("\n\t Echo Test ");	
// 	while(1)
// 	{
// 		c=UART_RxChar();
// 		UART_TxChar(c);
// 	}	
// }