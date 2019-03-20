
int elPin = 2;                  //Numero de Pin que vamos a usar
int minimo;                     //Para calibrar las lecturas
int maximo;                     //Para calibrar las lecturas
int nivelLuz;
int nivelLuzAjustado;

void setup() {
 Serial.begin(9600); 
 nivelLuz=analogRead(elPin);  //Leemos de la Foto Celda
 minimo=nivelLuz-20;            //Fijamos el valor minimo
 maximo=nivelLuz;
}

void loop(){
 nivelLuz=analogRead(elPin);
 
 if(minimo>nivelLuz){
    minimo=nivelLuz;
 }
 if(maximo<nivelLuz){
    maximo=nivelLuz;
 }
 
 //Se ajusta el nivel de luz para que muestre un valor entre 0 y 100.
 nivelLuzAjustadovel = map(nivelLuz, minimo, maximo, 0, 100); 
 
 Serial.println(nivelLuzAjustado); 
 delay(1000);
}
