#ifndef WATERLEVELSENSOR_H
#define WATERLEVELSENSOR_H
#include <inttypes.h>
#include "WaterLevelEnum.h"

//Internal pullup resistor in arduino 10K. Set bool FALSE if you use external betwen VCC and pins. 

class WaterLevelSensor{
    public:
        WaterLevelSensor();
        void init(uint8_t lowWaterLevelPin, uint8_t highWaterLevelPin, bool useInternalPullUpRes = true);
        bool isWaterLevelChanged();             //update and return bool
        WaterLevelEnum getWaterLevel();         //update and return
        WaterLevelEnum getLastWaterLevel();     //only return 


    private:
        WaterLevelEnum  waterLevel;
        uint8_t lowWaterLevelPin;
        uint8_t highWaterLevelPin;

        bool isWaterSensorHigh();
        bool isWaterSensorLow();
        
        void updateWaterLevel();

        bool isWaterLevelLow(bool waterSensorLow, bool waterSensorHigh);
        bool isWaterLevelMedium(bool waterSensorLow, bool waterSensorHigh);
        bool isWaterLevelHigh(bool waterSensorLow, bool waterSensorHigh);
        bool isWaterLevelError(bool waterSensorLow, bool waterSensorHigh);
    
   
};

#endif 