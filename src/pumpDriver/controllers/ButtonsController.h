#ifndef BUTTONSCONTROLLER_H
#define BUTTONSCONTROLLER_H
#include "hardware/button/Button.h"

class ButtonsController{
    private:
        Button buttonStart;
        Button buttonStop;
    public:
        void init();
        bool isButtonStopPressed();
        bool isButtonStartPressed();
        bool isMoreThanOneButtonPressed();
};

#endif