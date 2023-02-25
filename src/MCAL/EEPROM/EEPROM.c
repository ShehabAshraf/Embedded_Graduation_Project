#include "EEPROM.h"


/*To read the data from the EEPROM given the Address*/

 char EEPROM_read(short address){
	//Setup Address Register
	EEARL = (char)address; //LOW Address
	EEARH = (char)(address>>8); //High Address
	
	// Start Reading and Return Data
	SET_BIT(EECR,EERE);
}

/* write data in the EEPROM given the address and the data.*/
	
void EEPROM_write(short address,  char data)
{
	unsigned char INT_EN=0;
		
	// Setup Address Register
	EEARL = (char)address;
	EEARH = (char)(address>>8);
	
	// Put Data in Data Register
	EEDR = data;
	
	// Disable Interrupts 
	if((GET_BIT(SREG,7)==1)) //SREG:status register
	{
		INT_EN = 1;
		CLR_BIT(SREG,7);
	}
	
	// Start Writing
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
	while((GET_BIT(EECR,EEWE)==1));
	
	// Back
	if (INT_EN==1)
	{
		SET_BIT(SREG,7);
	}
}