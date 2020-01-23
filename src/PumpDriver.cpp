#include "PumpDriver.h"
#include "Config.h"

void PumpDriver::init(){
    pumpStatus = PUMP_OFF;
    lastTankStatus = WATER_ERROR;
    lastWellStatus = WATER_ERROR;

    lastTimeAutoChange = 0;
    lastTimeBlink = 0;
    lastTimeButtonPress = 0;
    lastTimeWaterLevelCheck = 0;

    outputDevices.initDevices();
    waterSensors.initSensors();
    ledController.init();
    buttons.init();
}

void PumpDriver::start(){
    bool stateUpdated = false;
    while(true){
        if(checkButtons()){
            stateUpdated = true;
        }
        if(isWaterLevelChanged()){
            stateUpdated = true;
        }
        if(stateUpdated){
            updateLedInfo();
            stateUpdated = false;
        }
    }
}

void PumpDriver::changeOutputDevicesState(){
    switch (pumpStatus){
    case PUMP_ERROR:
        outputDevices.pumpTurnOFF();
        break;
    case PUMP_OFF:
        outputDevices.pumpTurnOFF();
        break;
    case PUMP_FORCE_OFF:
        outputDevices.pumpTurnOFF();
        break;
    case PUMP_ON:
        outputDevices.pumpTurnON();
        break;
    case PUMP_FORCE_ON:
        outputDevices.pumpTurnON();
        break;
    default:
        break;
    }
}



void PumpDriver::updateLedInfo(){
    ledController.setTankInfo(waterSensors.getTankStatus());
    ledController.setWellInfo(waterSensors.getWellStatus());
    ledController.setPumpInfo(pumpStatus);
    ledController.update();
}

bool PumpDriver::isWaterLevelChanged(){
    bool isChanged = false;
    if(isWellLevelChanged()){
        lastWellStatus = waterSensors.getWellStatus();
        isChanged = true;
    }
    if(isTankLevelChanged()){
        lastTankStatus = waterSensors.getTankStatus();
        isChanged = true;
    }
    return isChanged;
}

bool PumpDriver::isWellLevelChanged(){
    return waterSensors.getWellStatus() != lastWellStatus;
}

bool PumpDriver::isTankLevelChanged(){
    return waterSensors.getTankStatus() != lastTankStatus;
}

bool PumpDriver::checkButtons(){
    if(!isTimeForButtonCheck()){
        return false;
    }
    if(buttons.isMoreThanOneButtonPressed()){
        return changeStateButtonError();
    } else if(buttons.isButtonStartPressed()){
        return changeStateButtonStart();
    } else if(buttons.isButtonStopPressed()){
        return changeStateButtonStop();
    }
    return false;
}

bool PumpDriver::changeStateButtonStart(){
    switch (pumpStatus) {
    case PUMP_FORCE_OFF:
        pumpStatus = PUMP_OFF;
        break;
    case PUMP_OFF:
        pumpStatus = PUMP_ON;
        break;
    case PUMP_ON:
        pumpStatus = PUMP_FORCE_ON;
        break;
    case PUMP_FORCE_ON:
        return false;
        break;
    case PUMP_ERROR:
        pumpStatus = PUMP_OFF;
        break;
    default:
        break;
        return false;
    }
    return true;
}

bool PumpDriver::changeStateButtonStop(){
    switch (pumpStatus) {
    case PUMP_FORCE_OFF:
        return false;
        break;
    case PUMP_OFF:
        pumpStatus = PUMP_FORCE_OFF;
        break;
    case PUMP_ON:
        pumpStatus = PUMP_OFF;
        break;
    case PUMP_FORCE_ON:
        pumpStatus = PUMP_OFF;
        break;
    case PUMP_ERROR:
        pumpStatus = PUMP_OFF;
        break;
    default:
        return false;
        break;
    }
    return true;
}

bool PumpDriver::changeStateButtonError(){
    if(pumpStatus == PUMP_ERROR){
        return false;
    } else{
        return true;
    }
}

bool PumpDriver::isTimeForButtonCheck(){
    if(getTimeSince(lastTimeButtonPress) >= WAIT_TIME_BETWEN_BUTTON){
        lastTimeButtonPress = millis();
        return true;
    }
    return false;
}

bool PumpDriver::isTimeForWaterLevelCheck(){
    if(getTimeSince(lastTimeWaterLevelCheck) >= WAIT_TIME_WATER_LEVEL_CHECK){
        lastTimeWaterLevelCheck = millis();
        return true;
    }
    return false;
}

bool PumpDriver::isTimeForAutoChangeState(){
    if((pumpStatus == PUMP_OFF) || (pumpStatus == PUMP_ON)){
        if(getTimeSince(lastTimeAutoChange) >= WAIT_TIME_AUTO_CHANGE){
            return true;
        }
    }
    return false;
}

bool PumpDriver::isTimeForBlinkLed(){
     if((pumpStatus == PUMP_FORCE_OFF) || (pumpStatus == PUMP_FORCE_ON)){
        if(getTimeSince(lastTimeBlink) >= WAIT_TIME_BLINK_LED){
            return true;
        }
    }
    return false;
}

uint16_t PumpDriver::getTimeSince(unsigned long time){
    return (uint16_t)(millis() - time);
}
