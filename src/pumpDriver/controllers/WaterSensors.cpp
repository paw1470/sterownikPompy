#include "WaterSensors.h"
#include "Config.h"

void WaterSensors::initSensors(){
    tankSensor.init(PIN_TANK_WATER_LEVEL_LOW, 
                    PIN_TANK_WATER_LEVEL_HIGH,
                    TANK_USE_INTERNAL_PULLUP);
    wellSensor.init(PIN_WELL_WATER_LEVEL_LOW, 
                    PIN_WELL_WATER_LEVEL_HIGH,
                    WELL_USE_INTERNAL_PULLUP);
}

WaterLevelEnum WaterSensors::getTankStatus(){
    return tankSensor.getWaterLevel();
}

WaterLevelEnum WaterSensors::getWellStatus(){
    return wellSensor.getWaterLevel();
}
