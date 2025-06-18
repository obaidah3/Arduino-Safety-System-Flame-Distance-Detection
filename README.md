**🚀 ESP32 OLED & RGB LED Controller**

This project demonstrates how to control an SSD1306-based OLED display and a common-anode RGB LED with an ESP32. It features both physical and web-based interfaces:

* 🔘 **Physical button**: Cycles through predefined emoji-style faces on the OLED and changes the LED color to preset values.
* 🌐 **Web interface**: Access a simple HTML form to select a face and manually adjust the RGB channels.

---

## ✨ Features

1. 😀 **OLED display** shows six different faces (happy, sad, neutral, excited, angry, surprised).
2. 🎨 **RGB LED** color updates to match each face or custom values via web form.
3. 🔄 **Physical button** on pin 4 cycles through faces and colors (debounced).
4. 📶 **Wi‑Fi connectivity** in STA + SoftAP mode:

   * Tries to connect to your local network (SSID/PASSWORD).
   * If STA fails within 20 s, falls back to SoftAP (`ESP32_OLED_AP` / `12345678`).
5. 💻 **Web server** on port 80 with an HTML form:

   * Select face index (0–5).
   * Enter R, G, B values (0–255).

---

## 📦 Components Used

| Component            | Model                        | Pin Connections              | Datasheet / Reference                                                                                                                                                                                                                                                                     |
| -------------------- | ---------------------------- | ---------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| ✅ Microcontroller    | ESP32-WROOM-32               | —                            | [ESP32-WROOM-32 Datasheet](https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf)                                                                                                                                                                   |
| ✅ Microcontroller    | Arduino Uno R3               | —                            | [Uno R3 Technical Specs](https://docs.arduino.cc/hardware/uno-rev3)                                                                                                                                                                                                                       |
| 🔥 Flame Sensor      | 4-Pin Flame Detection Module | D0 ➝ Pin 10                  | [Typical Flame Sensor Datasheet](https://makerselectronics.com/product/flame-sensor-module-4-pin)                                                                                                                                                                                         |
| 📏 Ultrasonic Sensor | HC-SR04                      | TRIG ➝ Pin 2, ECHO ➝ Pin 3   | [HC-SR04 Datasheet PDF](https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf)                                                                                                                                                                                                 |
| 💡 OLED Display      | 0.96" 128x64 I2C Blue        | SDA ➝ GPIO 21, SCL ➝ GPIO 22 | [SSD1306 OLED Datasheet](https://cdn-shop.adafruit.com/datasheets/SSD1306.pdf)  <br> [Display Module Datasheet](https://s20f2fdae3465e2c6.jimcontent.com/download/version/1675361647/module/14737241229/name/OLED%204%20Pin%20128x64%20Display%20module%200.96%20inch%20blue%20color.pdf) |
| 🔔 Buzzer            | Standard Active Buzzer       | Pin 8                        | [Buzzer Datasheet](https://makerselectronics.com/product/magnetic-buzzer-12v-2-pin)                                                                                                                                                                                                       |
| 💡 LED               | Standard LED                 | Pin 7                        | [HW-479 RGB LED Module Datasheet](https://makerselectronics.com/product/hw-479-rgb-led-module)                                                                                                                                                                                            |

---

## 🔌 Hardware Requirements

* ESP32 development board (or Arduino Uno R3)
* SSD1306 128×64 I²C OLED display
* Common‑anode RGB LED
* Pushbutton (active‑LOW)
* 3 resistors for LED (e.g. 220 Ω each)
* Breadboard and jumper wires

---

## 📌 Pin Connections

| Signal           | ESP32 Pin | Component              |
| ---------------- | --------- | ---------------------- |
| OLED SDA         | GPIO 21   | SSD1306 SDA            |
| OLED SCL         | GPIO 22   | SSD1306 SCL            |
| RGB LED Common + | 3.3 V     | RGB LED anode          |
| Red cathode      | GPIO 25   | through 220 Ω resistor |
| Green cathode    | GPIO 26   | through 220 Ω resistor |
| Blue cathode     | GPIO 27   | through 220 Ω resistor |
| Button (to GND)  | GPIO 4    | with internal pull‑up  |
| Serial debug     | TX0/RX0   | USB Serial Monitor     |

> **Note:** The RGB LED is common‑anode; pins drive cathodes with `analogWrite()`.

---

## 📥 Software Dependencies

Install the following libraries in the Arduino IDE:

* [Adafruit SSD1306 Library](https://github.com/adafruit/Adafruit_SSD1306)
* [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)
* **WiFi** (included with ESP32 core)

---

## ⚙️ Configuration

1. Open the sketch in the Arduino IDE.
2. Update the Wi‑Fi credentials:

   ```cpp
   const char* ssid     = "<YOUR_SSID>";
   const char* password = "<YOUR_PASSWORD>";
   ```
3. (Optional) Change the SoftAP SSID and password if desired:

   ```cpp
   const char* ap_ssid  = "ESP32_OLED_AP";
   const char* ap_pass  = "12345678";
   ```
4. Verify board and port, then upload.

---

## 🚀 Usage

1. **Power up**: ESP32 boots, initializes OLED, attempts Wi‑Fi STA.
2. **Serial monitor** (115200 baud) shows:

   * `Connecting to WiFi...` dots until success or timeout
   * `Connected to STA, IP: 192.168.x.x` or
   * `STA failed, starting SoftAP` and SoftAP IP
3. **Physical control**:

   * Press button → cycles face (0–5) and updates LED color.
4. **Web control**:

   1. Browse to the ESP32’s IP in a browser (STA or AP IP).
   2. Use the form to choose a face or set custom R/G/B values.
   3. Submit → updates OLED and LED in real time.

---

## 🛠️ Customization

* **Add faces**: Implement new `drawXFace()` and extend `totalScreens` and `presetColors`.
* **Color presets**: Edit `presetColors` array to change default colors for each face.
* **Port changes**: Modify pin definitions at top.

---

## 📝 License

This project is released under the MIT License. See [LICENSE](LICENSE.md) for details.
