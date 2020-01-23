#ifndef PUMPDRIVER_H
#define PUMPDRIVER_H
#include "OutputDevices.h"
#include "LedController.h"
#include "WaterSensors.h"
#include "ControllButtons.h"

class PumpDriver{
    private:
        OutputDevices outputDevices;
        LedController ledController;
        WaterSensors waterSensors;
        ControllButtons buttons;

        WaterLevelEnum lastWellStatus;
        WaterLevelEnum lastTankStatus;
        PumpStateEnum  lastPumpSatus;

        PumpStateEnum  pumpStatus;

        unsigned long lastTimeButtonPress;
        unsigned long lastTimeWaterLevelCheck;
        unsigned long lastTimeAutoChange;
        unsigned long lastTimeBlink;

        void updateLedInfo();
        bool isWaterLevelChanged();
        bool isWellLevelChanged();
        bool isTankLevelChanged();
        bool checkButtons();
        bool changeStateButtonStart();
        bool changeStateButtonStop();
        bool changeStateButtonError();
        bool isAutomaticControll();
        void changeOutputDevicesState();
        bool isTimeForButtonCheck();
        bool isTimeForWaterLevelCheck();
        bool isTimeForAutoChangeState();
        bool isTimeForBlinkLed();
        uint16_t getTimeSince(unsigned long time);
    public:
        void init();
        void start();
        
};

#endif