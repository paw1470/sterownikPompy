#ifndef PUMPDRIVER_H
#define PUMPDRIVER_H
#include "PumpsController.h"
#include "LedController.h"
#include "WaterSensors.h"
#include "ButtonsController.h"
#include "PumpStateInterpreter.h"
#include "ButtonsInterpreter.h"


class PumpDriver{
    private:
        PumpsController pumpsController;
        LedController ledController;
        WaterSensors waterSensors;
        ButtonsController buttons;
        PumpStateInterpreter pumpStateInterpreter;
        ButtonsInterpreter buttonsInterpreter;
        
        PumpStateEnum  pumpStatus;

        unsigned long lastTimeButtonPress;
        unsigned long lastTimeWaterLevelCheck;
        unsigned long lastTimeChangePumpState;
        unsigned long lastTimeBlink;

        void updateLedInfo();
        void timeForButtonCheck();
        void timeForWaterLevelChangeInfo();        
        void timeForAutoChangePumpState();
        void timeForBlinkLed(); 
        void checkButtons();
        void updatePump(PumpStateEnum newPumpState);
        uint16_t getTimeSince(unsigned long time);
    public:
        void init();
        void start();
        
};

#endif