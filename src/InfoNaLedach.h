#ifndef INFONALEDACH_H
#define INFONALEDACH_H

#include <inttypes.h>

#define LED_STUDNIA         0b11111000
#define LED_ZBIORNIK        0b11000111
#define LED_POMPA           0b00111111

#define LED_STUDNIA_RED     0b00000001
#define LED_STUDNIA_GREEN   0b00000010
#define LED_STUDNIA_BLUE    0b00000100
#define LED_ZBIORNIK_RED    0b00001000
#define LED_ZBIORNIK_GREEN  0b00010000
#define LED_ZBIORNIK_BLUE   0b00100000
#define LED_POMPA_RED       0b01000000
#define LED_POMPA_GREEN     0b10000000

enum Kolory{
    RED,
    GREEN,
    BLUE,
    ALL
};

class InfoNaLedach
{
private:
    uint8_t m_dataPin; 
    uint8_t m_latchPin; 
    uint8_t m_clockPin;
    uint8_t m_ledy;

public:
    InfoNaLedach(uint8_t dataPin, uint8_t latchPin, uint8_t clockPin);
    void ustawZbiornikLed(Kolory kolor);
    void ustawPompeLed(Kolory kolor);
    void ustawStudnieLed(Kolory kolor);
    void aktualizujLedy();
    void setup();
    ~InfoNaLedach();
};



#endif

