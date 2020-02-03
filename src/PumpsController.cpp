#include "PumpsController.h"
#include "Config.h"

void PumpsController::initDevices(){
    initPump();
}

bool PumpsController::isPumpOn(){
    return pump.isStateOn();
}

void PumpsController::pumpTurnON(){
    if(!pump.isStateOn()){
            pump.turnON();
    }
}

void PumpsController::pumpTurnOFF(){
    if(pump.isStateOn()){
        pump.turnOFF();
    }
}

void PumpsController::initPump(){
    pump.init(PUMP_N_O_CONNECTED, PUMP_N_O_CONNECTED, PUMP_INVERTED_OUTPUT);
}

void PumpsController::setState(PumpStateEnum state){
    switch (state)    {
    case PUMP_ERROR:
        pumpTurnOFF();
        break;
    case PUMP_OFF:
        pumpTurnOFF();
        break;
    case PUMP_FORCE_OFF:
        pumpTurnOFF();
        break;
    case PUMP_ON:
        pumpTurnON();
        break;
    case PUMP_FORCE_ON:
        pumpTurnON();
        break;
    default:
        break;
    }
}