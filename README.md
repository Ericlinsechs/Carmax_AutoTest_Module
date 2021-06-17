# 自動化治具盒 Carmax AutoTest Module

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
1. Autotest module
2. 12V power cable (alligator clip)
3. Current monitor adapter

- Some extra components are required :
1. USB outlet power adapter
2. USB to micro-USB cable
3. 12v power supplyer

## Usage

### Getting Started
1. Connect 5v power cable to the module.
2. Connect 12v power cable to power supplyer.
3. Once 5v power cable is connected, you would see the welcome message on the displayer on the box.
<p align="center">
  <img src="https://github.com/Ericlinsechs/Carmax_AutoTest_Module/blob/main/image/IMG_8619.png" width="350" title="hover text">
</p>

5. After you press the button on the left side of the displayer, it would enter mode selecting process, choose which test function you want to run.
6. When you finish your selecting, mode selecting process will be ended after 5 seconds (the countdown is on the right down side of the displayer).
7. Before the test is running, you would see the **ready to test** message.
8. Press the button again to start the test.

### **CAUTION**
- It's setting to be **non-stop** on each test function.
- If you desire a halt during the test, press the button between the time a test round is done and next one haven't start yet.
- Before function No.4 or No.5 is running, please make sure the voltage and current won't over the spec bellow :
  - **MAX voltage: 32v current: 1A (default)**
- Connecting Wifi is required when running the function No.5, default wifi setting is Samsung Galaxy Noto 20, if you want to change wifi, please check **current_monitor.h**.
