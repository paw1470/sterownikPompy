#ifndef PUMPSCONTROLLER_H
#define PUMPSCONTROLLER_H
#include <inttypes.h>
#include "RelaySwitchPB.h"
#include "pumpDriver/PumpStateEnum.h"

class PumpsController{
    public:
        void initDevices();
        bool isPumpOn();
        void pumpTurnON();
        void pumpTurnOFF();
        void setState(PumpStateEnum state);
    private:
        RelaySwitchPB pump;
        void initPump();
};

#endif
