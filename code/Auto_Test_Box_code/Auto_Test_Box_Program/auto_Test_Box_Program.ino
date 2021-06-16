/*
 * Auto Test Box Program
 * Editor: Eric Lin 
 * Date: 2021/06/16
 * 
 * The auto-test box is a multi-function test tool,
 * The multi-function including:
 * 1. 深度測試
 * 2. 布條紋測試
 * 3. AOA斷線測試
 * 4. 電流值檢測功能
 * 5. 連續紀錄10秒電流值功能
 * Through press the button to decide which test would you like to execute.
 * Also, it's really flexible to combine other new test function if needed.
 * 
 */

#include <Arduino.h>
#include "Depth_Autotest.h"
#include "Displayer_SSD1306.h"
#include "Current_Monitor.h"
#include "Shift_Mode.h"
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"

#define ACCPIN 15
#define REVPIN 2
#define BUTTONPIN 4
#define DEBOUNCE_TIME 250
volatile uint32_t DebounceTimer = 0;

/* Pin to which the button, PIR motion detector or radar is connected */
uint8_t button_count = 1;

bool flag;
byte _mode;

DepthAutoTest depthautotest(ACCPIN, REVPIN);  // DepthAutoTest initialize
CurrentMonitor currentmonitor;
Displayer_SSD1306 ssd1306;
WebPage webpage;
ShiftMode shiftmode;

/* Interrupt function, if interrupt is trigger, this func would be executed*/
void IRAM_ATTR buttonpressed() {
  if ( millis() - DEBOUNCE_TIME  >= DebounceTimer ) {          // Preventing debounce of button
    DebounceTimer = millis();
    shiftmode.button_function(button_count);
  }
}

void setup() {
    WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);                 // Disable brownout detector
    Serial.begin(115200); 
    currentmonitor.CurrentMonitor_initialize(ACCPIN, REVPIN);  // CurrentMonitor initialize
    Displayer_SSD1306();                                       // Oled Displayer SSD1306 initialize
    pinMode(BUTTONPIN, INPUT_PULLUP);
    attachInterrupt(BUTTONPIN, buttonpressed, FALLING);        // Setting button as a interrupt trigger
    _mode = shiftmode._ShiftMode(ACCPIN, REVPIN);              // Entering mode selecting 
}

void loop() {
  /* Depend on the value of _mode, different test function would be selected */
  /* 深度測試 */
  if (_mode == 0) {
    while(1)
      depthautotest._DepthAutoTest();
  }
  /* 布條紋測試 */
  if (_mode == 1) {
    while(1)
      depthautotest.RippleAutoTest();
  }
  /* AOA斷線測試 */
  if (_mode == 2) {
    while(1)
      depthautotest.AOAOffline();
  }
  /* 電流值檢測功能 */
  if (_mode == 3) {
    while(1)
      currentmonitor.CurrentMonitor_INA219();
  }
  /* 連續紀錄10秒電流值功能 */
  if (_mode == 4) {
    while(1) {
      currentmonitor.CurrentMonitor_INA219_10sec();
      webpage.ServerClient();
    }
  }
}
