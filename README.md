Stationary Pad Segregator

Overview

The Smart Sanitary Pad Segregator and Disposal System is an Arduino-based automated solution designed for hygienic handling and disposal of used sanitary pads in institutional female washrooms such as schools, universities, and workplaces.

The system detects deposited sanitary pads, automatically segregates them, shreds them into smaller pieces, and then safely disposes of them through a controlled combustion process. It also includes monitoring and alert mechanisms to notify the system owner when the bin requires attention.

This project aims to improve sanitation, privacy, and waste management efficiency while reducing manual handling of sanitary waste.

Key Features

- Automatic Detection: Uses an ultrasonic sensor to detect when a sanitary pad is deposited.
- Automated Segregation: A motorized mechanism directs pads into the shredding unit.
- Shredding System: Pads are shredded to reduce volume and prepare them for combustion.
- Controlled Combustion: Nichrome wire heating element burns the shredded waste safely.
- Bin Level Monitoring: Sensors track waste accumulation levels.
- GSM Notifications: Sends SMS alerts to the owner when the bin is full or requires maintenance.
- Arduino-Based Control: All processes are managed through an Arduino microcontroller.
- Safety Mechanisms: Sequential processing ensures shredding occurs before combustion.

Hardware Components

- Arduino Uno / Compatible Microcontroller
- Ultrasonic Sensor (HC-SR04) – object detection
- DC Motor – shredding mechanism
- Motor Driver / Relay Module
- Nichrome Wire Heating Element – combustion
- GSM Module (SIM800/900) – SMS alerts
- ACS712 Current Sensor – monitor current during heating
- Step-down Voltage Regulator
- Power Supply Unit
- Structural housing and mechanical shredding assembly

System Workflow

1. Pad Detection – The ultrasonic sensor detects the presence of a sanitary pad.
2. Segregation – The pad is directed to the shredding compartment.
3. Shredding Process – The DC motor activates the shredding mechanism.
4. Sensor Verification – The system confirms that shredding is complete.
5. Combustion Stage – Nichrome wire heats up to burn the shredded material.
6. Monitoring and Alerts – The GSM module sends alerts if the bin becomes full or if maintenance is required.

Applications

- Schools and universities
- Public washrooms
- Hospitals and clinics
- Offices and workplaces
- Institutional sanitation facilities

Project Goals

- Improve menstrual hygiene management
- Reduce environmental contamination from sanitary waste
- Minimize human contact with sanitary waste
- Provide an affordable automated disposal solution for institutions

Future Improvements

- IoT monitoring and cloud-based alerts
- Temperature control for safer combustion
- Solar-powered operation
- Mobile application for remote monitoring
