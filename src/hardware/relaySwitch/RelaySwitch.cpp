#include "RelaySwitch.h"
#include "Arduino.h"

RelaySwitch::RelaySwitch(){
    this->stateON = false;
}

void RelaySwitch::turnON(){
    this->stateON = true;
    setState(true);
}

void RelaySwitch::turnOFF(){
    stateON = false;
    setState(false);
}


void RelaySwitch::setState(bool on){
    if(on != invertedOutput){
        digitalWrite(relayPin, HIGH);
    } else{
        digitalWrite(relayPin, LOW);
    }
}

bool RelaySwitch::isStateOn(){
    return stateON;
}

void RelaySwitch::invertInterpreter(bool NOConnection, bool invertedOutput){
    this->invertedOutput = !NOConnection != invertedOutput;
}

void RelaySwitch::test(){
    turnON();
    delay(1000);
    turnOFF();
}

void RelaySwitch::init(uint8_t relayPin, bool NOConnection, bool invertedOutput){
    this->relayPin = relayPin;
    stateON = false;
    invertInterpreter(NOConnection, invertedOutput);
    pinMode(relayPin, OUTPUT);
    turnOFF();
}