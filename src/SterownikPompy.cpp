#include "SterownikPompy.h"
#include "Arduino.h"

SterownikPompy::SterownikPompy(uint8_t poziomStudniDolny, uint8_t poziomStudniGorny, 
            uint8_t poziomZbiornikaDolny, uint8_t poziomZbiornikaGorny,
            uint8_t dataPin, uint8_t latchPin, uint8_t clockPin,
            uint8_t pompaPin){
    czujniki = new Czujniki(poziomStudniDolny, poziomStudniGorny, poziomZbiornikaDolny, poziomZbiornikaGorny);
    infoNaLedach = new InfoNaLedach(dataPin, latchPin, clockPin);
    pompa = new Pompa(pompaPin);
}

void SterownikPompy::wymusWlaczenie(){
    czujniki->sprawdz();
    PoziomWody studnia = czujniki->getPoziomStudni();
    PoziomWody zbiornik = czujniki->getPoziomZbiornika();
    if(studnia != NISKI &&
            studnia != BLAD &&
            zbiornik != WYSOKI &&
            zbiornik != BLAD){
        pompa->wlacz();
    }
    aktualizujStanLedow();
}

void SterownikPompy::wymusWylaczenie(){
    pompa->wylacz();
    aktualizujStanLedow();
}

void SterownikPompy::sprawdzStanyCzujnikow(){
    czujniki->sprawdz();
    PoziomWody studnia = czujniki->getPoziomStudni();
    PoziomWody zbiornik = czujniki->getPoziomZbiornika();
    if(pompa->getStan()){
        if(studnia == NISKI ||
                studnia == BLAD || 
                zbiornik == WYSOKI ||
                zbiornik == BLAD){
            pompa->wylacz();   
        }     
    } else{
        if(studnia == WYSOKI && zbiornik == NISKI){
            pompa->wlacz();
        }
    }
    aktualizujStanLedow();
}

void SterownikPompy::aktualizujStanLedow(){
    Kolory kolorDlaStudni;
    switch (czujniki->getPoziomStudni())
    {
    case NISKI:
        kolorDlaStudni = RED;
        break;
    case SREDNI:
        kolorDlaStudni = BLUE;
        break;
    case WYSOKI:
        kolorDlaStudni = GREEN;
        break;
    default:
        kolorDlaStudni = ALL;
        break;
    }

    Kolory kolorDlaZbiornika;
    switch (czujniki->getPoziomZbiornika())
    {
    case NISKI:
        kolorDlaZbiornika = GREEN;
        break;
    case SREDNI:
        kolorDlaZbiornika = BLUE;
        break;
    case WYSOKI:
        kolorDlaZbiornika = RED;
        break;
    default:
        kolorDlaZbiornika = ALL;
        break;
    }
    
    Kolory kolorDlaPompy;
    if(pompa->getStan())
    {
        kolorDlaPompy = GREEN;
    } else{
        kolorDlaPompy = RED;
    }
    aktualizujStanLedow(kolorDlaStudni, kolorDlaZbiornika, kolorDlaPompy);
}

void SterownikPompy::aktualizujStanLedow(Kolory kolorDlaStudni, Kolory kolorDlaZbiornika, Kolory kolorDlaPompy){
    infoNaLedach->ustawStudnieLed(kolorDlaStudni);
    infoNaLedach->ustawZbiornikLed(kolorDlaZbiornika);
    infoNaLedach->ustawPompeLed(kolorDlaPompy);
    infoNaLedach->aktualizujLedy();
}


void SterownikPompy::setup(){
    infoNaLedach->setup();
    czujniki->setup();
    pompa->setup();
    delay(1000);
    sprawdzStanyCzujnikow();
}

SterownikPompy::~SterownikPompy(){
    
}