int pin = 7; 
unsigned long time;
unsigned long sizeofpulse;
float distance;

void setup()
{
  pinMode(13, OUTPUT); //para el Led Azul
  pinMode(12, OUTPUT); //para el Led Verde
  pinMode(11, OUTPUT); //para el Led Amarillo
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
  
  if(distance > 60 && distance <= 80 ){
    digitalWrite(13, HIGH);   
  }else{
    digitalWrite(13, LOW);
    
    if(distance > 20 && distance <= 60 ){
      digitalWrite(12, HIGH);   
    }else{
      digitalWrite(12, LOW);
      
      if(distance <= 20 ){
        digitalWrite(11, HIGH);   
      }else{
        digitalWrite(11, LOW);
      }//Fin Amarillo
      
    }//Fin Verde
  
  }//Fin Azul
  delay(50);  
  
  Serial.print(" Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(100);
}
