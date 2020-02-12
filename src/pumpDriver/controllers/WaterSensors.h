#ifndef WATERSENSORS_H
#define WATERSENSORS_H
#include <inttypes.h>
#include "WaterLevelEnum.h"
#include "WaterLevelSensor2PinPB.h"

class WaterSensors{
    public:
        WaterLevelEnum getTankStatus();
        WaterLevelEnum getWellStatus();
        void initSensors();
    
    private:
        WaterLevelSensor2PinPB tankSensor;
        WaterLevelSensor2PinPB wellSensor;
        
        void initTankSensor();
        void initWellSensor();
};

#endif