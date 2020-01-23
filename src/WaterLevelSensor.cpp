#include <Arduino.h>
#include "WaterLevelSensor.h"

WaterLevelSensor::WaterLevelSensor(){
    waterLevel = WaterLevelEnum::WATER_ERROR;
}

void WaterLevelSensor::init(uint8_t lowWaterLevelPin, uint8_t highWaterLevelPin, bool useInternalPullUpRes){
    this->lowWaterLevelPin = lowWaterLevelPin;
    this->highWaterLevelPin = highWaterLevelPin;
    if(useInternalPullUpRes){
        pinMode(lowWaterLevelPin, INPUT_PULLUP);
        pinMode(highWaterLevelPin, INPUT_PULLUP);
    } else{
        pinMode(lowWaterLevelPin, INPUT);
        pinMode(highWaterLevelPin, INPUT);
    }
    isWaterLevelChanged();
}

void WaterLevelSensor::updateWaterLevel(){
    if(isWaterLevelLow()){
        waterLevel = WaterLevelEnum::WATER_LOW_LEVEL;
    } else if(isWaterLevelMedium()){
        waterLevel = WaterLevelEnum::WATER_MEDIUM_LEVEL;
    } else if(isWaterLevelHigh()){
        waterLevel = WaterLevelEnum::WATER_HIGH_LEVEL;
    } else{
        waterLevel = WaterLevelEnum::WATER_ERROR;
    }
}

bool WaterLevelSensor::isWaterLevelChanged(){
    WaterLevelEnum lastWaterLevel = waterLevel;
    updateWaterLevel();
    return lastWaterLevel == waterLevel;
}

WaterLevelEnum WaterLevelSensor::getWaterLevel(){
    updateWaterLevel();
    return waterLevel;
}

WaterLevelEnum WaterLevelSensor::getLastWaterLevel(){
    return waterLevel;
}

bool WaterLevelSensor::isWaterSensorHigh(){
    return digitalRead(highWaterLevelPin) == LOW;
}

bool WaterLevelSensor::isWaterSensorLow(){
    return digitalRead(lowWaterLevelPin) == LOW;
}

bool WaterLevelSensor::isWaterLevelLow(){
    return !isWaterSensorLow() & !isWaterSensorHigh();
}

bool WaterLevelSensor::isWaterLevelMedium(){
    return isWaterSensorLow() & !isWaterSensorHigh();
}

bool WaterLevelSensor::isWaterLevelHigh(){
    return isWaterSensorLow() & isWaterSensorHigh();
}

bool WaterLevelSensor::isWaterLevelError(){
    return !isWaterSensorLow() & isWaterSensorHigh();
}





