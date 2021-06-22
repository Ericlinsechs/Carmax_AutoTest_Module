/*
 * Current monitor program
 *
 * Editor: Eric Lin
 * Date: 2021/06/16
 *
 * In this head file include two test functions Definition,
 * which are :
 * 1. 電流值檢測功能          --> CurrentMonitor_INA219()
 * 2. 連續紀錄10秒電流值功能  --> CurrentMonitor_INA219_10sec()
 *
 * Due to 連續紀錄10秒電流值功能 required to upload current data onto website,
 * it's necessary to CONNECT WIFI if you want to use this function.
 *
 * CAUTION:
 * Default current monitor max spec is 16V, 400mA,
 * if there is required, please uncomment the code in CurrentMonitor_initialize to up to 32v, 1A
 *
 */

#ifndef CURRENT_MONITOR_H
#define CURRENT_MONITOR_H

#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>
#include <Adafruit_INA219.h>
#include "Displayer_SSD1306.h"
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>

#define MAX_LENGTH  20
#define NUM_STRINGS 10
#define NUM_VALUE 10

/* Setting your wifi id and password here */
#define SSID "Galaxy Note20"
#define PASSWORD "12345678"

extern const char *ssid;
extern const char *password;

extern WiFiUDP ntpUDP;
extern NTPClient timeClient;

extern char daystamp_arr[NUM_STRINGS][MAX_LENGTH];
extern char timestamp_arr[NUM_STRINGS][MAX_LENGTH];
extern float current_mA_arr[NUM_VALUE];

extern String daystamp;
extern String timestamp;

extern WebServer server;

class WebPage {
private:
    String _formattedDate;
    Displayer_SSD1306 ssd1306;
public:
    WebPage();
    void WifiConnect();
    static void handleRoot();
    static void handleNotFound();
    static String SendHTML();
    void HTTPServer();
    void ServerClient();
    void AbsoluteTime();
};

class CurrentMonitor {
private:
    uint8_t _accPin, _revPin;
    uint8_t _buttonState;
    uint16_t monitorTriggerTimer = 200;
    uint16_t tenSectriggerTimer = 10000;
    String _daystamp;
    String _timestamp;
    float _shuntvoltage;
    float _busvoltage;
    float _current_mA;
    float _loadvoltage;
    float _power_mW;
    volatile unsigned long startMillis;
    volatile unsigned long currentMillis;
    Displayer_SSD1306 ssd1306;
    Adafruit_INA219 ina219;
    WebPage webpage;
public:
    CurrentMonitor();
    void CurrentMonitor_initialize(uint8_t accPin, uint8_t revPin);
    void CurrentMonitor_INA219();
    void CurrentMonitor_INA219_10sec();
};

#endif
