#include "LedController.h"
#include "Config.h"
#include "ConfigLedShiftRegister.h"

void LedController::init(){
    initShiftRegister();
    this->blink = true;
}

void LedController::setWellInfo(WaterLevelEnum wellWaterLevel){
    byte ledState = stateLedShiftRegister.getDataByte();
    ledState = clearWellInfo(ledState);
    switch (wellWaterLevel){
    case WATER_LEVEL_EMPTY:
        ledState = ledState | LED_WELL_RED;
        break;
    case WATER_LEVEL_MEDIUM:
        ledState = ledState | LED_WELL_BLUE;
        break;
    case WATER_LEVEL_FULL:
        ledState = ledState | LED_WELL_GREEN;
        break;
    default:
        ledState = ledState | LED_WELL_WHITE;
        break;
    }
    stateLedShiftRegister.setDataByte(ledState);
}

void LedController::setTankInfo(WaterLevelEnum tankWaterLevel){
    byte ledState = stateLedShiftRegister.getDataByte();
    ledState = clearTankInfo(ledState);
    switch (tankWaterLevel){
    case WATER_LEVEL_EMPTY:
        ledState = ledState | LED_TANK_GREEN;
        break;
    case WATER_LEVEL_MEDIUM:
        ledState = ledState | LED_TANK_BLUE;
        break;
    case WATER_LEVEL_FULL:
        ledState = ledState | LED_TANK_RED;
        break;
    default:
        ledState = ledState | LED_TANK_WHITE;
        break;
    }
    stateLedShiftRegister.setDataByte(ledState);
}

void LedController::setPumpInfo(PumpStateEnum pumpState){
    byte ledState = stateLedShiftRegister.getDataByte();
    ledState = clearPumpInfo(ledState);
    switch (pumpState){
    case PUMP_OFF:
        ledState = ledState | LED_PUMP_RED;
        break;
    case PUMP_FORCE_OFF:
        ledState = ledState | LED_PUMP_RED;
        break;
    case PUMP_ON:
        ledState = ledState | LED_PUMP_GREEN;
        break;
    case PUMP_FORCE_ON:
        ledState = ledState | LED_PUMP_GREEN;
        break;
    default:
        ledState = ledState | LED_PUMP_YELLOW;
        break;
    }
    stateLedShiftRegister.setDataByte(ledState);
}

void LedController::update(){
    stateLedShiftRegister.updateRegister();
}

void LedController::initShiftRegister(){
    stateLedShiftRegister.init(PIN_SHIFT_REGISTER_DATA, PIN_SHIFT_REGISTER_LATCH, PIN_SHIFT_REGISTER_CLOCK);
}

void LedController::blinkPump(){
    if(blink){
        this->blink = false;
        stateLedShiftRegister.setDataByte(
            clearPumpInfo(
                stateLedShiftRegister.getDataByte()));
    } else{
        this->blink = true;
    }
    update();
}

byte LedController::clearPumpInfo(byte data){
    return data & ~(LED_PUMP_ALL);
}

byte LedController::clearWellInfo(byte data){
    return data & ~(LED_WELL_ALL);
}

byte LedController::clearTankInfo(byte data){
    return data & ~(LED_TANK_ALL);
}

void LedController::test(){
    stateLedShiftRegister.testShift();
    colorTest();
}

void LedController::colorTest(){
    byte tempLedState = 0;
    tempLedState = LED_WELL_RED | LED_TANK_RED | LED_PUMP_RED;
    stateLedShiftRegister.setDataByte(tempLedState);
    update();

    delay(400);

    tempLedState = 0;
    tempLedState = LED_WELL_GREEN | LED_TANK_GREEN | LED_PUMP_GREEN;
    stateLedShiftRegister.setDataByte(tempLedState);
    update();

    delay(400);

    tempLedState = 0;
    tempLedState = LED_WELL_BLUE | LED_TANK_BLUE;
    stateLedShiftRegister.setDataByte(tempLedState);
    update();

    delay(400);

    tempLedState = 0;
    tempLedState = LED_WELL_YELLOW | LED_TANK_YELLOW | LED_PUMP_YELLOW;
    stateLedShiftRegister.setDataByte(tempLedState);
    update();

    delay(400);

    tempLedState = 0;
    tempLedState = LED_WELL_CYAN | LED_TANK_CYAN;
    stateLedShiftRegister.setDataByte(tempLedState);
    update();

    delay(400);

    tempLedState = 0;
    tempLedState = LED_WELL_MAGENTA | LED_TANK_MAGENTA;
    stateLedShiftRegister.setDataByte(tempLedState);
    update();

    delay(400);

    tempLedState = 0;
    tempLedState = LED_WELL_WHITE | LED_TANK_WHITE;
    stateLedShiftRegister.setDataByte(tempLedState);
    update();

    delay(400);
}