/*
 * Depth autotest program
 *
 * Editor: Eric Lin
 * Date: 2021/06/16
 *
 * In this head file include three test functions Definition,
 * which are :
 * 1. 深度測試    -->    _DepthAutoTest()
 * 2. 布條紋測試  -->    RippleAutoTest()
 * 3. AOA斷線測試 -->    AOAOffline()
 *
 */

#ifndef DEPTH_TEST_H
#define DEPTH_TEST_H

#include <Arduino.h>
#include "Displayer_SSD1306.h"
#include "Shift_Mode.h"

class DepthAutoTest {
private:
    uint8_t _accPin, _revPin;
    uint8_t _button_count;
    uint16_t _count;
    uint8_t _buttonState;
    uint8_t _lastButtonState;
    uint8_t _stateFlag;
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
    ShiftMode shiftmode;
public:
    DepthAutoTest(uint8_t accPin, uint8_t revPin);
    void _DepthAutoTest();
    void RippleAutoTest();
    void AOAOffline();
};

#endif
