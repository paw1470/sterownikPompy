#ifndef PUMPSTATEINTERPRETER_H
#define PUMPSTATEINTERPRETER_H
#include "pumpDriver/PumpStateEnum.h"
#include "WaterLevelEnum.h"

class PumpStateInterpreter{
private:
    /* data */
public:
    PumpStateEnum getNewPumpState(WaterLevelEnum wellWaterLevel, WaterLevelEnum tankWaterLevel, PumpStateEnum lastPumpState);
};

#endif
