/*
 * Oled displayer ssd1306 program
 *
 * Editor: Eric Lin
 * Date: 2021/06/16
 *
 * In this head file have all definition of displayer.
 *
 *
 */

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
    uint8_t _countdown;
    uint16_t _count;
    bool _flag;
    uint8_t _stateFlag;
    byte _mode;
    float _current_mA;
    String _daystamp;
    String _timestamp;
    unsigned long countdownMillis;
    uint16_t countdownTimer = 10;
public:
    Displayer_SSD1306();
    void DepthAutoTest_counter(uint16_t count);
    void RippleAutoTest_counter(uint16_t count);
    void AOAOffline_counter(uint8_t stateFlag);
    void CurrentMonitor_display(float current_mA);
    void CurrentMonitor_10sec_display();
    void Initialization_setting(bool flag, uint8_t countdown);
    void WifiConnect();
    void Ready_interface();
};

#endif
