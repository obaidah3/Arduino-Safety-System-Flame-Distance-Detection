#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pins
#define flamePin   10  // Flame sensor (D0)
#define ledPin      7  // LED pin
#define buzzerPin   8  // Buzzer pin

// HC-SR04 pins
#define trigPin     2
#define echoPin     3

// Danger distance threshold (cm)
const int DANGER_DIST = 200; // Large value for distance calculation only

void setup() {
  pinMode(flamePin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED initialization failed"));
    while (true);
  }

  // Show initial safe screen
  display.clearDisplay();
  drawSafeScreen();
  delay(1000);
}

void loop() {
  bool flameDetected = (digitalRead(flamePin) == HIGH);
  long dist = readDistance();  // Read distance

  if (flameDetected) {
    // Hazard state
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 2000);

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("Hazard! Flame detected!");
    display.print("Distance = ");
    display.print(dist);
    display.println(" cm");
    display.display();

    Serial.print("🔥 Hazard! Flame detected! Distance=");
    Serial.print(dist);
    Serial.println(" cm");
  } else {
    // Safe state
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);

    display.clearDisplay();
    drawSafeScreen();
  }

  delay(300);
}

// Calculate distance from HC-SR04
long readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

// Draw the Safe screen with a smiley face and "Safe" label
void drawSafeScreen() {
  display.drawCircle(64, 32, 30, SSD1306_WHITE);      // Head
  display.fillCircle(56, 24, 3, SSD1306_WHITE);       // Left eye
  display.fillCircle(72, 24, 3, SSD1306_WHITE);       // Right eye
  // Smiling mouth
  for (int x = 50; x <= 78; x += 4) {
    int y = 42 + (int)(4 * sin((x - 50) * PI / 28));
    display.drawPixel(x, y, SSD1306_WHITE);
  }
  // "Safe" text
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(44, 52);
  display.println("Safe");
  display.display();
}
