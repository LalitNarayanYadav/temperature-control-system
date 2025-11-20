# Temperature-Controlled Cooling System using DHT11, Fan PWM & Peltier  
### FOSSEE Winter Internship 2025 – Arduino Screening Task  
**Author:** Lalit Narayan Yadav  

---

## Objective
To build a real-time temperature control system using an Arduino board, DHT11 temperature sensor, PWM-controlled cooling fan, and a Peltier module.  
The system monitors temperature continuously, adjusts fan speed dynamically, and activates the Peltier module when the temperature rises significantly above a set threshold.

This project demonstrates sensor–actuator integration, embedded programming, and real-time control exactly as required for the FOSSEE Arduino Internship Task 1.

---

## Components Used

| Component | Description |
|----------|-------------|
| Arduino Mega / Uno | Main microcontroller board |
| DHT11 | Temperature & humidity sensor |
| 12V DC Fan | Cooling fan with PWM speed control |
| Peltier Module (TEC1-12706) | Thermoelectric cooling module |
| N-channel MOSFET driver | To drive fan & Peltier safely |
| LiPo Battery / 12V Adapter | External power for fan + Peltier |
| Breadboard, jumper wires | Wiring setup |
| Diode (1N4007) | Back EMF protection for fan |

---

## Circuit Diagram (Textual Description)

### **DHT11 Sensor Wiring**
DHT11 VCC → 5V
DHT11 GND → GND
DHT11 DATA → D2

---

### **Fan PWM Wiring (via MOSFET)**
D9 (PWM) → MOSFET Gate
Fan + → External 12V
Fan - → MOSFET Drain → GND

---

### **Peltier Module Wiring**
D10 → MOSFET Gate
Peltier + → 12V
Peltier - → MOSFET Drain → GND

---


### Important Notes
- Common GND between Arduino and 12V supply  
- Use MOSFETs for high current loads  
- Do NOT power Peltier directly from Arduino  

---

## Project Logic

1. Read temperature from DHT11 every 1 second  
2. Compare with set temperature (e.g., 29°C)  
3. Adjust fan speed based on temperature difference  

| Condition | Fan PWM | Meaning |
|----------|---------|---------|
| Temp ≤ Set Temp | 0% | Off |
| Temp − Set ≤ 1°C | 12% | Low |
| Temp − Set ≤ 2°C | 25% | Medium |
| Temp − Set ≤ 3°C | 38% | High |
| Temp − Set > 3°C | 100% | Full speed |

4. If temperature rises 2°C above setpoint → Peltier ON  
5. Display real-time output on Serial Monitor  

---

## Real Serial Monitor Output



---

## Hardware Setup



---

## Code

The full Arduino code is available in:
/code/temp_control_final.ino

---

## Demo Video




---

## Results

- Real-time temperature monitoring  
- Automatic fan speed control based on temperature difference  
- Peltier cooling activation for high temperature  
- Demonstrates robust sensor–actuator integration  
- Fully working embedded cooling control system  

---

## Submission Info

Submitted as **Screening Task 1** for  
**FOSSEE Winter Internship 2025 (Arduino Team), IIT Bombay**.

---

## Acknowledgment

Thanks to the FOSSEE team for promoting open-source embedded systems learning and hands-on project development.



