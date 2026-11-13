# Touch-Based Device Control System for Bedridden Patients

**An ARM7 LPC2148-Based Embedded System | Embedded C | UART | SPI | EEPROM**

## 📌 Project Overview

The Touch-Based Device Control System for Bedridden Patients is an embedded systems project designed to assist individuals with limited mobility in controlling essential electrical devices with minimal physical effort.

The system is developed using the **LPC2148 ARM7 microcontroller** and a resistive touchscreen interface. It incorporates password-based authentication to ensure secure access and prevent unauthorized device operation.

The user can control connected devices through predefined touchscreen positions after successful authentication. An external AT25LC512 EEPROM is used to store and update passwords, while a buzzer provides an emergency alert facility.

## 🎯 Project Objectives

- Develop a user-friendly touch-based device control system.
- Enable bedridden patients to operate connected devices with minimal physical effort.
- Implement password-based authentication for secure access.
- Store and modify passwords using external EEPROM.
- Provide an emergency alert mechanism using a buzzer.
- Avoid unintended device operation through touchscreen activation and deactivation.

## ⚙️ System Architecture

The system integrates the following peripherals with the LPC2148 microcontroller:

<img width="689" height="454" alt="image" src="https://github.com/user-attachments/assets/64d0392f-0074-4622-9555-0aa09b65d566" />

## 🧩 Block Diagram

The following block diagram illustrates the overall architecture of the Touch-Based Device Control System using the LPC2148 ARM7 microcontroller.

<img width="657" height="604" alt="image" src="https://github.com/user-attachments/assets/60ebe5d2-72b3-497b-9d14-82e3792049f5" />

### Block Diagram Description

- **LPC2148 ARM7:** Acts as the central processing unit and controls all interfaced peripherals.
- **Touchscreen Module:** Sends touch coordinates to the microcontroller through UART communication.
- **4×4 Matrix Keypad:** Accepts password input and password modification commands.
- **16×2 LCD:** Displays system messages and user information.
- **AT25LC512 EEPROM:** Stores and retrieves the authentication password through SPI communication.
- **LED 1 and LED 2:** Represent the connected devices and indicate their ON/OFF status.
- **Buzzer:** Provides an emergency alert.



## 🛠️ Hardware Requirements

- LPC2148 ARM7 Microcontroller
- Resistive Touchscreen Module
- 16×2 LCD Display
- 4×4 Matrix Keypad
- AT25LC512 SPI EEPROM
- LEDs (Device 1 and Device 2)
- Buzzer
- Required power supply and interfacing connections

## 💻 Software Requirements

- Embedded C
- Keil µVision IDE
- Flash Magic

## 🔌 Communication Protocols & Embedded Concepts

<img width="646" height="391" alt="image" src="https://github.com/user-attachments/assets/1374be2b-6a74-4d3a-80ea-cc691713df31" />


## 🔄 Working Principle

**1. Password Authentication**

The system initially waits for the user to enter a password through the 4×4 matrix keypad. The entered password is validated against the password stored in EEPROM.

**2. Touchscreen Activation**

After successful authentication, the touchscreen interface is activated to allow the user to control connected devices.

**3. Device Control**

The touchscreen is configured with predefined control positions. Based on the detected touch coordinates, the system switches Device 1 and Device 2 ON or OFF.

**4. Password Management**

The user/admin can modify the existing password. The updated password is stored in the AT25LC512 EEPROM for future authentication.

**5. Emergency Alert**

A buzzer is incorporated to provide an emergency alert when assistance is required.

**6. Touchscreen Deactivation**

The touchscreen can be disabled after completing the operation to prevent accidental or unwanted device control.

## ⭐ Key Features

- Password-protected device access
- Touchscreen-based device operation
- EEPROM-based password storage
- Password modification functionality
- UART-based touchscreen interfacing
- SPI-based EEPROM communication
- LCD and keypad interfacing
- Emergency buzzer alert
- Device ON/OFF control


## 📚 Technical Skills Gained

Through this project, I gained hands-on experience in:

- ARM7 LPC2148 microcontroller programming.
- Embedded C application development.
- UART and SPI communication protocols.
- Touchscreen interfacing and coordinate processing.
- EEPROM data storage and retrieval.
- LCD and matrix keypad interfacing.
- GPIO configuration and peripheral control.
- Interrupt handling and embedded debugging.

## 🚀 Future Enhancements

- Integration of real electrical appliances using relay modules.
- Wireless device monitoring and control.
- Mobile application integration.
- Voice-controlled device operation.
- Remote emergency notifications to caregivers.

## 👨‍💻 Project Information

<img width="733" height="457" alt="image" src="https://github.com/user-attachments/assets/fdccaf31-b16a-414c-bba1-febbce9e09ce" />


**Developed as an Embedded Systems Project**

**Domain:** Embedded Systems | Firmware Development | ARM7 Microcontrollers

