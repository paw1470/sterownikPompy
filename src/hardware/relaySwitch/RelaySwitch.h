#ifndef RELAYSWITCH_H
#define RELAYSWITCH_H
#include <inttypes.h>

//NOConnection true turn on when stateOn true; False when false
//inverted true if NOC is true on LOW
class RelaySwitch{
    public:
        RelaySwitch();
        void init(uint8_t relayPin, bool NCConection = true, bool invertedOutput = true);    //default values for relay switch
        void test();
        void turnON();
        void turnOFF();
        bool isStateOn();
    private:
        uint8_t relayPin;
        bool stateON;
        bool invertedOutput;
        void setState(bool on);
        void invertInterpreter(bool NOConnection, bool invertedOutput);
};

#endif