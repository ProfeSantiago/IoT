 int PinMagnetico=2;       //connect tilt to D2
 int LED=13;
 int estado;
 
 void setup() {
     Serial.begin(9600);
     pinMode(LED, OUTPUT); 
     pinMode(PinMagnetico, INPUT);  
 }
 
 void loop() {
    estado = digitalRead(PinMagnetico);
  
     if(estado==HIGH)   //when the digital output value of tilt is high, turn on the LED.
     {
       digitalWrite(LED, HIGH); 
       Serial.println("Abierto");  
     }else{
       digitalWrite(LED, LOW);
       Serial.println("Cerrado");
     } 
 }
