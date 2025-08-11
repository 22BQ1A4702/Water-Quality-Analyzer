# 💧 Water Quality Analyzer using Arduino

## 📌 Overview
The **Water Quality Analyzer** is an IoT-based system that measures the turbidity (cloudiness) of water and displays the results on an **LCD display**.  
It uses a turbidity sensor connected to an **Arduino UNO** and is useful for **monitoring water quality** in real time for environmental and industrial applications.

---

## 🛠️ Features
- Measures water turbidity in **NTU (Nephelometric Turbidity Units)**.
- Displays real-time turbidity readings on a **16x2 LCD**.
- Compact and low-cost design.
- Can be integrated with IoT platforms for remote monitoring.

---

## 📷 Final Output
When everything is connected and the code is uploaded successfully, the LCD will show:
- **Turbidity Value** in NTU.
- Status messages like *"Water Clear"* or *"Water Turbid"* depending on quality.

---

## 🧩 Components Required
| Component            | Quantity |
|----------------------|----------|
| Arduino UNO          | 1        |
| Turbidity Sensor     | 1        |
| 16x2 LCD Display     | 1        |
| Potentiometer (10kΩ) | 1        |
| Breadboard           | 1        |
| Jumper Wires         | As needed |
| USB Cable            | 1        |

---

## ⚙️ Circuit Connections
1. **Turbidity Sensor**  
   - Signal Pin → Arduino **A0**  
   - VCC → **5V**  
   - GND → **GND**  

2. **LCD Display (16x2)**  
   - RS → Pin 2  
   - E → Pin 3  
   - D4 → Pin 4  
   - D5 → Pin 5  
   - D6 → Pin 6  
   - D7 → Pin 7  
   - VCC → **5V**  
   - GND → **GND**  
   - Potentiometer middle pin → **V0** of LCD (contrast control)
