#ifndef PUMPSCONTROLLER_H
#define PUMPSCONTROLLER_H
#include <inttypes.h>
#include "hardware/relaySwitch/RelaySwitch.h"
#include "pumpDriver/PumpStateEnum.h"

class PumpsController{
    public:
        void initDevices();
        bool isPumpOn();
        void pumpTurnON();
        void pumpTurnOFF();
        void setState(PumpStateEnum state);
    private:
        RelaySwitch pump;
        void initPump();
};

#endif
