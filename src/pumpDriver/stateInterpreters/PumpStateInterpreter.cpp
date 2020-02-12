#include "PumpStateInterpreter.h"

PumpStateEnum PumpStateInterpreter::getNewPumpState(WaterLevelEnum wellWaterLevel, WaterLevelEnum tankWaterLevel, PumpStateEnum lastPumpState){
    if(wellWaterLevel == WATER_LEVEL_ERROR || tankWaterLevel == WATER_LEVEL_ERROR){     //error
        return PUMP_ERROR;
    }
    if(lastPumpState == PUMP_ON && (wellWaterLevel == WATER_LEVEL_EMPTY || tankWaterLevel == WATER_LEVEL_FULL)){  //auto Off
        return PUMP_OFF;
    }
    if(lastPumpState == PUMP_OFF && (wellWaterLevel == WATER_LEVEL_FULL && tankWaterLevel == WATER_LEVEL_EMPTY)){  //auto On
        return PUMP_ON;
    }
    return lastPumpState;
}
