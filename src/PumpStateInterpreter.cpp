#include "PumpStateInterpreter.h"

PumpStateEnum PumpStateInterpreter::getNewPumpState(WaterLevelEnum wellWaterLevel, WaterLevelEnum tankWaterLevel, PumpStateEnum lastPumpState){
    if(wellWaterLevel == WATER_ERROR || tankWaterLevel == WATER_ERROR){     //error
        return PUMP_ERROR;
    }
    if(lastPumpState == PUMP_ON && (wellWaterLevel == WATER_LOW_LEVEL || tankWaterLevel == WATER_HIGH_LEVEL)){  //auto Off
        return PUMP_OFF;
    }
    if(lastPumpState == PUMP_OFF && (wellWaterLevel == WATER_HIGH_LEVEL || tankWaterLevel == WATER_LOW_LEVEL)){  //auto On
        return PUMP_ON;
    }
    return lastPumpState;
}
