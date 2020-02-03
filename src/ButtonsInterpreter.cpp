#include "ButtonsInterpreter.h"

PumpStateEnum ButtonsInterpreter::getStateWithStartButton(PumpStateEnum oldPumpState){
    switch (oldPumpState) {
    case PUMP_FORCE_OFF:
        return PUMP_OFF;
        break;
    case PUMP_OFF:
        return PUMP_ON;
        break;
    case PUMP_ON:
        return PUMP_FORCE_ON;
        break;
    case PUMP_FORCE_ON:
        return PUMP_FORCE_ON;
        break;
    case PUMP_ERROR:
        return PUMP_OFF;
        break;
    default:
        return PUMP_ERROR;
        break;
    }
}

PumpStateEnum ButtonsInterpreter::getStateWithStopButton(PumpStateEnum oldPumpState){
    switch (oldPumpState) {
    case PUMP_FORCE_OFF:
        return PUMP_FORCE_OFF;
        break;
    case PUMP_OFF:
        return PUMP_FORCE_OFF;
        break;
    case PUMP_ON:
        return PUMP_OFF;
        break;
    case PUMP_FORCE_ON:
        return PUMP_OFF;
        break;
    case PUMP_ERROR:
        return PUMP_OFF;
        break;
    default:
        return PUMP_ERROR;
        break;
    }
}

PumpStateEnum ButtonsInterpreter::getStateWithAllButtons(PumpStateEnum oldPumpState){
    return PUMP_ERROR;
}