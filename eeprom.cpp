#include <Arduino.h>
#include <EEPROM.h>

#include "eeprom.h"


int eeprom_get_size(void)
{
  return EEPROM.length();
}

void eeprom_clear_all(void)
{
  for(int i = 0; i < EEPROM.length(); i++)
  {
    EEPROM.write(i, 0);
  }
}

void eeprom_write(int address, char value1)
{
  EEPROM.write(address, value1);
}

int eeprom_read(int address)
{
  return EEPROM.read(address);
}