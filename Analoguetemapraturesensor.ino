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
