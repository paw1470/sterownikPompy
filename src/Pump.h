#ifndef PUMP_H
#define PUMP_H
#include <inttypes.h>

//NOConnection true turn on when stateOn true; False when false
//inverted true if NOC is true on LOW
class Pump{
    public:
        Pump();
        void init(uint8_t pumpPin, bool NCConection, bool invertedOutput);
        void test();
        void turnON();
        void turnOFF();
        bool isStateOn();
    private:
        uint8_t pumpPin;
        bool stateON;
        bool invertedOutput;
        void setPumpState(bool on);
        void invertInterpreter(bool NOConnection, bool invertedOutput);
};

#endif