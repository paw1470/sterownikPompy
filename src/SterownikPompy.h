#ifndef STEROWNIKPOMPY_H
#define STEROWNIKPOMPY_H

#include "Pompa.h"
#include "Czujniki.h"
#include "InfoNaLedach.h"

class SterownikPompy
{
private:
    Pompa *pompa;
    Czujniki *czujniki;
    InfoNaLedach *infoNaLedach;
    void aktualizujStanLedow(Kolory kolorDlaStudni, Kolory kolorDlaZbiornika, Kolory kolorDlaPompy);
    void aktualizujStanLedow();
public:
    SterownikPompy(uint8_t poziomStudniDolny, uint8_t poziomStudniGorny, 
            uint8_t poziomZbiornikaDolny, uint8_t poziomZbiornikaGorny,
            uint8_t dataPin, uint8_t latchPin, uint8_t clockPin,
            uint8_t pompaPin);
    void wymusWlaczenie();
    void wymusWylaczenie();
    void sprawdzStanyCzujnikow();
    void setup();
    ~SterownikPompy();
};




#endif