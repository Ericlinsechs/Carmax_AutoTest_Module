/*
 * Adafruit_SSD1306 oled displayer 128 x 64
 * Desired text size. 1 is default 6x8, 2 is 12x16, 3 is 18x24, etc
 */

#include "Displayer_SSD1306.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

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

void Displayer_SSD1306::AOAOffline_counter(uint16_t count) {
    _count = count;
    display.clearDisplay();
    display.setFont();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.print("AOA Offline Test");
    display.setTextSize(5);
    display.setCursor(0, 24);
    display.print(_count);
    display.display();
}

void Displayer_SSD1306::CurrentMonitor_display(float current_mA, String daystamp, String timestamp) {
    _current_mA = current_mA;
    _daystamp = daystamp;
    _timestamp = timestamp;
    display.clearDisplay();
    display.setFont();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.print("---Current monitor---");
    display.setCursor(0, 12);
    display.print(_daystamp);
    display.print(" ");
    display.print(_timestamp);
    display.setTextSize(3);
    display.setCursor(0, 40);
    display.print(_current_mA);
    display.setTextSize(1);
    display.setCursor(112, 56);
    display.print("mA");
    display.display();
}
