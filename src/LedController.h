#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H
#include "Shift74hc595.h"
#include "WaterLevelEnum.h"
#include "PumpStateEnum.h"


class LedController{
    private:
        Shift74hc595 stateLedShiftRegister;
        void initShiftRegister();
        byte clearPumpInfo(byte data);
        byte clearWellInfo(byte data);
        byte clearTankInfo(byte data);
        bool blink;
    public:
        void init();
        void setWellInfo(WaterLevelEnum wellWaterLevel);
        void setTankInfo(WaterLevelEnum tankWaterLevel);
        void setPumpInfo(PumpStateEnum pumpState);
        void update();
        void blinkPump();
        void test();
        void colorTest();
};

#endif
