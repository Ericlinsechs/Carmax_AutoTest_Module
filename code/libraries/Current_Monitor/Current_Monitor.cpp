#include "Current_Monitor.h"

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, 28800);

const char *ssid     = SSID;
const char *password = PASSWORD;

char daystamp_arr[NUM_STRINGS][MAX_LENGTH];
char timestamp_arr[NUM_STRINGS][MAX_LENGTH];
float current_mA_arr[NUM_VALUE];

String daystamp;
String timestamp;

WebServer server(80);

Webpage::Webpage() {}

void Webpage::NetworkConnect() {
    WiFi.begin(ssid, password);
    while ( WiFi.status() != WL_CONNECTED ) {
      delay ( 500 );
      Serial.print ( "." );
    }
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    timeClient.begin();
}

void Webpage::handleRoot() {
  server.send(200, "text/html", SendHTML());
}

void Webpage::handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

String Webpage::SendHTML() {
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta charset=\"utf-8\" />";
  ptr +="<meta http-equiv=\"refresh\" content=\"3\">";
  ptr +="<title>Eric Lin's Home Page</title>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";

    ptr +="<div id=\"webpage\">\n";
    ptr +="<h1>Current Monitor</h1>\n";
    ptr +="<div class=\"data\">\n";
    ptr +="<b class=\"data_topic\">Data: </b><br>\n";
    ptr +="<a class=\"data\">";
    for(int i=0;i<10;i++){
      ptr +=daystamp_arr[i];
      ptr +="&nbsp";
      ptr +=timestamp_arr[i];
      ptr +="&nbsp";
      ptr +=current_mA_arr[i];
      ptr +="mA";
      ptr +="&nbsp";
      ptr +="<br>";
    }
    ptr +="</a>\n";
    ptr +="</div>\n";
    ptr +="<div class=\"update\">\n";
    ptr +="<br><b class=\"updatetitle\">Last Update:</b>\n";
    ptr +="<div class=\"datestamp\"></div>";
    ptr +="<d class=\"date\">";
    ptr +=daystamp;
    ptr +="</d>\n";
    ptr +="<div class=\"timestamp\"></div>";
    ptr +="<t class=\"time\">";
    ptr +=timestamp;
    ptr +="</t>\n";

    ptr +="</div>\n";
    ptr +="</body>\n";
    ptr +="</html>\n";
  return ptr;
}

void Webpage::HTTPServer() {
    if (MDNS.begin("esp32")) {
        Serial.println("MDNS responder started");
    }
    server.on("/", Webpage::handleRoot);
    server.on("/inline", []() {
        server.send(200, "text/plain", "this works as well");
    });
    server.onNotFound(Webpage::handleNotFound);
    server.begin();
    Serial.println("HTTP server started");
}

void Webpage::AbsoluteTime() {
    timeClient.update();
    _formattedDate = timeClient.getFormattedDate();
    int splitT = _formattedDate.indexOf("T");
    daystamp = _formattedDate.substring(0, splitT);
    timestamp = timeClient.getFormattedTime();
}


CurrentMonitor::CurrentMonitor() {
    ina219.begin();
    // ina219.setCalibration_32V_1A();
    ina219.setCalibration_16V_400mA();
}

void CurrentMonitor::CurrentMonitor_INA219() {
    webpage.AbsoluteTime();
    _daystamp = daystamp;
    _timestamp = timestamp;
    _current_mA = ina219.getCurrent_mA();
    ssd1306.CurrentMonitor_display(_current_mA, _daystamp, _timestamp);
    /************************************************
    _shuntvoltage = ina219.getShuntVoltage_mV();
    _busvoltage = ina219.getBusVoltage_V();
    _power_mW = ina219.getPower_mW();
    _loadvoltage = busvoltage + (shuntvoltage / 1000);
    *************************************************/
}

void CurrentMonitor::CurrentMonitor_INA219_10sec() {
    for(int i=0; i<10; i++){
        startMillis = millis();
        currentMillis = millis();
        webpage.AbsoluteTime();
        _daystamp = daystamp;
        _timestamp = timestamp;
        strcpy(daystamp_arr[i], _daystamp.c_str());
        strcpy(timestamp_arr[i], _timestamp.c_str());
        current_mA_arr[i] = ina219.getCurrent_mA();
        // ssd1306.CurrentMonitor_display(_current_mA, _daystamp, _timestamp);
        Serial.print(daystamp_arr[i]);
        Serial.print(" ");
        Serial.print(timestamp_arr[i]);
        Serial.print(" ");
        Serial.print(current_mA_arr[i]);
        Serial.println("mA");
        if (i<10){
          while(currentMillis - startMillis < 1000)
            currentMillis = millis();
        }
        /************************************************
        _shuntvoltage = ina219.getShuntVoltage_mV();
        _busvoltage = ina219.getBusVoltage_V();
        _power_mW = ina219.getPower_mW();
        _loadvoltage = busvoltage + (shuntvoltage / 1000);
        *************************************************/
    }
    server.handleClient();
}
