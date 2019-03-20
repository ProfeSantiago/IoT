int pin = 7; 
unsigned long time;
unsigned long sizeofpulse;
float distance;

void setup()
{
  pinMode(13, OUTPUT); //para el Led
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH); 
}

void loop()
{
  pinMode(pin, OUTPUT); 
  digitalWrite(pin, LOW);
  delayMicroseconds(25);
  digitalWrite(pin, HIGH); 
  time = micros(); 
  pinMode(pin, INPUT); 
  sizeofpulse = pulseIn(pin, LOW, 18000); 
  time = micros() - time - sizeofpulse; 
  distance = (time*340.29/2/10000)-3; 
  
  if(distance <= 20){
    digitalWrite(13, HIGH);   
    delay(250);    
  }else{
    digitalWrite(13, LOW);
    delay(250); 
  }
  
  Serial.print(" Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(100);
}
