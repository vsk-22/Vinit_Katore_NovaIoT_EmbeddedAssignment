# FleetGuard Smart Environmental Monitoring System

## Industrial IoT Edge Device for Refrigerated Transport Containers

---

## Project Overview

FleetGuard Smart Environmental Monitoring System is an Industrial IoT edge device designed to continuously monitor environmental conditions inside refrigerated transport containers carrying temperature-sensitive products such as pharmaceuticals, vaccines, laboratory samples, and specialty chemicals.

The system continuously measures temperature and humidity, classifies operating conditions into Normal, Warning, and Critical states, generates local alerts, stores historical event logs, and is designed for future cloud integration using MQTT over Wi-Fi.

This project was developed as a proof-of-concept (PoC) for the FleetGuard Technologies Embedded Systems Assignment.

---

## Features

- Continuous Temperature Monitoring
- Continuous Humidity Monitoring
- Three-Level Condition Classification
  - Normal
  - Warning
  - Critical
- OLED Display for Live Status
- LED Status Indicators
- Audible Buzzer Alerts
- Local Event Logging
- Modular Firmware Architecture
- Expandable Hardware Design
- Future MQTT Cloud Integration
- Low-Cost ESP32-Based Architecture

---

## System Architecture

```
                  DHT22 Sensor
                       |
                       |
                    ESP32 MCU
        -------------------------------
       |        |        |             |
     OLED     LEDs    Buzzer      MicroSD
       |
   Future Wi-Fi
       |
    MQTT Cloud
```

---

## Hardware Components

| Component | Purpose |
|-----------|---------|
| ESP32 DevKit V1 | Main Controller |
| DHT22 | Temperature & Humidity Sensor |
| OLED Display (SSD1306) | Status Display |
| RGB LEDs | Status Indication |
| Active Buzzer | Audible Alarm |
| MicroSD Card Module | Event Storage |
| Push Button | Configuration |
| 5V Power Supply | System Power |

---

## Software Stack

- Arduino IDE
- Embedded C++
- ESP32 Board Package
- DHT Sensor Library
- Adafruit SSD1306 Library
- Adafruit GFX Library
- SPI Library
- SD Library
- Wire Library

---

## Project Structure

```
FleetGuard-IoT/
│
├── firmware/
│   ├── main.cpp
│   ├── sensors.cpp
│   ├── alerts.cpp
│   ├── logger.cpp
│   ├── display.cpp
│   └── config.cpp
│
├── hardware/
│   ├── block_diagram.png
│   ├── schematic.pdf
│   └── component_list.pdf
│
├── diagrams/
│   ├── system_architecture.png
│   ├── firmware_architecture.png
│   ├── flowchart.png
│   └── state_machine.png
│
├── reports/
│   ├── Engineering_Report.pdf
│   └── AI_Usage_Report.pdf
│
├── demo/
│   └── Demo.mp4
│
├── assets/
│
└── README.md
```

---

## Working Principle

1. ESP32 periodically reads temperature and humidity values from the DHT22 sensor.
2. Sensor readings are validated.
3. Values are compared against predefined thresholds.
4. The system classifies the operating condition.
5. OLED displays current values and status.
6. LEDs indicate system state.
7. Buzzer activates during critical conditions.
8. Events are stored locally for future analysis.
9. The architecture supports future MQTT cloud connectivity.

---

## Threshold Values

| Status | Temperature | Humidity |
|---------|-------------|----------|
| Normal | 2°C – 8°C | 40% – 60% |
| Warning | 0–2°C or 8–10°C | 30–40% or 60–70% |
| Critical | <0°C or >10°C | <30% or >70% |

---

## GPIO Connections

| Device | ESP32 GPIO |
|---------|------------|
| DHT22 Data | GPIO 4 |
| OLED SDA | GPIO 21 |
| OLED SCL | GPIO 22 |
| Green LED | GPIO 16 |
| Yellow LED | GPIO 17 |
| Red LED | GPIO 18 |
| Buzzer | GPIO 19 |
| MicroSD CS | GPIO 5 |

---

## Event Logging

The system records:

- Temperature
- Humidity
- Warning Events
- Critical Events
- Sensor Failure
- Power Restart
- Configuration Changes

---

## Future Improvements

- MQTT Integration
- AWS IoT Core
- Azure IoT Hub
- LoRaWAN Connectivity
- OTA Firmware Updates
- Mobile Dashboard
- GPS Tracking
- Battery Backup
- Door Monitoring
- Vibration Detection

---

## Advantages

- Low Cost
- Reliable
- Modular Design
- Easy Maintenance
- Energy Efficient
- Scalable Architecture
- Cloud Ready
- Suitable for Mass Deployment

---

## Assumptions

- Stable 5V DC power supply is available.
- DHT22 sensor provides valid readings within its operating range.
- Local event storage has sufficient capacity.
- Wi-Fi connectivity will be added in future deployments.

---

## Limitations

- Prototype monitors only temperature and humidity.
- Cloud integration is not implemented in this proof-of-concept.
- Battery backup is not included.
- Industrial-grade enclosure is outside the scope of this assignment.

---

## Build Instructions

1. Install Arduino IDE.
2. Install ESP32 Board Package.
3. Install the required libraries:
   - DHT Sensor Library
   - Adafruit SSD1306
   - Adafruit GFX
   - SD
   - SPI
4. Connect the hardware according to the schematic.
5. Open the project in Arduino IDE.
6. Select the ESP32 board and COM port.
7. Compile and upload the firmware.
8. Open the Serial Monitor to observe system logs.

---

## Author

**Name:** Vinit Katore

**Assignment:** Embedded Systems Engineering Assignment

**Organization:** FleetGuard Technologies (Case Study)

**Platform:** ESP32

**Year:** 2026

---

## License

This project was developed solely for educational and assessment purposes.
