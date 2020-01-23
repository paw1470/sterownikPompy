#ifndef OUTPUTDEVICES_H
#define OUTPUTDEVICES_H
#include <inttypes.h>
#include "Pump.h"

class OutputDevices{
    public:
        void initDevices();
        bool isPumpOn();
        void pumpTurnON();
        void pumpTurnOFF();

    private:
        Pump pump;
        void initPump();
};

#endif
