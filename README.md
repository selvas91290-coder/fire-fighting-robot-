# 🔥 Fire Fighting Robot using Arduino

## 📌 Project Overview

The Fire Fighting Robot is an autonomous robotic system designed to
detect a flame using flame sensors and automatically move toward the
fire location. Once the fire is detected, the robot stops and activates
a water pump to extinguish the fire.

The robot uses three flame sensors to detect fire from the right, front,
and left directions.

## 🎯 Objectives

- Detect fire using flame sensors
- Identify the direction of the fire
- Move the robot automatically
- Stop when fire is detected
- Activate a water pump
- Control the water direction using a servo motor
- Reduce the need for manual intervention

## 🛠️ Components Used

- Arduino
- Flame Sensors × 3
- L298N Motor Driver
- BO Motors
- Servo Motor
- Water Pump
- Robot Chassis
- Battery
- Jumper Wires

## 🔌 Pin Configuration

| Component | Arduino Pin |
|-----------|-------------|
| Motor ENA | D10 |
| Motor IN1 | D9 |
| Motor IN2 | D8 |
| Motor IN3 | D7 |
| Motor IN4 | D6 |
| Motor ENB | D5 |
| Right Flame Sensor | A0 |
| Front Flame Sensor | A1 |
| Left Flame Sensor | A2 |
| Servo | A4 |
| Water Pump | A5 |

## ⚙️ Working Principle

1. The three flame sensors continuously monitor the surroundings.
2. The Arduino reads the sensor values.
3. If a flame is detected on the right side, the robot stops.
4. If a flame is detected in front, the robot stops.
5. If a flame is detected on the left side, the robot stops.
6. The water pump is activated.
7. The servo motor sweeps the water toward the detected fire area.
8. If no fire is detected, the robot continues its movement logic.

## 🧠 Control Logic

### Right Flame
- Stop robot
- Turn ON pump
- Sweep servo toward right

### Front Flame
- Stop robot
- Turn ON pump
- Sweep servo across the fire area

### Left Flame
- Stop robot
- Turn ON pump
- Sweep servo toward left

## 💻 Software

- Arduino IDE
- Embedded C / Arduino C++

## 📂 Project Structure

```text
Fire-Fighting-Robot/
│
├── README.md
├── Arduino_Code/
│   └── Fire_Fighting_Robot.ino
├── PPT/
│   └── Fire_Fighting_Robot_Presentation.pptx
├── Images/
├── Circuit_Diagram/
└── Documentation/
    └── Project_Report.pdf
