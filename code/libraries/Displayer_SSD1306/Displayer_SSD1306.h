#ifndef DISPLAYER_SSD1306_H
#define DISPLAYER_SSD1306_H

#include <Arduino.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library.
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3C for 128x64, 0x3D for 128x32

class Displayer_SSD1306 {
private:
    uint16_t _count;
    float _current_mA;
    String _daystamp;
    String _timestamp;
public:
    Displayer_SSD1306();
    void DepthAutoTest_counter(uint16_t count);
    void RippleAutoTest_counter(uint16_t count);
    void AOAOffline_counter(uint16_t count);
    void CurrentMonitor_display(float current_mA, String daystamp, String timestamp);
};

#endif
