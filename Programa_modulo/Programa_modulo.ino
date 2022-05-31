/*
 * Estructura básica
 * Por: Cristina Sánchez
 * Fecha: 08 de mayo de 2022
 * 
 * Esto es una muestra de la estructura básica de un programa
 */

// Bibliotecas
//#include <Serial.h>  // opcional

// Constantes

// Variables
int dato = 0;
double timeStart, timeFinish;

// Definición de objetos

// Condiciones iniciales - Se ejecuta sólo una vez al energizar

void setup() {//inicio de void setup
  //aqui ve tu codigo
  Serial.begin (115200); //iniciar comunicacion Serial
  Serial.println ("Comunicación Serial Iniciada");
  delay (1000);

}//Fin de void setup


//cuerpo de programa - se ejecuta constantemente
void loop() {//inicio de void loop
  // put your main code here, to run repeatedly:
  timeStart = micros();
  for (int i = 0; i < 1000; i++){
    dato++; //un solo ciclo de reloj

    if (dato > 8){ //reinicia el valor a 0
    dato = 0;
    }
  }
  timeFinish = micros();
  Serial.println ("con if");
  Serial.println (timeFinish - timeStart); //imprime valor del contador
  delay (10000);

  timeStart = micros();
  for (int i = 0; i < 1000; i++){
    dato++; //un solo ciclo de reloj
    if (dato > 8){ //reinicia el valor a 0
    dato = 0;
    dato %= 8;
    }
  }
  timeFinish = micros();
  Serial.println ("con operadores");
  Serial.println (timeFinish - timeStart); //imprime valor del contador
  delay (10000);

}// fin de void loop


/*void loop() {//inicio de void loop
  // put your main code here, to run repeatedly:
  
   
   //incremento
  //dato = dato +1; //varios ciclos de reloj
//  dato++; //un solo ciclo de reloj

//  if (dato > 8){ //reinicia el valor a 0
    dato = 0;
//  }

                 //dato %=8;  //limitado
                //dato =dato % 8;

 // int residuo = dato % 8;

  Serial.println (dato); //imprime valor del contador
  delay (1000);

}// fin de void loop*/
