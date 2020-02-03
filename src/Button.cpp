#include "Button.h"
#include "Arduino.h"

void Button::init(uint8_t pin, bool internalPullUpResistor){
    buttonPin = pin;
    if(internalPullUpResistor){
        pinMode(buttonPin, INPUT_PULLUP);
    } else{
        pinMode(buttonPin, INPUT);
    }
}

bool Button::isButtonPressed(){ 
    return !digitalRead(buttonPin);
}

