# 自動化治具盒 Carmax Auto-test Module

This module is featured by conbining several test functions into one single box, the functions of it contains :
1. 深度測試功能
2. 布條紋測試功能
3. AOA斷線測試功能
4. 電流檢測功能
5. 連續紀錄10秒電流值功能

# How to use it

If you want to carry out tests immediately instead of editing the code or change the hardware, this part is fitting to you.

## Prerequisites

Before start using it, there are some stuffs you need to prepare.

- The components of the module include :
1. Auto-test module
2. 12V power cable (alligator clip)
3. Current monitor adapter
<p align="left">
  <img src="https://github.com/Ericlinsechs/Carmax_AutoTest_Module/blob/main/image/components.png" width="350" title="hover text">
</p>

- Some extra components are required :
1. USB outlet power adapter
2. USB to micro-USB cable
3. 12v power supplyer
<p align="left">
  <img src="https://github.com/Ericlinsechs/Carmax_AutoTest_Module/blob/main/image/required.png" width="350" title="hover text">
</p>

## Usage

### Getting Started
1. Connect 5v power cable to the module.
<p align="left">
  <img src="https://github.com/Ericlinsechs/Carmax_AutoTest_Module/blob/main/image/power_wire_connect.png" width="200" title="hover text">
</p>

2. Connect 12v power cable to power supplyer.
3. Once 5v power cable is connected, you would see the **welcome message** on the displayer on the box.
<p align="left">
  <img src="https://github.com/Ericlinsechs/Carmax_AutoTest_Module/blob/main/image/welcome.JPG" width="200" title="hover text">
</p>

4. After you press the button on the left side of the displayer, it would enter mode selecting process, choose which test function you want to run it.
<p align="left">
  <img src="https://github.com/Ericlinsechs/Carmax_AutoTest_Module/blob/main/image/mode_selecting.png" width="200" title="hover text">
</p>

5. When you finish your selecting, mode selecting process will be ended after 5 seconds (the countdown is on the bottom right side of the displayer).
6. Before the test is running, you would see the **ready to test** message.
<p align="left">
  <img src="https://github.com/Ericlinsechs/Carmax_AutoTest_Module/blob/main/image/ready_for_test.png" width="200" title="hover text">
</p>

7. Press the button again to start the test.

### Hardware Set Up

### **CAUTION**
- It's setting to be **non-stop** on each test function.
- If you desire a halt during the test, press the button between the time a test round is done and next one haven't start yet.
- Before function No.4 or No.5 is running, please make sure the voltage and current won't over the spec bellow :
  - **MAX voltage: 32v current: 1A (default)**
- Connecting Wifi is required when running the function No.5, default wifi setting is Samsung Galaxy Noto 20, if you want to change wifi, please check [current_monitor.h](https://github.com/Ericlinsechs/Carmax_AutoTest_Module/blob/main/code/Auto_Test_Box_code/libraries/Current_Monitor/Current_Monitor.h).

# Set Up (addition)
Only for code uploaded requirement would need to see this part.

## Prerequisites
- Copy this `git clone https://github.com/Ericlinsechs/Carmax_AutoTest_Module.git /.` to your terminal(cmd or so on) and exeuted.
- Download [ArduinoIDE](https://www.arduino.cc/en/software)
- Copy these [libraries](https://github.com/Ericlinsechs/Carmax_AutoTest_Module/tree/main/code/Auto_Test_Box_code/libraries) into this path(default)`C:\Users\[Username]\Documents\Arduino\libraries`
- Copy [auto_Test_Box_Program](https://github.com/Ericlinsechs/Carmax_AutoTest_Module/tree/main/code/Auto_Test_Box_code/Auto_Test_Box_Program) dir into this path(default)`C:\Users\[Username]\Documents\Arduino`
## Getting Started
