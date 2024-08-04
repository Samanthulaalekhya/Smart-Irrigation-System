#include <SoftwareSerial.h>
SoftwareSerial bluetooth(10, 11); // RX, TX pins for Bluetooth module
int waterSensorPin = A0; // Analog pin for water level sensor

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  int waterLevel = analogRead(waterSensorPin);
  float inches = map(waterLevel, 0, 1023, 0, 12); // Adjust mapping based on sensor specs

  Serial.print("Water Level (inches): ");
  Serial.println(inches);

  bluetooth.print("Water Level: ");
  bluetooth.println(inches);

  delay(1000); // Adjust delay as needed
}