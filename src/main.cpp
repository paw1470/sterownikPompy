#include <Arduino.h>

#define poziomStudniMin 6           //mozna define zastapic "int nazwa = wartosc"
#define poziomStudniMax 7
#define poziomZbiornikaMin 8
#define poziomZbiornikaMax 9
#define wlacznikPompy  5
#define wylacznikPompy 4
#define ledStudniPusta 11				
#define ledZbiornikaPelny 12
#define pompa 10

bool pompaWlaczona;   //zmienna przechowujaca informacje czy pompa aktualnie powinna dzialac

void wylaczPompe(){
  	pompaWlaczona = false;    //zaznaczam informacje ze pompa wylaczona 
  	digitalWrite(pompa, HIGH); //wylaczam pompe ustawiajac stan wysoki bo tak dziala moj przekaznik
}

void wlaczPompe(){
  	pompaWlaczona = true;
  	digitalWrite(pompa, LOW);
}



//jezeli bedzie woda to powinno byc low, jezeli woda nie dotyka to pull-up powinien dawac high

bool isStudniaPusta(){
	if(digitalRead(poziomStudniMin) == HIGH){
		return true;//pusta studnia ma dac true jezeli woda nie bedzie obnizala napiecia
	} else {
		return false;
	}
		
}

bool isStudniaPelna(){
	if(digitalRead(poziomStudniMax) == HIGH){
		return false; //pelna studnia ma dac true jezeli bedzie czujnik bedzie w wodzie
	} else {
		return true;
	}
		
}

bool isZbiornikPelny(){
	if(digitalRead(poziomZbiornikaMax) == HIGH){
		return false;
	} else {
		return true;
	}
	
}

bool isWlacznikWcisniety(){
	if(digitalRead(wlacznikPompy) == HIGH){
		return false;
	} else {
		return true;
	}
}

bool isWylacznikWcisniety(){
	if(digitalRead(wylacznikPompy) == HIGH){
		return false;
	} else {
		return true;
	}
}

void ledPustaStudnia(bool pusta){
	if(pusta){
		digitalWrite(ledStudniPusta, HIGH); //studnia pusta wiec wlaczam diode
	} else {
		digitalWrite(ledStudniPusta, LOW); //studnia nie jest pusta wiec wylaczam diode
	}
}

void ledPelnyZbiornik(bool pelny){
	if(pelny){
		digitalWrite(ledZbiornikaPelny, HIGH); //studnia pusta wiec wlaczam diode
	} else {
		digitalWrite(ledZbiornikaPelny, LOW); //studnia nie jest pusta wiec wylaczam diode
	}
}

void sprawdzStany(){
	if(pompaWlaczona){				//pompa wlaczona?
		if(isZbiornikPelny()){		//wylacz jak zbiornik pelny
			wylaczPompe();
		}
		if(isStudniaPusta()){
			wylaczPompe();			//wylacz jak nie ma wody w studni
		}
		if(isWylacznikWcisniety()){
			wylaczPompe();
		}
	} else {						//jak pompa wylaczona
		if(isZbiornikPelny()){		//jak zbiornik pelny 
			//pusty if dla latwiejszego zrozumienia
		} else {					//jak zbiornik nie jest pelny 
			if(isStudniaPelna()){		//jezeli studnia jest pelna
				wlaczPompe();		//wlacz pompe bo studnia pelna
			}
			if(isWlacznikWcisniety()){	//wlacz pompe bo tak
				wlaczPompe();
			}
		}
	}
}

void ustawLedy(){
	if(isZbiornikPelny()){
		ledPelnyZbiornik(true);
	} else {
		ledPelnyZbiornik(false);
	}
	if(isStudniaPusta()){
		ledPustaStudnia(true);
	} else {
		ledPustaStudnia(false);
	}
}

void setup() {
	pinMode(poziomStudniMin, INPUT_PULLUP);
	pinMode(poziomStudniMax, INPUT_PULLUP);
	pinMode(poziomZbiornikaMin, INPUT_PULLUP);
	pinMode(poziomZbiornikaMax, INPUT_PULLUP);
	pinMode(wylacznikPompy, INPUT_PULLUP);
	pinMode(wlacznikPompy, INPUT_PULLUP);
	pinMode(ledStudniPusta, OUTPUT);
	pinMode(ledZbiornikaPelny, OUTPUT);
	pinMode(pompa, OUTPUT);
	wylaczPompe();
}

void loop() {
	sprawdzStany();
	ustawLedy();
	delay(50);
}