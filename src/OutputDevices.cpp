#include "OutputDevices.h"
#include "Config.h"

void OutputDevices::initDevices(){
    initPump();
}

bool OutputDevices::isPumpOn(){
    return pump.isStateOn();
}

void OutputDevices::pumpTurnON(){
    if(!pump.isStateOn()){
            pump.turnON();
    }
}

void OutputDevices::pumpTurnOFF(){
    if(pump.isStateOn()){
        pump.turnOFF();
    }
}

void OutputDevices::initPump(){
    pump.init(PUMP_N_O_CONNECTED, PUMP_N_O_CONNECTED, PUMP_INVERTED_OUTPUT);
}