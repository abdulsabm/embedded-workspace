# ESP32 ESP-IDF v5.5.5 – Quick Start

## 1. Open VS Code
    Open Visual Studio Code.
    Open the ESP32 project folder:
    \embedded-workspace\esp32\ESP32_ST7789_I80

## 2. Create a New Project
    Press: Ctrl + Shift + P
    Select: ESP-IDF: Create New Project
    Enter the project name.
        Example: esp_example_test
        Choose: \embedded-workspace\esp32
    The project will be created at: \embedded-workspace\esp32\esp_example_test

## 3. Open the Project
    In VS Code: File → Open Folder
    Select: \embedded-workspace\esp32\esp_example_test

## 4. Select ESP-IDF Version
    Press: Ctrl + Shift + P
    Select: ESP-IDF: Select Current ESP-IDF Version
    Choose: 5.5.5

## 5. Open ESP-IDF Terminal
    Press: Ctrl + Shift + P
    Select: ESP-IDF: Open ESP-IDF Terminal
    Check the version:
        ```powershell
        idf.py --version
    Expected: ESP-IDF v5.5.5

## 6. Set ESP32 Target
    For a normal ESP32: idf.py set-target esp32

## 7. Build the Project
    idf.py build
    If successful: Project build complete.

## 8. Connect ESP32
    Connect the ESP32 board to the PC using USB.
    Find the COM port from: Device Manager → Ports (COM & LPT)
    Example: COM5

## 9. Flash the ESP32
    idf.py -p COM5 flash
    Replace COM5 with your actual COM port.

## 10. Monitor Serial Output
    idf.py -p COM5 monitor
    To exit the monitor: Ctrl + ]

## 11. Build + Flash + Monitor
    The easiest command: idf.py -p COM5 flash monitor

## 12. Useful Commands         Command	Purpose
    idf.py --version	Check ESP-IDF version
    idf.py set-target esp32	Select ESP32
    idf.py menuconfig	Configure project
    idf.py build	Build project
    idf.py flash	Flash ESP32
    idf.py monitor	Open serial monitor
    idf.py flash monitor	Flash + monitor
    idf.py fullclean	Clean build files

## 13. Debugging
    Open: Run and Debug
    or press: Ctrl + Shift + D
    Use the ESP-IDF debugging configuration when available.

## 14. Important
    Always check: idf.py --version
    It should show: ESP-IDF v5.5.5