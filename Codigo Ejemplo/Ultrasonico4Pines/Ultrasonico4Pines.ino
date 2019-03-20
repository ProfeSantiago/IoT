#define trigPin 2 // Trigger Pin
#define echoPin 3 // Echo Pin
//#define LEDPin 13 // Onboard LED

int maximumRange = 300;   // Maximum range needed
int minimumRange = 0;     // Minimum range needed
long duration, distance;  // Duration used to calculate distance

void setup() {
 Serial.begin (115200);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 //pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
}

void loop() {
 //Serial.println("--");
 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);  
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calcula la distancia (cm) basada en la velocidad del sonido.
 distance = duration/58.2;
 
 if (distance >= maximumRange || distance <= minimumRange){
     Serial.println("-1"); // Negativo = Fuera de Rango
     //digitalWrite(LEDPin, HIGH); 
 }else {
     Serial.println(distance);
     //digitalWrite(LEDPin, LOW); //Apaga led porque leyo bien
 }
 
 delay(50);//Se detiene 50ms antes de leer otra vez.
}
