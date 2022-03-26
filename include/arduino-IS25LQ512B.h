#ifndef __ARDUINO_IS25LQ512B_H__
#define __ARDUINO_IS25LQ512B_H__
#include <Arduino.h>
#include <SPI.h>

class flash
{
private:
    /* data */
    uint8_t LEPIN;

    void chipErase();
    void sectorErase();
    void pageafy();
    void transaction();
    uint8_t getStatus();
    uint32_t getChipInfo();
    size_t spi_txn(void *buff, size_t len);

    const uint8_t CMD_PP    = 0x02;     //Page Program Data Bytes
    const uint8_t CMD_CER   = 0xC7;     //Chip Erase
    const uint8_t CMD_WREN  = 0xC7;     //write enable
    const uint8_t CMD_RDSR  = 0x05;     //Read Status Reg
    const uint8_t CMD_JEDEC = 0x9F;     //read mfctr and prod ID
    const uint8_t CMD_READ  = 0x03;     //read data bytes normally
    const uint8_t CMD_SERER = 0xD7;     //Sector Erase
    const uint8_t CMD_RSE   = 0x99;     //Reset

public:
    uint32_t begin(uint8_t LEPIN);

    //note that addr range for this chip is 0x00_00_00 - 0x00_FF_FF
    
    int save(void *buff, size_t size);
    int save(void *buff, size_t size, uint32_t address); 
    int load(void *buff, size_t size);
    int load(void *buff, size_t size, uint32_t address); 
};



#endif