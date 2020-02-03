#include "PumpDriver.h"
#include "Config.h"

void PumpDriver::init(){
    lastTimeChangePumpState = 0L;
    lastTimeBlink = 0L;
    lastTimeButtonPress = 0L;
    lastTimeWaterLevelCheck = 0L;

    pumpsController.initDevices();
    waterSensors.initSensors();
    ledController.init();
    updatePump(PUMP_OFF);
    buttons.init();    
    testOnStart();

}    

void PumpDriver::start(){
    timeForWaterLevelChangeInfo();
    timeForButtonCheck();
    timeForAutoChangePumpState();
    timeForBlinkLed();
}

void PumpDriver::updateLedInfo(){
    ledController.setTankInfo(waterSensors.getTankStatus());
    ledController.setWellInfo(waterSensors.getWellStatus());
    ledController.setPumpInfo(pumpStatus);
    ledController.update();
}

void PumpDriver::checkButtons(){
    PumpStateEnum tempPumpState = pumpStatus;
    if(buttons.isMoreThanOneButtonPressed()){
        tempPumpState = buttonsInterpreter.getStateWithAllButtons(tempPumpState);
    } else if(buttons.isButtonStartPressed()){
        tempPumpState = buttonsInterpreter.getStateWithStartButton(tempPumpState);
    } else if(buttons.isButtonStopPressed()){
        tempPumpState = buttonsInterpreter.getStateWithStopButton(tempPumpState);
    }
    if(tempPumpState != pumpStatus){
        updatePump(tempPumpState);
    }
}

void PumpDriver::timeForButtonCheck(){
    if(getTimeSince(lastTimeButtonPress) >= WAIT_TIME_BETWEN_BUTTON){
        lastTimeButtonPress = millis();
        checkButtons();
    }
}

void PumpDriver::timeForWaterLevelChangeInfo(){
    if(getTimeSince(lastTimeWaterLevelCheck) >= WAIT_TIME_WATER_LEVEL_CHECK){
        lastTimeWaterLevelCheck = millis();
        ledController.setTankInfo(waterSensors.getTankStatus());
        ledController.setWellInfo(waterSensors.getWellStatus());
        ledController.update();
    }
}

void PumpDriver::timeForAutoChangePumpState(){
    if((pumpStatus == PUMP_OFF) || (pumpStatus == PUMP_ON)){
        if(getTimeSince(lastTimeChangePumpState) >= WAIT_TIME_AUTO_CHANGE){
            PumpStateEnum tempPumpState = pumpStatus;
            tempPumpState = pumpStateInterpreter.getNewPumpState(waterSensors.getWellStatus(), waterSensors.getTankStatus(), tempPumpState);
            if(pumpStatus != tempPumpState){
                updatePump(tempPumpState);
            }
        }
    }
}

void PumpDriver::timeForBlinkLed(){
     if((pumpStatus == PUMP_FORCE_OFF) || (pumpStatus == PUMP_FORCE_ON)){
        if(getTimeSince(lastTimeBlink) >= WAIT_TIME_BLINK_LED){
            lastTimeBlink = millis();
            ledController.setPumpInfo(pumpStatus);
            ledController.blinkPump();
        }
    }
}

void PumpDriver::updatePump(PumpStateEnum newPumpState){
    lastTimeChangePumpState = millis();
    pumpStatus = newPumpState;
    ledController.setPumpInfo(pumpStatus);
    ledController.update();
    pumpsController.setState(pumpStatus);
}

uint16_t PumpDriver::getTimeSince(unsigned long time){
    return (uint16_t)(millis() - time);
}

void PumpDriver::testOnStart(){
    updatePump(PUMP_ON);
    delay(1000);
    updatePump(PUMP_OFF);
    ledController.test();
    updatePump(PUMP_OFF);
}