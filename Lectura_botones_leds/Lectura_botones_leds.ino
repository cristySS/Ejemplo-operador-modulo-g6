/*
 * lectura de botones
 * Por: Cristina sanchez
 * Fecha: 13 de abril de 2022
 * 
 * este programa muestra las instrucciones basicas 
 * para la lectura de botones y el encendido de leds
 */

//Bibliotecas


//Constantes
const int BOTON1 = 4;
const int LED1 = 2; //ocupa un pin digital

//Varibles
int dato1;

//Definicion de objetos
 
//Condiciones iniciales - s ejecuta solo uan vez al energiar


void setup() { //inicio de void setup()
  // put your setup code here, to run once:
  pinMode (BOTON1, INPUT_PULLUP); //CONFIGURAR EL PIN DONDE SE ONnecta el pin
  pinMode (LED1, OUTPUT); //configurar el pin donde se conecta el eled   
  digitalWrite (LED1, LOW); // 0, false, LOW, 1, true, HIGH
  
}//fin de void setup


//cuerpo del programa- se ejecuta constantemenete
void loop() {
  // put your main code here, to run repeatedly:
  dato1 = digitalRead (BOTON1); //Leer el boton -lee lecura digital del pin
  // se presiono el boton se apague el led
  //pasaremos al led la lectura del boton
  digitalWrite (LED1, dato1);
  
}

//fin de void loop
