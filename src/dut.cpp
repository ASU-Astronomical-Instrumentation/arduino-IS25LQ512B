#include "Arduino.h"
#include "arduino-IS25LQ512B.h"

flash *f;

void setup(){
    Serial.begin(9600);
    f = new flash();
    int i = f->begin(10);
    Serial.println(i);

}

void loop(){
    Serial.println("Hello WOrld");
}