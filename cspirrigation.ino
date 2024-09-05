 #include <SoftwareSerial.h>
 const int waterLevelPin = A0;
 const int relayPin = 8;
 SoftwareSerial bluetooth(10, 11);

 void setup() {
 pinMode(waterLevelPin, INPUT);
 pinMode(relayPin, OUTPUT);
 Serial.begin(9600);
 bluetooth.begin(9600);
 }
 void loop() {
 int waterLevel = analogRead(waterLevelPin);
 float inches = map(waterLevel, 0, 1023, 0, 12); // Adjust mapping based on sensor specs
 Serial.print("Water Level (inches): ");
 Serial.println(inches);
 // Check water level and send status to Bluetooth terminal
 if (inches < 4.0) {
 digitalWrite(relayPin, HIGH);
 Serial.print("Water pump is ON ");
 // Send status to mobile app indicating the water pump is ON
 bluetooth.println("Water Pump: ON");
 }
 else {
 digitalWrite(relayPin, LOW);
 Serial.print("Water pump is OFF");
 // Send status to mobile app indicating the water pump is OFF
 bluetooth.println("Water Pump: OFF");
 }
 delay(5000);
 }
