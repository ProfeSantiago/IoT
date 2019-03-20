#include <dht.h> //Cargamos la libreria
dht DHT;         //Creamos una instancia de la libereria

#define elPin 5

void setup()
{
  Serial.begin(115200);  
}

void loop()
{
  Serial.print("DHT11, \t");
  int chk = DHT.read11(elPin);
    
  // Imprimimos en pantalla los valores
  Serial.print(DHT.humidity, 1);
  Serial.print(",\t");
  Serial.println(DHT.temperature, 1);

  delay(1000);
}
