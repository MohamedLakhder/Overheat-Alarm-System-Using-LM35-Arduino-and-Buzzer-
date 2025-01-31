# 🚀 Overheat Alarm System Using LM35, Arduino, and Buzzer

## 📌 Description
This project is a simple **temperature monitoring and alarm system** using an **LM35 analog temperature sensor, Arduino, LED indicators, and a buzzer**. It continuously measures the surrounding temperature and triggers an **alarm** when the temperature exceeds a set threshold (50°C).

## 🛠️ How It Works
- The **LM35 sensor** reads the ambient temperature and sends an **analog signal** to the Arduino.
- The Arduino processes the signal and converts it into **Celsius (°C)**.
- If the temperature is **below 50°C**:
  - ✅ **Green LED** turns **ON** (safe condition).
  - ❌ **Red LED & Buzzer** remain **OFF**.
- If the temperature **reaches or exceeds 50°C**:
  - 🚨 **Red LED & Buzzer** turn **ON** (alert mode).
  - ❌ **Green LED** turns **OFF**.
- The **temperature readings** are displayed on the **Serial Monitor**.

## 🔧 Components Required
- **Arduino Uno** (or any compatible board)
- **LM35 Temperature Sensor**
- **Buzzer** (for alarm)
- **Red LED** (alert indicator)
- **Green LED** (safe indicator)
- **Resistors (220Ω - for LEDs)**
- **Jumper Wires**
- **Breadboard**

## 📜 Code Overview
The Arduino reads the sensor data, checks the temperature threshold, and controls the LEDs and buzzer accordingly.

```cpp
#define ledgreen 2
#define ledred 3
#define buzzer 1
#define temperaturesensor A0

void setup() {
  pinMode(ledgreen, OUTPUT);
  pinMode(ledred, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(temperaturesensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  int valeurtemperaturesensor = analogRead(temperaturesensor);
  float voltage = valeurtemperaturesensor * (5.0 / 1023.0);
  float temperature = voltage * 100.0;

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  if (temperature >= 50) {  // Check if temp is high
    digitalWrite(ledred, HIGH);
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledgreen, LOW);
  } else {
    digitalWrite(ledred, LOW);
    digitalWrite(buzzer, LOW);
    digitalWrite(ledgreen, HIGH);
  }

  delay(1000); // Wait 1 second before next reading
}
