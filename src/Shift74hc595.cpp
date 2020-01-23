#include "Shift74hc595.h"
#include "BitOperations.h"

void Shift74hc595::init(uint8_t dataPin, uint8_t latchPin, uint8_t clockPin){
    this->dataPin = dataPin;
    this->latchPin = latchPin;
    this->clockPin = clockPin;
    this->shiftData = 0;
}
        
byte Shift74hc595::getShiftData(){
    return shiftData;
}
        
bool Shift74hc595::isBitOn(uint8_t bitPosition){
    return true && BitVal(shiftData, bitPosition);
}

void Shift74hc595::setBit(uint8_t bitPosition, bool bitNewState){
    if(bitNewState){
        SetBit(shiftData, bitPosition);
    } else{
        ClearBit(shiftData, bitPosition);
    }
}

void Shift74hc595::setDataByte(byte data){
	this->shiftData = data;
}

void Shift74hc595::updateRegister(){
	digitalWrite(latchPin, LOW);
   	shiftOut(dataPin, clockPin, LSBFIRST, shiftData);
   	digitalWrite(latchPin, HIGH);
}