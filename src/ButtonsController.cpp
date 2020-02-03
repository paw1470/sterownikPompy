#include "ButtonsController.h"
#include "Config.h"

void ButtonsController::init(){
    buttonStart.init(PIN_BUTTON_START, BUTTON_START_USE_INTERNAL_PULLUP);
    buttonStop.init(PIN_BUTTON_STOP, BUTTON_STOP_USE_INTERNAL_PULLUP);
}

bool ButtonsController::isButtonStopPressed(){
    return buttonStop.isButtonPressed();
}

bool ButtonsController::isButtonStartPressed(){
    return buttonStart.isButtonPressed();
}

bool ButtonsController::isMoreThanOneButtonPressed(){
    return isButtonStartPressed() && isButtonStopPressed();
}