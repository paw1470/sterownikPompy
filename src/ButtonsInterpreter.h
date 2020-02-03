#ifndef BUTTONSINTERPRETER_H
#define BUTTONSINTERPRETER_H
#include "PumpStateEnum.h"

class ButtonsInterpreter{


private:
    /* data */
public:
    PumpStateEnum getStateWithStartButton(PumpStateEnum oldPumpState);
    PumpStateEnum getStateWithStopButton(PumpStateEnum oldPumpState);
    PumpStateEnum getStateWithAllButtons(PumpStateEnum oldPumpState);
};


#endif