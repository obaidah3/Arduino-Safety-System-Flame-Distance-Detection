# 🔥 Arduino Safety System — Flame & Distance Detection 🚨

This project demonstrates an **embedded safety system** using an **Arduino Uno**, a **Flame Sensor**, an **HC-SR04 Ultrasonic Distance Sensor**, a **Buzzer**, an **LED**, and a **0.96" OLED Display**.  
The system detects flame hazards and measures distance, providing real-time alerts visually (OLED) and audibly (buzzer & LED).

---

## 🎥 Demo Video

[![Watch the Video](https://img.shields.io/badge/▶️%20Watch%20Live%20Video-blue?style=for-the-badge)](https://raw.githubusercontent.com/obaidah3/Arduino-Safety-System-Flame-Distance-Detection/main/Flame-Distance-Detection.mp4)

---

## 📦 **Components Used**

| Component | Model | Pin Connections | Datasheet / Reference |
|-----------|-------|-----------------|-----------------------|
| ✅ Microcontroller | [Arduino Uno R3](https://store.arduino.cc/products/arduino-uno-rev3) | — | [Uno R3 Technical Specs](https://docs.arduino.cc/hardware/uno-rev3) |
| 🔥 Flame Sensor | 4-Pin Flame Detection Module | D0 ➝ Pin 10 | [Typical Flame Sensor Datasheet](https://makerselectronics.com/product/flame-sensor-module-4-pin) |
| 📏 Ultrasonic Sensor | [HC-SR04](https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf) | TRIG ➝ Pin 2, ECHO ➝ Pin 3 | [HC-SR04 Datasheet PDF](https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf) |
| 💡 OLED Display | 0.96" 128x64 I2C Blue | SDA, SCL ➝ I2C Pins | [SSD1306 OLED Datasheet](https://cdn-shop.adafruit.com/datasheets/SSD1306.pdf) |
| 🔔 Buzzer | Standard Active Buzzer | Pin 8 | [Buzzer Datasheet](https://makerselectronics.com/product/magnetic-buzzer-12v-2-pin) |
| 💡 LED | Standard LED | Pin 7 | [HW-479 RGB LED Module Datasheet](https://makerselectronics.com/product/hw-479-rgb-led-module) |

---

## ⚙️ **How It Works**

- **Flame Sensor:** Detects flame presence. When flame is detected:
  - LED turns ON.
  - Buzzer activates with a tone.
  - OLED shows `Hazard! Flame detected!` + distance.

- **Ultrasonic Sensor (HC-SR04):** Continuously measures the distance to obstacles (shown on OLED).

- **OLED Display:** Shows a smiley face and `Safe` when no flame is detected. Updates dynamically when hazard occurs.

---

## 🔌 **Pin Configuration**

| Arduino Pin | Function |
|-------------|-------------------------------|
| `Pin 10` | Flame Sensor (D0) |
| `Pin 7` | LED |
| `Pin 8` | Buzzer |
| `Pin 2` | HC-SR04 Trigger |
| `Pin 3` | HC-SR04 Echo |
| `SDA`/`A4` | OLED I2C Data |
| `SCL`/`A5` | OLED I2C Clock |

---

## 🚀 **Usage Instructions**

1. Connect all modules according to the pin table.
2. Upload the provided `.ino` file using **Arduino IDE**.
3. Open **Serial Monitor** at `9600 baud` for debugging.
4. Observe:
   - If no flame: OLED shows smiley + `Safe`.
   - If flame detected: LED and buzzer alert, OLED shows `Hazard!` + distance.

---

## 📁 **Project File**

| File | Description |
|------|--------------|
| `SafetySystem.ino` | Main Arduino sketch. |
| `README.md` | Project documentation (this file). |

---

## 🔗 **Resources & Datasheets**

- [Arduino Uno R3](https://store.arduino.cc/products/arduino-uno-rev3)
- [Flame Sensor Module Datasheet](https://makerselectronics.com/product/magnetic-buzzer-12v-2-pin)
- [HC-SR04 Ultrasonic Sensor Datasheet](https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf)
- [SSD1306 OLED Datasheet](https://cdn-shop.adafruit.com/datasheets/SSD1306.pdf)
- [Adafruit SSD1306 Library](https://github.com/adafruit/Adafruit_SSD1306)
- [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)

---

## ✅ **Libraries Required**

Before uploading, install:
- `Adafruit GFX Library`
- `Adafruit SSD1306 Library`

These can be installed easily via **Arduino Library Manager**.

---

## 📷 **Preview**

| Safe Mode | Hazard Mode |
|-----------|--------------|
| 😊 `Safe` with smiley face | 🔥 `Hazard!` + Distance |

---

## 👤 **Author**

- **AbdulRahman Essam**
---

## ⚖️ **License**

This project is open-source and free to use for educational and non-commercial purposes.

---

## 🔑 **Keywords**

`Arduino Uno R3` · `Flame Sensor` · `HC-SR04` · `SSD1306 OLED` · `Fire Safety` · `Embedded Systems` · `Buzzer Alert` · `C++`

---

**Stay safe and have fun building! 🔧✨**
