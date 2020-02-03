#ifndef CONFIG_H
#define CONFIG_H

//  WAIT TIME
#define WAIT_TIME_BETWEN_BUTTON         150
#define WAIT_TIME_WATER_LEVEL_CHECK     75
#define WAIT_TIME_AUTO_CHANGE           1000
#define WAIT_TIME_BLINK_LED             300

//  BUTTONS
#define PIN_BUTTON_STOP                     4
#define BUTTON_STOP_USE_INTERNAL_PULLUP     true

#define PIN_BUTTON_START                    5
#define BUTTON_START_USE_INTERNAL_PULLUP    true

//  TANK
#define PIN_TANK_WATER_LEVEL_LOW    6 
#define PIN_TANK_WATER_LEVEL_HIGH   7
#define TANK_USE_INTERNAL_PULLUP    true

//  WELL
#define PIN_WELL_WATER_LEVEL_LOW    8
#define PIN_WELL_WATER_LEVEL_HIGH   9
#define WELL_USE_INTERNAL_PULLUP    true

//  SHIFT REGISTER
#define PIN_SHIFT_REGISTER_CLOCK    10
#define PIN_SHIFT_REGISTER_LATCH    11
#define PIN_SHIFT_REGISTER_DATA     12

//  PUMP
#define PIN_PUMP                    13          //13 pin with internal led
#define PUMP_N_O_CONNECTED          true        //pump in normally open connection in relay switch
#define PUMP_INVERTED_OUTPUT        true        //led 13 is off when pump on

#endif