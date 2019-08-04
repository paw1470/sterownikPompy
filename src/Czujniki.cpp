#include "Czujniki.h"
#include <Arduino.h>

Czujniki::Czujniki(uint8_t poziomStudniDolny, uint8_t poziomStudniGorny, 
            uint8_t poziomZbiornikaDolny, uint8_t poziomZbiornikaGorny){
    m_poziomStudniDolny = poziomStudniDolny;
    m_poziomStudniGorny = poziomStudniGorny;
    m_poziomZbiornikaDolny = poziomZbiornikaDolny;
    m_poziomZbiornikaGorny = poziomZbiornikaGorny;
}

void Czujniki::setup(){
    pinMode(m_poziomStudniDolny, INPUT_PULLUP);
	pinMode(m_poziomStudniGorny, INPUT_PULLUP);
	pinMode(m_poziomZbiornikaDolny, INPUT_PULLUP);
	pinMode(m_poziomZbiornikaGorny, INPUT_PULLUP);
    sprawdz();
}

bool Czujniki::sprawdz(){
    return (sprawdzPoziomStudni() || sprawdzPoziomZbiornika());
}

bool Czujniki::sprawdzPoziomStudni(){
    if(isCzujnikStudniDolny()){
        if(isCzujnikStudniGorny()){
            if(m_ostatniPoziomStudni == WYSOKI){
                return false;
            } else{
                m_ostatniPoziomStudni = WYSOKI;
                return true;
            }
        } else{
            if(m_ostatniPoziomStudni == SREDNI){
                return false;
            } else{
                m_ostatniPoziomStudni = SREDNI;
                return true;
            }
        }   
    } else{
        if(isCzujnikStudniGorny()){
                m_ostatniPoziomStudni = BLAD;
                return true;
        } else{
            if(m_ostatniPoziomStudni == NISKI){
                return false;
            } else{
                m_ostatniPoziomStudni = NISKI;
                return true;
            }
        }   
    }
}

bool Czujniki::sprawdzPoziomZbiornika(){
     if(isCzujnikZbiornikaDolny()){
        if(isCzujnikZbiornikaGorny()){
            if(m_ostatniPoziomZbiornika == WYSOKI){
                return false;
            } else{
                m_ostatniPoziomZbiornika = WYSOKI;
                return true;
            }
        } else{
            if(m_ostatniPoziomZbiornika == SREDNI){
                return false;
            } else{
                m_ostatniPoziomZbiornika = SREDNI;
                return true;
            }
        }   
    } else{
        if(isCzujnikZbiornikaGorny()){
                m_ostatniPoziomZbiornika = BLAD;
                return true;
        } else{
            if(m_ostatniPoziomZbiornika == NISKI){
                return false;
            } else{
                m_ostatniPoziomZbiornika = NISKI;
                return true;
            }
        }   
    }
}

PoziomWody Czujniki::getPoziomStudni(){
    return m_ostatniPoziomStudni;
}

PoziomWody Czujniki::getPoziomZbiornika(){
    return m_ostatniPoziomZbiornika;
}

bool Czujniki::isCzujnikStudniDolny(){
    return digitalRead(m_poziomStudniDolny) == LOW;
}

bool Czujniki::isCzujnikStudniGorny(){
    return digitalRead(m_poziomStudniGorny) == LOW;
}

bool Czujniki::isCzujnikZbiornikaDolny(){
    return digitalRead(m_poziomZbiornikaDolny) == LOW;
}

bool Czujniki::isCzujnikZbiornikaGorny(){
    return digitalRead(m_poziomZbiornikaGorny) == LOW;
}

Czujniki::~Czujniki(){

}