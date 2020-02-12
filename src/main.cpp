#include "pumpDriver/PumpDriver.h"

PumpDriver pumpDriver;

void setup(){
    pumpDriver.init();
    
}

void loop(){
    pumpDriver.start();
}