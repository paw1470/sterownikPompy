#include "InfoNaLedach.h"
#include "Arduino.h"
#include <inttypes.h>

InfoNaLedach::InfoNaLedach(uint8_t dataPin, uint8_t latchPin, uint8_t clockPin){
    m_dataPin = dataPin;
    m_latchPin = latchPin;
    m_clockPin = clockPin;
};

void InfoNaLedach::ustawZbiornikLed(Kolory kolor){
    m_ledy = m_ledy & LED_ZBIORNIK;
    switch (kolor)
    {
    case RED:
        m_ledy = m_ledy ^ LED_ZBIORNIK_RED;
        break;
    case GREEN:
        m_ledy = m_ledy ^ LED_ZBIORNIK_GREEN;
        break;
    case BLUE:
        m_ledy = m_ledy ^ LED_ZBIORNIK_BLUE;
        break;
    case ALL:
        m_ledy = m_ledy ^ LED_ZBIORNIK_RED;
        m_ledy = m_ledy ^ LED_ZBIORNIK_GREEN;
        m_ledy = m_ledy ^ LED_ZBIORNIK_BLUE;
        break;
    default:
        break;
    }
};


void InfoNaLedach::ustawPompeLed(Kolory kolor){
    m_ledy = m_ledy & LED_POMPA;
    switch (kolor)
    {
    case RED:
        m_ledy = m_ledy ^ LED_POMPA_RED;
        break;
    case GREEN:
        m_ledy = m_ledy ^ LED_POMPA_GREEN;
        break;
    case ALL:
        m_ledy = m_ledy ^ LED_POMPA_RED;
        m_ledy = m_ledy ^ LED_POMPA_GREEN;
        break;
    default:
        break;
    }
};
void InfoNaLedach::ustawStudnieLed(Kolory kolor){
     m_ledy = m_ledy & LED_STUDNIA;
    switch (kolor)
    {
    case RED:
        m_ledy = m_ledy ^ LED_STUDNIA_RED;
        break;
    case GREEN:
        m_ledy = m_ledy ^ LED_STUDNIA_GREEN;
        break;
    case BLUE:
        m_ledy = m_ledy ^ LED_STUDNIA_BLUE;
        break;
     case ALL:
        m_ledy = m_ledy ^ LED_STUDNIA_RED;
        m_ledy = m_ledy ^ LED_STUDNIA_GREEN;
        m_ledy = m_ledy ^ LED_STUDNIA_BLUE;
        break;
    default:
        break;
    }
};

void InfoNaLedach::aktualizujLedy()
{
   digitalWrite(m_latchPin, LOW);
   shiftOut(m_dataPin, m_clockPin, LSBFIRST, m_ledy);
   digitalWrite(m_latchPin, HIGH);
}

void InfoNaLedach::setup(){
    pinMode(m_dataPin, OUTPUT);
    pinMode(m_clockPin, OUTPUT);
    pinMode(m_latchPin, OUTPUT);
    m_ledy = 0b00000001;
    aktualizujLedy();
}

InfoNaLedach::~InfoNaLedach(){

};