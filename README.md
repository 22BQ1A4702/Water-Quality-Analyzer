# 💧 Water Quality Analyzer using Arduino

## 📌 Overview
The **Water Quality Analyzer** is an Arduino-based system that measures the turbidity (cloudiness) of water in **NTU** (Nephelometric Turbidity Units) and displays the results on a **16x2 LCD display**.  
It uses a **turbidity sensor** connected to an Arduino UNO, making it a simple, low-cost tool for **real-time water quality monitoring** in domestic, industrial, and environmental applications.

---

## 🛠️ Features
- 📏 **Measures turbidity** in NTU (0–300 range).
- 📟 **LCD display** showing both numeric NTU values and water quality status.
- 🔍 **Automatic classification** of water cleanliness.
- 💡 Low-cost, easy-to-build, and compact design.
- 🌐 Can be extended for IoT/cloud monitoring.

---

## 🧩 Components Required
| Component           | Quantity |
|---------------------|----------|
| Arduino UNO         | 1        |
| Turbidity Sensor    | 1        |
| 16x2 LCD Display    | 1        |
| Potentiometer (10kΩ)| 1        |
| Breadboard          | 1        |
| Jumper Wires        | As needed |
| USB Cable           | 1        |

---

## ⚙️ Circuit Connections

### Turbidity Sensor
| Pin     | Arduino Pin |
|---------|-------------|
| Signal  | A0          |
| VCC     | 5V          |
| GND     | GND         |

### LCD Display (16x2)
| LCD Pin | Arduino Pin |
|---------|-------------|
| RS      | 12          |
| E       | 11          |
| D4      | 5           |
| D5      | 4           |
| D6      | 3           |
| D7      | 2           |
| VCC     | 5V          |
| GND     | GND         |
| V0      | Middle pin of Potentiometer |

---

## 📜 Arduino Code
Code is available in [`water_quality_analyzer.ino`](water_quality_analyzer.ino).

The **key logic**:
- Sensor reading is **limited to a max of 208** for calibration.
- NTU is mapped from **0–208 ADC reading → 300–0 NTU**.
- Water quality is classified as:

| NTU Value      | Water Quality Status      |
|----------------|---------------------------|
| ≥ 200          | Water Very Clean          |
| 150 – 199      | Water Clean               |
| 100 – 149      | Water Slightly Dirty      |
| 50 – 99        | Water Dirty               |
| < 50           | Water Very Dirty          |

---

## 📷 Output
When connected and running:
1. LCD shows **"Welcome To Turbidity Sensor"** for 3 seconds.
2. LCD displays **Turbidity: <value> NTU**.
3. LCD shows **Water Quality Status** based on NTU classification.

Example:
Turbidity: 298
Water Very Clean


🧪 How to Get the Output
Install Arduino IDE
Download from: https://www.arduino.cc/en/software

Connect Your Arduino
Use a USB cable to connect Arduino to your computer.

Upload the Code

Open Arduino IDE

Paste the code above

Select Tools → Board → Arduino Uno

Select Tools → Port → [Your Arduino Port]

Click Upload

Observe the LCD Output

The LCD will display NTU: <value>

If value ≤ 298 NTU, water is CLEAN

If value > 298 NTU, water is DIRTY

