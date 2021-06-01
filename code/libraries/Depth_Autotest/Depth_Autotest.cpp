#include "Depth_Autotest.h"

DepthAutoTest::DepthAutoTest(uint8_t accPin, uint8_t revPin, uint8_t swPin) {
    _accPin = accPin;
    _revPin = revPin;
    _swPin = swPin;
    pinMode(_accPin, OUTPUT);
    pinMode(_revPin, OUTPUT);
    pinMode(_swPin, INPUT_PULLUP);
    digitalWrite(_accPin, LOW);
    digitalWrite(_revPin, LOW);
}

void DepthAutoTest::_DepthAutoTest() {
    if (digitalRead(_swPin) == LOW || _flag_process == true) {
        if (millis() - _displayermillis >= 300){
            ssd1306.DepthAutoTest_counter(_count);
            _displayermillis = millis();
        }
        if (_flag_init) {
            digitalWrite(_accPin, HIGH);
            _firstStop = millis();
            _flag_init = false;
            _flag_1 = true;
        }
        else if ((millis() - _firstStop >= 2000) && _flag_1) {
            digitalWrite(_revPin, HIGH);
            _secondStop = millis();
            _flag_1 = false;
            _flag_2 = true;
            _flag_process = true;
            _count ++;
        }
        else if ((millis() - _secondStop >= 12000) && _flag_2) {
            digitalWrite(_revPin, LOW);
            _thirdStop = millis();
            _flag_2 = false;
            _flag_3 = true;
        }
        else if ((millis() - _thirdStop >= 300) && _flag_3) {
            digitalWrite(_accPin, LOW);
            _forthStop = millis();
            _flag_3 = false;
            _flag_4 = true;
            _flag_process = false;
        }
        else if ((millis() - _forthStop >= 20200) && _flag_4) {
            digitalWrite(_accPin, HIGH);
            _firstStop = millis();
            _flag_4 = false;
            _flag_1 = true;
        }
    }
}

void DepthAutoTest::RippleAutoTest() {
    if (digitalRead(_swPin) == LOW || _flag_process == true) {
        if (millis() - _displayermillis >= 300){
            ssd1306.RippleAutoTest_counter(_count);
            _displayermillis = millis();
        }
        if (_flag_init) {
            digitalWrite(_accPin, HIGH);
            _firstStop = millis();
            _flag_init = false;
            _flag_1 = true;
        }
        else if ((millis() - _firstStop >= 2000) && _flag_1) {
            digitalWrite(_revPin, HIGH);
            _secondStop = millis();
            _flag_1 = false;
            _flag_2 = true;
            _flag_process = true;
            _count ++;
        }
        else if ((millis() - _secondStop >= 12000) && _flag_2) {
            digitalWrite(_revPin, LOW);
            _thirdStop = millis();
            _flag_2 = false;
            _flag_3 = true;
        }
        else if ((millis() - _thirdStop >= 300) && _flag_3) {
            digitalWrite(_accPin, LOW);
            _forthStop = millis();
            _flag_3 = false;
            _flag_4 = true;
            _flag_process = false;
        }
        else if ((millis() - _forthStop >= 480000) && _flag_4) {
            digitalWrite(_accPin, HIGH);
            _firstStop = millis();
            _flag_4 = false;
            _flag_1 = true;
        }
    }
}

void DepthAutoTest::AOAOffline() {
    if (digitalRead(_swPin) == LOW || _flag_process == true) {
        if (millis() - _displayermillis >= 300){
            ssd1306.RippleAutoTest_counter(_count);
            _displayermillis = millis();
        }
        if (_flag_init) {
            digitalWrite(_accPin, HIGH);
            _firstStop = millis();
            _flag_init = false;
            _flag_1 = true;
        }
        else if ((millis() - _firstStop >= 12000) && _flag_1) {
            digitalWrite(_accPin, LOW);
            _secondStop = millis();
            _flag_1 = false;
            _flag_2 = true;
            _flag_process = true;
            _count ++;
        }
        else if ((millis() - _secondStop >= 67000) && _flag_2) {
            digitalWrite(_accPin, HIGH);
            _thirdStop = millis();
            _flag_2 = false;
            _flag_3 = true;
        }
        else if ((millis() - _thirdStop >= 2000) && _flag_3) {
            digitalWrite(_accPin, LOW);
            _forthStop = millis();
            _flag_3 = false;
            _flag_4 = true;
        }
        else if ((millis() - _forthStop >= 14000) && _flag_4) {
            digitalWrite(_accPin, HIGH);
            _firstStop = millis();
            _flag_4 = false;
            _flag_1 = true;
        }
    }
}
