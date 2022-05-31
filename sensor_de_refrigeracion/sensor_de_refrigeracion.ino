//Librerias
#include "DHT.h"



//Constantes
//#define DHTPIN 4
#define DHTPIN 12
#define DHTTYPE DHT11   // DHT 11

const int BOTON1 = 14; //;//activara  la refirgreacion al ser presionado REFRIGERACION MANUAL
const int LED1 = 2; //ocupa un pin digital

const int BOTON2 = 15; //14;//activara la refrigeracion por ALTA DEMANDA
const int LED2 = 4; //15; //ocupa un pin digital

const int BOTON3 = 13;//activara cuando halla SOBRECARGA DE FUNCIONAMIENTO
//const int LED3 = 12; //ocupa un pin digital

const int NIVEL_TEMP = 28;

//Varibles
int dato1;
int dato2;
int dato3;
float t;

//Definicion de objetos
 
//Condiciones iniciales - s ejecuta solo uan vez al energiar
// Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);

void setup() { //inicio de void setup()
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  pinMode (BOTON1, INPUT_PULLUP); //CONFIGURAR EL PIN DONDE SE ONnecta el pin-activa refrigeracion al presionarlo
  pinMode (LED1, OUTPUT); //configurar el pin donde se conecta el led- refrigeracion manual
  digitalWrite (LED1, LOW); // 0, false, LOW, 1, true, HIGH
  
  pinMode (BOTON2, INPUT_PULLUP); //alta demanda
  pinMode (LED2, OUTPUT); //configurar el pin donde se conecta el led- refrigeracion automatica
  digitalWrite (LED2, LOW); // 0, false, LOW, 1, true, HIGH
  
  pinMode (BOTON3, INPUT_PULLUP); //sobrecarga de funcionamiento
// pinMode (LED3, OUTPUT); //configurar el pin donde se conecta el led- refrigeracion automatica
//  digitalWrite (LED3, LOW); // 0, false, LOW, 1, true, HIGH

  dht.begin();
  
}//fin de void setup

float lecturaDHT(){
  //  Read temperature as Celsius (the default)
  t = dht.readTemperature(); 
   //  Check if any reads failed and exit early (to try again).
  if (isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    //return;
  }

 //   Compute heat index in Celsius (isFahreheit = false)
 // float hic = dht.computeHeatIndex(t, false);
    Serial.println(t);
  //Serial.print(F("°C "));
  return (t);
}

void lecturaBotones(numero){
  if numero = 1 {
  dato1 = digitalRead (BOTON1); //Leer el boton -lee lecura digital del pin
  // se presiono el boton se apague el led
  //pasaremos al led la lectura del boton
  }
}

//cuerpo del programa- se ejecuta constantemente
// put your main code here, to run repeatedly:
void loop() {
  //   Wait a few seconds between measurements.
 delay(2000);

//   Reading temperature  takes about 250 milliseconds!
 //  Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  lecturaDHT();
  int numero_boton = 1;
  lecturaBotones(numero);
  
 
  if (dato1 == 1){ // digitalRead (BOTON1)){ 
     digitalWrite (LED1, HIGH);  //dato1);
     Serial.println("Refrigeracion manual ACTIVADA");
     return;
  }else{
    digitalWrite(LED1,LOW);
    dato2 == digitalRead (BOTON2);
    dato3 == digitalRead (BOTON3);
    if ((t > NIVEL_TEMP) || (dato2 == 1) || (dato3 == 1)){
       digitalWrite (LED2, HIGH);
       Serial.println("Refrigeracion AUTOMATICA ACTIVADA");
       return;
    }else{
        digitalWrite(LED2,LOW);
    } 
  }
  
/*  if (t > NIVEL_TEMP){
    digitalWrite (LED2, HIGH);
  }else{
    digitalWrite(LED2,LOW);
  }
*/
 

}
