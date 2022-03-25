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

public:
    /**
     * @brief 
     * 
     */
    flash(/* args */);
    ~flash();
    int begin(uint8_t LEPIN);

    //note that addr range for this chip is 0x00_00_00 - 0x00_FF_FF
    
    int save(void *buff, size_t size);
    int save(void *buff, size_t size, uint32_t address); 
    int load(void *buff, size_t size);
    int load(void *buff, size_t size, uint32_t address); 
};

flash::flash(/* args */)
{
}

flash::~flash()
{
}


#endif