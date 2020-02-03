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
    bool waterSensorLow = isWaterSensorLow();
    bool waterSensorHigh = isWaterSensorHigh();
    if(isWaterLevelLow(waterSensorLow, waterSensorHigh)){
        waterLevel = WaterLevelEnum::WATER_LOW_LEVEL;
    } else if(isWaterLevelMedium(waterSensorLow, waterSensorHigh)){
        waterLevel = WaterLevelEnum::WATER_MEDIUM_LEVEL;
    } else if(isWaterLevelHigh(waterSensorLow, waterSensorHigh)){
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
    return !digitalRead(highWaterLevelPin);
}

bool WaterLevelSensor::isWaterSensorLow(){
    return !digitalRead(lowWaterLevelPin);
}

bool WaterLevelSensor::isWaterLevelLow(bool waterSensorLow, bool waterSensorHigh){
    return !waterSensorLow & !waterSensorHigh;
}

bool WaterLevelSensor::isWaterLevelMedium(bool waterSensorLow, bool waterSensorHigh){
    return waterSensorLow & !waterSensorHigh;
}

bool WaterLevelSensor::isWaterLevelHigh(bool waterSensorLow, bool waterSensorHigh){
    return waterSensorLow & waterSensorHigh;
}

bool WaterLevelSensor::isWaterLevelError(bool waterSensorLow, bool waterSensorHigh){
    return !waterSensorLow & waterSensorHigh;
}





