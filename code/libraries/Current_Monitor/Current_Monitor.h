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

#define SSID "debby"
#define PASSWORD "0910859186"

extern const char *ssid;
extern const char *password;

class Webpage {
private:
    String _formattedDate;
    WiFiUDP ntpUDP;
public:
    Webpage();
    void NetworkConnect();
    void AbsoluteTime();
    static void handleRoot();
    static void handleNotFound();
    static String SendHTML();
    void HTTPServer();
};

class CurrentMonitor {
private:
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
    Webpage webpage;
public:
    CurrentMonitor();
    void CurrentMonitor_INA219();
    void CurrentMonitor_INA219_10sec();
};

#endif
