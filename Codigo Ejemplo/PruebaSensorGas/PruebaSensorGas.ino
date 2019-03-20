const int analogInPin = A0;  //El Pin Cero Analogo
const int ledPin = 13;       //Enciende el led de la tarjeta
int sensorValue = 0;         //Inicializa en cero las lecturas

void setup() {
  Serial.begin(9600); 
  pinMode(ledPin, OUTPUT);     
}

void loop() {

  sensorValue = analogRead(analogInPin);            

  if (sensorValue >= 750)
  {
    digitalWrite(ledPin, HIGH);   // sets the LED on
  }
  else
  {
    digitalWrite(ledPin, LOW);    // sets the LED off
  }

  Serial.print("sensor = " );                       
  Serial.println(sensorValue);     
  delay(100);                     
}
