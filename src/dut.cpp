#include "Arduino.h"
#include "arduino-IS25LQ512B.h"

flash *f;

void setup(){
    Serial.begin(9600);
    SPI.begin();
    f = new flash();
}

void loop(){
    while (Serial.available() == 0);
    Serial.read();
    
    Serial.println("Hello WOrld");
    uint32_t i = f->begin(10);

    char buff[48];
    sprintf(buff, "resp=0x%08x\n",i); 
    Serial.println(buff);
}