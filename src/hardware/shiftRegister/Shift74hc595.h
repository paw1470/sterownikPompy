#ifndef SHIFT74HC595_H
#define SHIFT74HC595_H

#include <inttypes.h>
#include "Arduino.h"

class Shift74hc595{
    private:
        uint8_t dataPin; 
        uint8_t latchPin; 
        uint8_t clockPin;
        byte data;
    public:
        void init(uint8_t dataPin, uint8_t latchPin, uint8_t clockPin);
        byte getDataByte();
        bool isBitOn(uint8_t bitPosition);
        void setBit(uint8_t bitPosition, bool bitNewState);
        void setDataByte(byte data);
        void updateRegister();
        void test();
};

#endif