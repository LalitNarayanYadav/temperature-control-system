# Component List – Temperature-Controlled Cooling System

This document lists all components required to build the Arduino-based Temperature Control System using DHT11, Fan PWM, Peltier, Relay, and MOSFET.

---

## Electronic Components

| Component | Quantity | Description |
|----------|----------|-------------|
| Arduino Mega / Uno | 1 | Main microcontroller board |
| DHT11 Sensor | 1 | Digital temperature & humidity sensor |
| 12V DC Fan | 1 | Cooling fan with PWM speed control |
| Peltier Module TEC1-12706 | 1 | Thermoelectric cooling unit |
| N-channel MOSFET (IRLZ44N / IRFZ44N) | 2 | Drives fan and Peltier |
| MOSFET Driver Module (optional) | 1 | For easier driving of inductive load |
| 10kΩ Potentiometer | 1 | Used for setting target temperature |
| Relay Module (5V or 12V) | 1 | Controls high power load |
| 220Ω resistor | 1 | Optional for indicator LED |
| Jumper wires | — | Male-male / male-female |
| Breadboard | 1 | Prototyping board |

---

## Power Components

| Component | Description |
|----------|-------------|
| LiPo Battery / 12V Adapter | Powers fan + Peltier |
| Heat Sink | Required for Peltier module |
| Small Fan for heatsink | Optional but recommended |

---

## Mechanical Items

- Breadboard  
- Cable ties  
- Thermal paste (for Peltier)  
- Heatsink mounting screws  

---

## Notes

- The Peltier module **must** be used with a heatsink.
- All grounds must be connected to form a **common ground**.
- Use MOSFETs rated for at least **30A** for safety.
