#ifndef BUTTONSCONTROLLER_H
#define BUTTONSCONTROLLER_H
#include "ButtonPB.h"

class ButtonsController{
    private:
        ButtonPB buttonStart;
        ButtonPB buttonStop;
    public:
        void init();
        bool isButtonStopPressed();
        bool isButtonStartPressed();
        bool isMoreThanOneButtonPressed();
};

#endif