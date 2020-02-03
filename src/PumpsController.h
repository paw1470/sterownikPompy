#ifndef PUMPSCONTROLLER_H
#define PUMPSCONTROLLER_H
#include <inttypes.h>
#include "Pump.h"
#include "PumpStateEnum.h"

class PumpsController{
    public:
        void initDevices();
        bool isPumpOn();
        void pumpTurnON();
        void pumpTurnOFF();
        void setState(PumpStateEnum state);
    private:
        Pump pump;
        void initPump();
};

#endif
