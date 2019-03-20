int pirPin = 8;
int val;

void setup() {
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(pirPin); //read state of the PIR
  
  if (val == LOW) {
    Serial.println("No motion"); 
    digitalWrite(13, LOW);
  }
  else {
    Serial.println("Motion!"); 
    digitalWrite(13, HIGH);   
  }
  
  delay(1000);
}
