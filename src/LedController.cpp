#include "LedController.h"
#include "Config.h"
#include "ConfigLedShiftRegister.h"

void LedController::init(){
    initShiftRegister();
    blink = true;
}

void LedController::setWellInfo(WaterLevelEnum wellWaterLevel){
    byte ledState = stateLedShiftRegister.getShiftData();
    ledState = ledState & LED_WELL_OFF;
    switch (wellWaterLevel){
    case WATER_LOW_LEVEL:
        ledState = ledState | LED_WELL_RED;
        break;
    case WATER_MEDIUM_LEVEL:
        ledState = ledState | LED_WELL_BLUE;
        break;
    case WATER_HIGH_LEVEL:
        ledState = ledState | LED_WELL_GREEN;
        break;
    default:
        ledState = ledState | LED_WELL_WHITE;
        break;
    }
    stateLedShiftRegister.setDataByte(ledState);
}

void LedController::setTankInfo(WaterLevelEnum tankWaterLevel){
    byte ledState = stateLedShiftRegister.getShiftData();
    ledState = ledState & LED_TANK_OFF;
    switch (tankWaterLevel){
    case WATER_LOW_LEVEL:
        ledState = ledState | LED_TANK_GREEN;
        break;
    case WATER_MEDIUM_LEVEL:
        ledState = ledState | LED_WELL_BLUE;
        break;
    case WATER_HIGH_LEVEL:
        ledState = ledState | LED_WELL_RED;
        break;
    default:
        ledState = ledState | LED_WELL_WHITE;
        break;
    }
    stateLedShiftRegister.setDataByte(ledState);
}

void LedController::setPumpInfo(PumpStateEnum pumpState){
    byte ledState = stateLedShiftRegister.getShiftData();
    ledState = ledState & LED_PUMP_OFF;
    switch (pumpState){
    case PUMP_OFF:
        ledState = ledState | LED_PUMP_RED;
        break;
    case PUMP_FORCE_OFF:
        if(blink){
            ledState = ledState | LED_PUMP_RED;
            blink = !blink;
        }        
        break;
    case PUMP_ON:
        ledState = ledState | LED_PUMP_GREEN;
        break;
    case PUMP_FORCE_ON:
        if(blink){
            ledState = ledState | LED_PUMP_GREEN;
            blink = !blink;
        }
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