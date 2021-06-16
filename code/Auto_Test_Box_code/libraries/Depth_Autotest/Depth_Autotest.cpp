#include "Depth_Autotest.h"
#include "Shift_Mode.h"

/* Definition of ACC and REV pin status */
DepthAutoTest::DepthAutoTest(uint8_t accPin, uint8_t revPin) {
    _accPin = accPin;
    _revPin = revPin;
    pinMode(_accPin, OUTPUT);
    pinMode(_revPin, OUTPUT);
    digitalWrite(_accPin, LOW);
    digitalWrite(_revPin, LOW);
}
/*******************
 DepthAutoTest
 Test step:
 1. Acc ON
 2. wait for 2sec
 3. Rev ON
 4. wait for 12sec
 5. Rec OFF
 6. wait for 0.3sec
 7. Acc OFF
 8. wait for 20.2sec
 ********************/
void DepthAutoTest::_DepthAutoTest() {
    _buttonState = buttonState;
    if (_buttonState >= 1 || _flag_process == true) {
        if (millis() - _displayermillis >= 300) {
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
    else
        ssd1306.Ready_interface();
}

/*******************
 RippleAutoTest
 Test step:
 1. Acc ON
 2. wait for 2sec
 3. Rev ON
 4. wait for 12sec
 5. Rec OFF
 6. wait for 0.3sec
 7. Acc OFF
 8. wait for 8min
 ********************/
void DepthAutoTest::RippleAutoTest() {
    _buttonState = buttonState;
    if (_buttonState >= 1 || _flag_process == true) {
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
    else
        ssd1306.Ready_interface();
}

/*******************
 AOAOffline
 Test step:
 1. Acc ON
 2. wait for 12sec
 3. Acc OFF
 4. wait for 67sec
 5. Acc ON
 6. wait for 2sec
 7. Acc OFF
 8. wait for 14sec
 9. Acc ON
 ********************/

void DepthAutoTest::AOAOffline() {
    _buttonState = buttonState;
    if (_buttonState >= 1 || _flag_process == true) {
        if (millis() - _displayermillis >= 300) {
            ssd1306.AOAOffline_counter(_stateFlag);
            _displayermillis = millis();
        }
        if (_flag_init) {
            digitalWrite(_accPin, HIGH);
            _firstStop = millis();
            _flag_init = false;
            _flag_1 = true;
            _flag_process = true;
            _stateFlag = 1;
        }
        else if ((millis() - _firstStop >= 12000) && _flag_1) {
            digitalWrite(_accPin, LOW);
            _secondStop = millis();
            _flag_1 = false;
            _flag_2 = true;
            _flag_process = true;
            _count ++;
            _stateFlag = 2;
        }
        else if ((millis() - _secondStop >= 67000) && _flag_2) {
            digitalWrite(_accPin, HIGH);
            _thirdStop = millis();
            _flag_2 = false;
            _flag_3 = true;
            _stateFlag = 3;
        }
        else if ((millis() - _thirdStop >= 2000) && _flag_3) {
            digitalWrite(_accPin, LOW);
            _forthStop = millis();
            _flag_3 = false;
            _flag_4 = true;
            _stateFlag = 4;
        }
        else if ((millis() - _forthStop >= 14000) && _flag_4) {
            digitalWrite(_accPin, HIGH);
            _lastButtonState = _buttonState;
            _stateFlag = 5;
            while(_buttonState == _lastButtonState) {
                _buttonState = buttonState;
                ssd1306.AOAOffline_counter(_stateFlag);
            };
            _firstStop = millis();
            _flag_4 = false;
            _flag_init = true;
            _flag_process = false;
        }
    }
    else
        ssd1306.Ready_interface();
}
