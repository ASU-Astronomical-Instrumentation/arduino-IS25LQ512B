#include "arduino-IS25LQ512B.h"

/** Public Methods **/
uint32_t flash::begin(uint8_t LEPIN){
    this->LEPIN = LEPIN;
    pinMode(this->LEPIN, OUTPUT);
    digitalWrite(this->LEPIN, HIGH);
    return this->getChipInfo();
}
int flash::save(void *buff, size_t size){
    return 0;
}
int flash::save(void *buff, size_t size, uint32_t address){
    return 0;
}
int flash::load(void *buff, size_t size){
    return 0;
}
int flash::load(void *buff, size_t size, uint32_t address){
    return 0;
}

/** Private Methods **/

void flash::chipErase(){

}
void flash::sectorErase(){

}
void flash::pageafy(){

}
void flash::transaction(){

}
uint8_t flash::getStatus(){
    return 1;
}
uint32_t flash::getChipInfo(){
    uint32_t info = 0;
    uint8_t b[] = {0x9F, 0x00, 0x00, 0x00};
    this->spi_txn(b, 4);
    info = 0x000000 | b[1] << 16 | b[2] << 8 | b[3];
    return info;
}

size_t flash::spi_txn(void *buff, size_t len){
    digitalWrite(this->LEPIN, LOW);
    SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE0));
    SPI.transfer(buff, len);
    SPI.endTransaction();
    digitalWrite(this->LEPIN, HIGH);
    return 0;
}