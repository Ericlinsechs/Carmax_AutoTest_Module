#include "Shift_Mode.h"

uint8_t buttonState;
byte mode;

ShiftMode::ShiftMode(){}

int ShiftMode::_ShiftMode(uint8_t accPin, uint8_t revPin) {
    _accPin = accPin;
    _revPin = revPin;
    while(_flag) {
        if (buttonState != _lastbuttonState) {
            _endMillis = millis();
            if (mode < 4)
                mode ++;
            else
                mode = 0;
            _lastbuttonState = buttonState;
            _mode = mode;
        }
        _countdown = 5 - (millis() - _endMillis)/1000;
        ssd1306.Initialization_setting( _flag, _countdown);    // Show the countdown on the bottom left side of displayer
        if (millis() - _endMillis > _breakoutTime) {           // The end of mode selecting
            _flag = !_flag;
            ssd1306.Initialization_setting(_flag, _countdown);
            buttonState = 0;
            function_initialize();
            Serial.println("Selecting mode ended");
        }
        _mode = mode;
    }
    return _mode;
};

void ShiftMode::welcome_message() {
    while (buttonState < 1) {
        ssd1306.welcome_message_displayer();
        _endMillis = millis();
    }
}
/* The value would be change when the botton is pressed */
void ShiftMode::button_function(uint8_t button_count) {
    _button_count = button_count;
    buttonState += _button_count;
    if (buttonState >= 2)  // the value could only be 0 or 1
        buttonState = 0;
};

void ShiftMode::function_initialize() {
    switch(_mode) {
        case 0:
            Serial.println("深度測試模式");
            break;
        case 1:
            Serial.println("布條紋測試模式");
            break;
        case 2:
            Serial.println("AOA斷線模式");
            break;
        case 3:
            Serial.println("電流監控模式");
            currentmonitor.CurrentMonitor_initialize(_accPin, _revPin);
            break;
        case 4:
            Serial.println("電流紀錄連續10sec模式");
            webpage.WifiConnect();
            webpage.HTTPServer();
            currentmonitor.CurrentMonitor_initialize(_accPin, _revPin);
            break;
        default:
            Serial.println("深度測試模式");
    }
};
