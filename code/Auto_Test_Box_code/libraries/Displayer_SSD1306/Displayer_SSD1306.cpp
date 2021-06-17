/*
 * Adafruit_SSD1306 oled displayer 128 x 64
 * Desired text size. 1 is default 6x8, 2 is 12x16, 3 is 18x24, etc
 */

#include "Displayer_SSD1306.h"
#include "Shift_Mode.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

/* Oled Displayer SSD1306 initialize */
Displayer_SSD1306::Displayer_SSD1306() {
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) { // Address 0x3D for 128x64
      for (;;); // Don't proceed, loop forever
    }
    // Clear the display.
    display.clearDisplay();
}

void Displayer_SSD1306::DepthAutoTest_counter(uint16_t count) {
    _count = count;
    display.clearDisplay();
    display.setFont();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.print("---Depth Auto Test---");
    display.setTextSize(5);
    display.setCursor(0, 24);
    display.print(_count);
    display.display();
}

void Displayer_SSD1306::RippleAutoTest_counter(uint16_t count) {
    _count = count;
    display.clearDisplay();
    display.setFont();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.print("Ripple Auto Test");
    display.setTextSize(5);
    display.setCursor(0, 24);
    display.print(_count);
    display.display();
}

void Displayer_SSD1306::AOAOffline_counter(uint8_t stateFlag) {
    _stateFlag = stateFlag;
    display.clearDisplay();
    display.setFont();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.print("AOA Offline Test");
    if (_stateFlag <= 4) {
        display.setCursor(0, 24);
        display.print("Testing......");
        display.setCursor(0, 36);
        if (_stateFlag == 1) {
            display.print("Wait for 12sec");
        }
        if (_stateFlag == 2) {
            display.print("Wait for 67sec");
        }
        if (_stateFlag == 3) {
            display.print("Wait for 2sec");
        }
        if (_stateFlag == 4) {
            display.print("Wait for 14sec");
        }
        display.display();
    }
    else if (_stateFlag == 5) {
        display.setCursor(0, 24);
        display.print("Press button to");
        display.setCursor(0, 36);
        display.print("continue...");
        display.display();
    }
}

void Displayer_SSD1306::CurrentMonitor_display(float current_mA) {
    _current_mA = current_mA;
    _daystamp = daystamp;
    _timestamp = timestamp;
    display.clearDisplay();
    display.setFont();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.print("---Current monitor---");
    display.setTextSize(3);
    display.setCursor(0, 40);
    display.print(_current_mA);
    display.setTextSize(1);
    display.setCursor(112, 56);
    display.print("mA");
    display.display();
}

void Displayer_SSD1306::CurrentMonitor_10sec_display() {
    display.clearDisplay();
    display.setFont();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.print("Current Monitor");
    display.setCursor(0, 12);
    display.print("10sec Mode");
    display.setCursor(0, 36);
    display.print("IP: ");
    display.print(WiFi.localIP());
    display.setCursor(0, 48);
    display.print("Uploading......");
    display.display();
}

void Displayer_SSD1306::welcome_message_displayer() {
    display.clearDisplay();
    display.setFont();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.print("Welcome to Carmax");
    display.setCursor(0, 12);
    display.print("Auto Test Program");
    display.setCursor(0, 36);
    display.print("Press the button");
    display.setCursor(0, 48);
    display.print("to select mode");
    display.display();
}

void Displayer_SSD1306::Initialization_setting(bool flag, uint8_t countdown) {
    _mode = mode;
    _flag = flag;
    _countdown = countdown;
    display.clearDisplay();
    display.setFont();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    if (!_flag) {
        display.setTextSize(1);
        display.setCursor(0, 24);
        display.print("Mode Select ended");
    }
    else {
        display.setCursor(0, 0);
        display.print("Mode Selecting:");
        display.setCursor(0, 24);
        switch(_mode) {
            case 0:
                display.print("Depth Auto Test");
                break;
            case 1:
                display.print("Ripple Auto Test");
                break;
            case 2:
                display.print("AOA Offline Test");
                break;
            case 3:
                display.print("Current Monitor Mode");
                break;
            case 4:
                display.print("Current Monitor");
                display.setCursor(0, 36);
                display.print(" 10sec Mode");
                break;
            default:
                display.print("Depth Auto Test");
        }
        if (millis() - countdownMillis >= countdownTimer) {
            countdownMillis = millis();
            display.setCursor(122, 56);
            display.print(_countdown);
        }
    }
    display.display();
}

void Displayer_SSD1306::WifiConnect() {
    display.clearDisplay();
    display.setFont();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.print("Current Monitor");
    display.setCursor(0, 12);
    display.print(" 10sec Mode");
    display.setCursor(0, 36);
    display.print("wifi connecting......");
    display.display();
}
void Displayer_SSD1306::Ready_interface() {
    _mode = mode;
    display.clearDisplay();
    display.setFont();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    switch(_mode) {
        case 0:
            display.print("Depth Auto Test");
            break;
        case 1:
            display.print("Ripple Auto Test");
            break;
        case 2:
            display.print("AOA Offline Test");
            break;
        case 3:
            display.print("Current Monitor Mode");
            break;
        case 4:
            display.print("Current Monitor");
            display.setCursor(0, 12);
            display.print(" 10sec Mode");
            break;
        default:
            display.print("Depth Auto Test");
    }
    display.setCursor(0, 24);
    display.print("Ready for test");
    display.setCursor(0, 36);
    display.print("Push the button");
    display.setCursor(0, 48);
    display.print("to start it...");
    display.display();
}
