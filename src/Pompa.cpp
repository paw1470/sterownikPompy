#include "Pompa.h"
#include "Arduino.h"

Pompa::Pompa(uint8_t pompaPin)
{
    m_pompaPin = pompaPin;
}

void Pompa::wylacz(){
    stan = false;   
  	digitalWrite(m_pompaPin, HIGH);
}

void Pompa::wlacz(){
    stan = true;   
  	digitalWrite(m_pompaPin, LOW);
}

bool Pompa::getStan(){
    return stan;
}

void Pompa::setup(){
    pinMode(m_pompaPin, OUTPUT);
    wylacz();
}

Pompa::~Pompa()
{
}