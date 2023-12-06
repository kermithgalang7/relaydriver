#ifndef __EEPROM_H__
#define __EEPROM_H__


int eeprom_get_size(void);
void eeprom_clear_all(void);
void eeprom_write(int address, char value);
int eeprom_read(int address);


#endif //__EEPROM_H__