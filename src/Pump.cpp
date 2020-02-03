#include "Pump.h"
#include "Arduino.h"

Pump::Pump(){
    this->stateON = false;
}

void Pump::turnON(){
    this->stateON = true;
    setPumpState(true);
}

void Pump::turnOFF(){
    stateON = false;
    setPumpState(false);
}


void Pump::setPumpState(bool on){
    if(on != invertedOutput){
        digitalWrite(pumpPin, HIGH);
    } else{
        digitalWrite(pumpPin, LOW);
    }
}

bool Pump::isStateOn(){
    return stateON;
}

void Pump::invertInterpreter(bool NOConnection, bool invertedOutput){
    this->invertedOutput = !NOConnection != invertedOutput;
}

void Pump::test(){
    turnON();
    delay(1000);
    turnOFF();
}

void Pump::init(uint8_t pumpPin, bool NOConnection, bool invertedOutput){
    this->pumpPin = pumpPin;
    stateON = false;
    invertInterpreter(NOConnection, invertedOutput);
    pinMode(pumpPin, OUTPUT);
    turnOFF();
}