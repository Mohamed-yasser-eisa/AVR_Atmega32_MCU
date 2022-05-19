
#include "internalEEPROM.h"

void EEPROM_write(uint16 address, uint8 data)
{
	/*wait until (EEWE) bit in (EECR), becomes ZERO, to start new write operation*/
	while (READ_BIT(EECR,EEWE))
	{
		//do nothing
	}
	/*wait until (SPMEN) bit in (SPMCR) becomes zero*/
	while (READ_BIT(SPMCR,SPMEN))
	{
		//do nothing
	}
	/*load address in (EEARL, EEARH)*/
	EEARL = (uint8) address;
	EEARH = (uint8) (address>>8);
	/*load data to (EEDR)*/
	EEDR = data;
	/*write logic '1' to (EEMWE) bit in (EECR)*/
	SET_BIT(EECR,EEMWE);
	/*start EEPROM write operation, by setting the (EEWE) bit in (EECR)*/
	SET_BIT(EECR,EEWE);
	/*wait for 4 clock cycles, until write operation is done*/
	while (READ_BIT(EECR,EEWE))
	{
		//wait for 4 clock cycles.
	}
}


uint8 EEPROM_read(uint16 address)
{
	uint8 data = 0;
	/*first make sure that any write operation is finished first*/
	while (READ_BIT(EECR,EEWE))
	{
		//do nothing
	}
	/*load address in (EEARL, EEARH)*/
	EEARL = (uint8) address;
	EEARH = (uint8) (address>>8);
	/*start EEPROM read operation by setting (EERE) bit in (EECR)*/
	SET_BIT(EECR,EERE);
	/*read data from (EEDR) and return it*/
	data = EEDR;
	/*return data*/
	return data;
}