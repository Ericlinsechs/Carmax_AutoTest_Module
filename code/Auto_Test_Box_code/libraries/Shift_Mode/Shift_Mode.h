/*
 * Shift mode program
 *
 * Editor: Eric Lin
 * Date: 2021/06/16
 *
 * In this head file have all definition of mode selecting.
 * Once auto-test box is enabled, mode selecting would be trigger.
 *
 */

#ifndef SHIFT_MODE_H
#define SHIFT_MODE_H

#include <Arduino.h>
#include "Displayer_SSD1306.h"
#include "Current_Monitor.h"

extern uint8_t buttonState;
extern byte mode;

class ShiftMode {
private:
    uint8_t _accPin, _revPin;
    uint8_t _button_count;
    uint8_t _lastbuttonState;
    uint8_t _countdown;
    byte _mode;
    bool _flag = true;
    unsigned long _endMillis = 0;
    unsigned long _breakoutTime = 5000;  // 5 sec to break out
    Displayer_SSD1306 ssd1306;
    CurrentMonitor currentmonitor;
    WebPage webpage;
public:
    ShiftMode();
    int _ShiftMode(uint8_t accPin, uint8_t revPin);
    void button_function(uint8_t button_count);
    void function_initialize();
};









#endif
