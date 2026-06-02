# Smart Home Environment & Safety Monitor

An embedded systems prototype designed for real-time environmental tracking and hazard detection. Built entirely in C++ using the Arduino microcontroller platform, this system acts as a localized smart-home hub, providing immediate visual feedback and audible alerts for fire or gas leaks.

## Key Features
* **Real-Time Hazard Detection:** Utilizes an MQ2 sensor to continuously monitor for dangerous levels of combustible gases and smoke.
* **Automated Alarm System:** Triggers a high-decibel piezo buzzer immediately upon crossing hazard thresholds.
* **Environmental Tracking:** Logs and displays ambient room temperature and relative humidity via a DHT11 sensor.
* **I2C LCD Interface:** Provides a clean, real-time visual readout of all sensor states using I2C communication to minimize wiring overhead.

## Hardware Architecture

![Project Schematic](Project%20Diagram.png)

* **Microcontroller:** Arduino Uno (ATmega328P)
* **Gas/Smoke Sensor:** MQ-2 Combustible Gas Sensor
* **Environment Sensor:** DHT11 Temperature & Humidity Sensor
* **Display:** 16x2 LCD Display with I2C Backpack
* **Actuator:** Active Piezo Buzzer

## Software & Libraries Used
The firmware is written in strict **C++** and leverages the following core libraries for hardware communication:
* `Wire.h` (For I2C communication)
* `LiquidCrystal_I2C.h` (For display rendering)
* `DHT.h` (For digital sensor parsing)

## Installation & Flashing
1. Clone this repository to your local machine.
2. Open `Sweet Home.ino` in the Arduino IDE.
3. Ensure the required libraries (`DHT sensor library` and `LiquidCrystal I2C`) are installed via the Library Manager.
4. Wire the components according to the diagram above.
5. Select your Arduino board and COM port, then click **Upload**.
