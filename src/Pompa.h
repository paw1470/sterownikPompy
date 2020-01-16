#ifndef POMPA_H
#define POMPA_H
#include <inttypes.h>

class Pompa
{
private:
    uint8_t m_pompaPin;
    bool stan;
public:
    Pompa(uint8_t pompaPin);
    void wlacz();
    void wylacz();
    void setup();
    bool getStan();
    ~Pompa();
};


#endif