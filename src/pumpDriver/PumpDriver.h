#ifndef PUMPDRIVER_H
#define PUMPDRIVER_H
#include "pumpDriver/controllers/PumpsController.h"
#include "pumpDriver/controllers/LedController.h"
#include "pumpDriver/controllers/WaterSensors.h"
#include "pumpDriver/controllers/ButtonsController.h"
#include "pumpDriver/stateInterpreters/PumpStateInterpreter.h"
#include "pumpDriver/stateInterpreters/ButtonsInterpreter.h"


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
        void testOnStart();
    public:
        void init();
        void start();
        
};

#endif