/*
 * Estructura básica
 * Por: Hugo Vargas
 * Fecha: 28 de junio de 2021
 * 
 * Esto es una muestra de la estructura básica de un programa
 */

// Bibliotecas
//#include <Serial.h>  // opcional

// Constantes

// Variables
int dato = 0;

// Definición de objetos

// Condiciones iniciales - Se ejecuta sólo una vez al energizar




void setup() {//inicio de void setup
  //aqui ve tu codigo
  Serial.begin (115200); //iniciar comunicacion Serial
  Serial.println ("Comunicación Serial Iniciada");
  delay (5000);

}//Fin de void setup


//cuerpo de programa - se ejecuta constantemente
void loop() {//inicio de void loop
  // put your main code here, to run repeatedly:

  //incremento
  //dato = dato +1;
  dato++;

  if (dato > 8){
    dato = 0;
  }

  //dato %=8;  //limitado
  //dato =dato % 8;

  int residuo = dato % 8;

}// fin de void loop
