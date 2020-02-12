#ifndef WATERSENSORS_H
#define WATERSENSORS_H
#include <inttypes.h>
#include "hardware/waterSensor/WaterLevelEnum.h"
#include "hardware/waterSensor/WaterLevelSensor.h"

class WaterSensors{
    public:
        WaterLevelEnum getTankStatus();
        WaterLevelEnum getWellStatus();
        void initSensors();
    
    private:
        WaterLevelSensor tankSensor;
        WaterLevelSensor wellSensor;
        
        void initTankSensor();
        void initWellSensor();
};

#endif