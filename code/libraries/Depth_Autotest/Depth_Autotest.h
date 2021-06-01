/*
 * Depth autotest program
 *
 * Editor: Eric Lin   date: 2021.02.24
 *
 * Test step:
 *  1. Acc ON
 *  2. wait for 2sec
 *  3. Rev ON
 *  4. wait for 12sec
 *  5. Rec OFF
 *  6. wait for 0.3sec
 *  7. Acc OFF
 *  8. wait for 20.2sec
 * Repeat 300 times
 *
 */

#ifndef DEPTH_TEST_H
#define DEPTH_TEST_H

#include <Arduino.h>
#include "Displayer_SSD1306.h"

class DepthAutoTest {
private:
    uint8_t _accPin, _revPin, _swPin;
    uint16_t _count;
    bool _flag_init = true;
    bool _flag_process;
    bool _flag_1;
    bool _flag_2;
    bool _flag_3;
    bool _flag_4;
    unsigned long _firstStop = millis();
    unsigned long _secondStop = 0;
    unsigned long _thirdStop = 0;
    unsigned long _forthStop = 0;
    unsigned long _displayermillis = 0;
    Displayer_SSD1306 ssd1306;
public:
    DepthAutoTest(uint8_t accPin, uint8_t revPin, uint8_t swPin);
    void _DepthAutoTest();
    void RippleAutoTest();
    void AOAOffline();
};

#endif
