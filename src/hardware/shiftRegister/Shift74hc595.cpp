#include "Shift74hc595.h"
#include "BitOperations.h"

void Shift74hc595::init(uint8_t dataPin, uint8_t latchPin, uint8_t clockPin){
    this->dataPin = dataPin;
    this->latchPin = latchPin;
    this->clockPin = clockPin;
    pinMode(dataPin, OUTPUT);
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    this->data = 0;
}
        
byte Shift74hc595::getDataByte(){
    return data;
}
        
bool Shift74hc595::isBitOn(uint8_t bitPosition){
    return true && BitVal(data, bitPosition);
}

void Shift74hc595::setBit(uint8_t bitPosition, bool bitNewState){
    if(bitNewState){
        SetBit(data, bitPosition);
    } else{
        ClearBit(data, bitPosition);
    }
}

void Shift74hc595::setDataByte(byte data){
    if(this->data != data){
        this->data = data;
        updateRegister();
    }
}

void Shift74hc595::updateRegister(){
	digitalWrite(latchPin, LOW);
   	shiftOut(dataPin, clockPin, LSBFIRST, data);
   	digitalWrite(latchPin, HIGH);
}

void Shift74hc595::test(){
    this->data = 1;
    for(int i=0; i<8; i++){
        updateRegister();
        this->data <<= 1;
        delay(250);
    }
    this->data = 0;
}