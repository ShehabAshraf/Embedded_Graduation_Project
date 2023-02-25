#include "../DIO/DIO.h"
#include "../../Memory_Map/MEM_MAP.h"
#include "../../UTILS/BitMath.h"
#include "../../UTILS/STD_Types.h"

#ifndef EEPROM_H
#define EEPROM_H

char EEPROM_read(short address);
void EEPROM_write(short address,  char data);

#endif
