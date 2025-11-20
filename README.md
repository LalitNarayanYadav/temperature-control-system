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
| Arduino Mega  | Main microcontroller board |
| DHT11 | Temperature & humidity sensor |
| 12V DC Fan (PWM-Controlled) | Cooling fan with variable speed |
| Peltier Module (TEC1-12706) | Thermoelectric cooler |
| N-channel MOSFET ( IRLZ44N) | Drives fan and Peltier |
| Relay Module (5V/12V) | Switches higher load devices |
| Potentiometer (10kΩ) | Adjusts set temperature |
| LiPo Battery / 12V Adapter | External power for actuators |
| Breadboard & wires | Hardware connections |
---

## Circuit Diagram (Textual Description)

### **DHT11 Sensor Wiring**
DHT11 VCC → 5V
DHT11 GND → GND
DHT11 DATA → D2

---

### **Potentiometer (Set Temperature Control)**
Left pin → 5V
Right pin → GND
Middle pin → A0 (analog input)

---

### **Fan PWM Wiring (via MOSFET)**
Fan + → 12V
Fan - → MOSFET Drain
MOSFET Source → GND
MOSFET Gate → D9 (PWM)

---

### **Peltier Module Wiring**
Peltier + → 12V
Peltier - → MOSFET Drain
MOSFET Gate → D10
GND → Common Ground

---

### **Relay Module**
Relay IN → D7
Relay VCC → 5V
Relay GND → GND
Load → Through relay terminal (NO/COM)

---


### ⚠ Important Notes
- Arduino GND and battery GND **must be common**  
- Do NOT power fan or Peltier directly from Arduino  
- Include diode protection for inductive loads  
- Use heatsinks with Peltier and MOSFET  

---

## Project Logic

1. **Potentiometer** sets the target temperature (e.g., range 20°C–40°C).  
2. **DHT11** reads temperature every 1 second.  
3. Fan speed is adjusted using PWM based on temperature difference.  
4. **Relay** activates/deactivates auxiliary cooling if temperature exceeds threshold (optional).  
5. **Peltier module** activates when temperature rises significantly above target.  
6. System prints all values in real time.

---

## PWM Control Logic

| Difference (Temp – SetTemp) | Fan PWM | Peltier | Relay |
|-----------------------------|---------|---------|--------|
| ≤ 0°C                       | 0%      | OFF     | OFF    |
| 0–1°C                       | 12%     | OFF     | OFF    |
| 1–2°C                       | 25%     | OFF     | OFF    |
| 2–3°C                       | 38%     | OFF     | ON     |
| > 3°C                        | 100%    | ON      | ON     |

---


## Real Serial Monitor Output


---

## Hardware Setup



---

## Code

The full Arduino code is available in:
temperature-control-system/code/temp_control_final.ino

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



