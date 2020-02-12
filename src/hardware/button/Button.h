#ifndef BUTTON_H
#define BUTTON_H
#include <inttypes.h>

class Button{
    private:
        uint8_t buttonPin;
    public:
        void init(uint8_t pin, bool internalPullUpResistor);
        bool isButtonPressed();
};

#endif