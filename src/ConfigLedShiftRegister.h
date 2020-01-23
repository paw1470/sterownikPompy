#ifndef CONFIGLEDSHIFTREGISTER_H
#define CONFIGLEDSHIFTREGISTER_H

#define LED_1_OFF       0b11111000      //for &
#define LED_1_RED       0b00000001 
#define LED_1_GREEN     0b00000010
#define LED_1_BLUE      0b00000100

#define LED_2_OFF       0b11000111      //for &
#define LED_2_RED       0b00001000
#define LED_2_GREEN     0b00010000
#define LED_2_BLUE      0b00100000

//only 2 bits
#define LED_3_OFF       0b00111111      //for &
#define LED_3_RED       0b01000000
#define LED_3_GREEN     0b10000000

//WELL
#define LED_WELL_OFF        LED_1_OFF
#define LED_WELL_RED        LED_1_RED
#define LED_WELL_GREEN      LED_1_GREEN
#define LED_WELL_BLUE       LED_1_BLUE
#define LED_WELL_YELLOW     LED_1_RED | LED_1_GREEN
#define LED_WELL_MAGENTA    LED_1_RED | LED_1_BLUE
#define LED_WELL_CYAN       LED_1_GREEN |LED_1_BLUE
#define LED_WELL_WHITE      LED_1_RED | LED_1_GREEN | LED_1_BLUE

//TANK
#define LED_TANK_OFF        LED_2_OFF
#define LED_TANK_RED        LED_2_RED
#define LED_TANK_GREEN      LED_2_GREEN
#define LED_TANK_BLUE       LED_2_BLUE
#define LED_TANK_YELLOW     LED_2_RED | LED_2_GREEN
#define LED_TANK_MAGENTA    LED_2_RED | LED_2_BLUE
#define LED_TANK_CYAN       LED_2_GREEN |LED_2_BLUE
#define LED_TANK_WHITE      LED_2_RED | LED_2_GREEN | LED_2_BLUE

//PUMP
#define LED_PUMP_OFF        LED_3_OFF
#define LED_PUMP_RED        LED_3_RED
#define LED_PUMP_GREEN      LED_3_GREEN
#define LED_PUMP_YELLOW     LED_3_RED | LED_3_GREEN



#endif