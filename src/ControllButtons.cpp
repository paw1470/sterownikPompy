#include "ControllButtons.h"
#include "Config.h"

void ControllButtons::init(){
    buttonStart.init(PIN_BUTTON_START, BUTTON_START_USE_INTERNAL_PULLUP);
    buttonStop.init(PIN_BUTTON_STOP, BUTTON_STOP_USE_INTERNAL_PULLUP);
}

bool ControllButtons::isButtonStopPressed(){
    return buttonStop.isButtonPressed();
}

bool ControllButtons::isButtonStartPressed(){
    return buttonStart.isButtonPressed();
}

bool ControllButtons::isMoreThanOneButtonPressed(){
    return isButtonStartPressed() && isButtonStopPressed();
}