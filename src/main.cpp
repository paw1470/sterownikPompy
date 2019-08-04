#include <Arduino.h>
#include "SterownikPompy.h"

#define poziomStudniMinPin 8           //mozna define zastapic "int nazwa = wartosc"
#define poziomStudniMaxPin 9
#define poziomZbiornikaMinPin 6
#define poziomZbiornikaMaxPin 7
#define latchPin 11
#define dataPin 12
#define clockPin 10
#define wlacznikPompy  5
#define wylacznikPompy 4
#define pompa 13

unsigned int czasOczekiwania = 1000; // ile ms ma czekac po aktualizacji stanu pompy

SterownikPompy sterownikPompy(poziomStudniMinPin, poziomStudniMaxPin,
								poziomZbiornikaMinPin, poziomZbiornikaMaxPin,
								dataPin, latchPin, clockPin,
								pompa);

unsigned long czasOstatniegoSprawdzeniaStanu;

bool isWlacznikWcisniety(){
	return digitalRead(wlacznikPompy) == LOW;
}

bool isWylacznikWcisniety(){
	return digitalRead(wylacznikPompy) == LOW;
}

void setup() {
	czasOstatniegoSprawdzeniaStanu = 0;
	pinMode(wylacznikPompy, INPUT_PULLUP);
	pinMode(wlacznikPompy, INPUT_PULLUP);
	sterownikPompy.setup();
}

void loop() {
	if ((unsigned long)(millis() - czasOstatniegoSprawdzeniaStanu) >= czasOczekiwania){
		sterownikPompy.sprawdzStanyCzujnikow();
		czasOstatniegoSprawdzeniaStanu = millis();
	}
	if(isWlacznikWcisniety()){
		sterownikPompy.wymusWlaczenie();
	}
	if(isWylacznikWcisniety()){
		sterownikPompy.wymusWylaczenie();
	}
	delay(50);
}