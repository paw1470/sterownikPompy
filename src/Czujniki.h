#ifndef CZUJNIKI_H
#define CZUJNIKI_H
#include <inttypes.h>

enum PoziomWody{
    NISKI,
    SREDNI,
    WYSOKI,
    BLAD
};

class Czujniki
{
private:
    bool sprawdzPoziomStudni();
    bool sprawdzPoziomZbiornika();
    bool isCzujnikStudniDolny();
    bool isCzujnikStudniGorny();
    bool isCzujnikZbiornikaDolny();
    bool isCzujnikZbiornikaGorny();

    uint8_t m_poziomStudniDolny;
    uint8_t m_poziomStudniGorny;
    uint8_t m_poziomZbiornikaDolny;
    uint8_t m_poziomZbiornikaGorny;
    PoziomWody m_ostatniPoziomStudni;
    PoziomWody m_ostatniPoziomZbiornika;

public:
    Czujniki(uint8_t poziomStudniDolny, uint8_t poziomStudniGorny, 
            uint8_t poziomZbiornikaDolny, uint8_t poziomZbiornikaGorny);
    bool sprawdz();
    void setup();
    PoziomWody getPoziomStudni();
    PoziomWody getPoziomZbiornika();
    ~Czujniki();
};

#endif 