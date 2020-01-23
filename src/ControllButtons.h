#ifndef CONTROLLBUTTONS_H
#define CONTROLLBUTTONS_H
#include "Button.h"

class ControllButtons{
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