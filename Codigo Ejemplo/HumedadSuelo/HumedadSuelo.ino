int ASignal = A0;
 void setup() {
 Serial.begin(9600);
 }
 
 void loop() {
 int sensorValue = analogRead(ASignal);
 Serial.println(sensorValue);
 }
