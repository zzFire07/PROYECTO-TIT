//---- IMPORTACION DE LIBRERIAS ----//
#include "Adafruit_TCS34725.h"
#include <Servo.h>

//---- ASIGNANDO LOS SERVOS ----//
Servo servo_tolva;
Servo servo_varilla;
Servo servo_contenedor;

int pos = 0; // VARIABLE DE MOVIMIENTO DE LOS SERVOS VARILLA Y CONTENEDOR.
int open = 0; // MOVIMIENTO PARA ABRIR FLUJO DE TAPAS EN LA TOLVA
int close = 180; // MOVIMIENTO PARA CERRAR FLUJO DE TAPAS EN LA TOLVA

float grupo2 = 2; // "amarillo"
float grupo5 = 5; // "blanco"
float grupo6 = 6; // "gris"
float grupo7 = 7; // "negro"

int sensor = 0;
//---- VARIABLES CON LOS GRADOS PARA EL CORRESPONDIENTE CANASTO ----//
int grados_canasto_1 = 11;
int grados_canasto_2 = 33;
int grados_canasto_3 = 55;
int grados_canasto_4 = 77;
int grados_canasto_5 = 99;
int grados_canasto_6 = 121;
int grados_canasto_7 = 143;

//----- VARIABLES PARA CONTAR LAS TAPAS EN LOS CONTENEDORES ------//
int contador_tapas_1 = 0;
int contador_tapas_2 = 0;
int contador_tapas_3 = 0;
int contador_tapas_4 = 0;
int contador_tapas_5 = 0;
int contador_tapas_6 = 0;
int contador_tapas_7 = 0;
int contador_tapas_8 = 0;  // TAPAS NO CLASIFICADAS CORRECTAMENTE //

//----PIN Y FRECUENCIA DEL BUZZER----//
int pinBuzzer = 11; // ALARMA
int salida = 200;

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

//----ASIGNACION SERVOS----//
int pinservo_varilla = 10;
int cerogrados = 400;
int cientochentagrados = 2400;

int pinservo_contenedor = 3;
int cerogrados1 = 350;
int cientochentagrados1 = 2350;

void setup() {
  //--ASIGNO PIN A LED, BOTON Y MOTOR DC--//
  pinMode(13, OUTPUT); // LED ROJO
  pinMode(12, OUTPUT); // LED VERDE
  pinMode(10, OUTPUT); // BOTON
  pinMode(9, OUTPUT); // MOTOR DC
  
  //--ASIGNO PIN A LOS SERVOS--//
  servo_tolva.attach(1);
  servo_varilla.attach(pinservo_varilla, cerogrados, cientochentagrados);
  servo_contenedor.attach(pinservo_contenedor, cerogrados1, cientochentagrados1);
  
  //--INICIO TERMINAL SERIAL--//
  Serial.begin(9600);


}
void loop() {
  digitalWrite(12, HIGH);
  
  float red, green, blue;
  
  tcs.getRGB(&red, &green, &blue);
  
  uint32_t sum = (red+green+blue)/3;
  
  float r = red; r /= sum;
  int rojo = r*100;
  float g = green; g /= sum;
  int verde = g*100;
  float b = blue; b /= sum;
  int azul = b*100;
  
  Serial.print("R:\t"); Serial.print(rojo); 
  Serial.print("\tG:\t"); Serial.print(verde); 
  Serial.print("\tB:\t"); Serial.print(azul);
  Serial.println("");
        
//  }
  if ((rojo > 150 and rojo < 185) and (verde > 70 and verde < 100) and (azul > 35 and azul < 65)) {
    servo_tolva.write(open);
    delay(500);
    servo_tolva.write(close);
    delay(3000);
  }
    while ((rojo > 150 and rojo < 185) and (verde > 70 and verde < 100) and (azul > 35 and azul < 65)) {
      
        tcs.getRGB(&red, &green, &blue);
  
        uint32_t sum = (red+green+blue)/3;
        
        float r = red; r /= sum;
        int rojo = r*100;
        float g = green; g /= sum;
        int verde = g*100;
        float b = blue; b /= sum;
        int azul = b*100;d
        
        digitalWrite(13, HIGH);
        digitalWrite(12, LOW);
        analogWrite(pinBuzzer, salida);
        delay(90);
        analogWrite(pinBuzzer, 0);
        delay(90);
  }
  
  if ((rojo > 43 and rojo < 90) and (verde > 100 and g < 115) and (azul > 100 and azul < 160)) { // CHEQUEA COLOR AZUL
     for (pos = 0; pos <= grados_canasto_1; pos += 1) {
    servo_varilla.write(pos);    
    servo_contenedor.write(180-pos);
    delay(9);
      }
     int grados_contenedor = servo_contenedor.read();
     //servo_contenedor.write(#POSICION PARA QUE CAIGA EN EL CONTENEDOR#)//
     delay(600);
     servo_contenedor.write(180);
     servo_varilla.write(0);
     delay(800);
      contador_tapas_1 +=1;
      Serial.println("TAPITA AZUL CLASIFICADA");
  }
  if ((rojo > 50 and rojo < 100) and (verde > 130 and g < 180) and (azul > 65 and azul < 75)) { // CHEQUEA COLOR VERDE
     for (pos = 0; pos <= grados_canasto_2; pos += 1) {
    servo_varilla.write(pos);    
    servo_contenedor.write(180-pos);
    delay(9);
      }
     int grados_contenedor = servo_contenedor.read();
     //servo_contenedor.write(#POSICION PARA QUE CAIGA EN EL CONTENEDOR#)//
     delay(600);
     servo_contenedor.write(180);
     servo_varilla.write(0);
     delay(800);
      contador_tapas_2 +=1;
      Serial.println("TAPITA VERDE CLASIFICADA");
  }
  if ((rojo > 230 and rojo < 255) and (verde > 20 and g < 40) and (azul > 25 and azul < 35)) { // CHEQUEA COLOR ROJO
     for (pos = 0; pos <= grados_canasto_3; pos += 1) {
    servo_varilla.write(pos);    
    servo_contenedor.write(180-pos);
    delay(9);
      }
     int grados_contenedor = servo_contenedor.read();
     //servo_contenedor.write(#POSICION PARA QUE CAIGA EN EL CONTENEDOR#)//
     delay(600);
     servo_contenedor.write(180);
     servo_varilla.write(0);
     delay(800);
      contador_tapas_3 +=1;
      Serial.println("TAPITA ROJA CLASIFICADA");
  }
  if (sensor = grupo7) {
     for (pos = 0; pos <= grados_canasto_4; pos += 1) {
    servo_varilla.write(pos);    
    servo_contenedor.write(180-pos);
    delay(9);
      }
     int grados_contenedor = servo_contenedor.read();
     //servo_contenedor.write(#POSICION PARA QUE CAIGA EN EL CONTENEDOR#)//
     delay(600);
     servo_contenedor.write(180);
     servo_varilla.write(0);
     delay(800);
      contador_tapas_4 +=1;
  }
  if (sensor = grupo7) {
     for (pos = 0; pos <= grados_canasto_1; pos += 1) {
    servo_varilla.write(pos);    
    servo_contenedor.write(180-pos);
    delay(9);
      }
     int grados_contenedor = servo_contenedor.read();
     //servo_contenedor.write(#POSICION PARA QUE CAIGA EN EL CONTENEDOR#)//
     delay(600);
     servo_contenedor.write(180);
     servo_varilla.write(0);
     delay(800);
      contador_tapas_5 +=1;
  }
  if (sensor = grupo7) {
     for (pos = 0; pos <= grados_canasto_1; pos += 1) {
    servo_varilla.write(pos);    
    servo_contenedor.write(180-pos);
    delay(9);
      }
     int grados_contenedor = servo_contenedor.read();
     //servo_contenedor.write(#POSICION PARA QUE CAIGA EN EL CONTENEDOR#)//
     delay(600);
     servo_contenedor.write(180);
     servo_varilla.write(0);
     delay(800);
      contador_tapas_6 +=1;
  }
  if (sensor = grupo7) {
     for (pos = 0; pos <= grados_canasto_1; pos += 1) {
    servo_varilla.write(pos);    
    servo_contenedor.write(180-pos);
    delay(9);
      }
     int grados_contenedor = servo_contenedor.read();
     //servo_contenedor.write(#POSICION PARA QUE CAIGA EN EL CONTENEDOR#)//
     delay(600);
     servo_contenedor.write(180);
     servo_varilla.write(0);
     delay(800);
      contador_tapas_7 +=1;
  }
  else {
     //MOTOR PASO A PASO GIRA PARA EL OTRO SENTIDO//
     delay(400);
      contador_tapas_8 +=1;
  }
  if (contador_tapas_1 == 2000) {
      while (digitalRead(10) == LOW) {
          digitalWrite(13, HIGH);
          analogWrite(pinBuzzer, salida);
          delay(200);
          analogWrite(pinBuzzer, 0);
          delay(200);
          digitalWrite(12, LOW);
          }
      contador_tapas_1 = 0;
      }
   if (contador_tapas_2 == 2000) {
      while (digitalRead(10) == LOW) {
          digitalWrite(13, HIGH);
          analogWrite(pinBuzzer, salida);
          delay(200);
          analogWrite(pinBuzzer, 0);
          delay(200);
          digitalWrite(12, LOW);
          }
      contador_tapas_2 = 0;
      }
    if (contador_tapas_3 == 2000) {
      while (digitalRead(10) == LOW) {
          digitalWrite(13, HIGH);
          analogWrite(pinBuzzer, salida);
          delay(200);
          analogWrite(pinBuzzer, 0);
          delay(200);
          digitalWrite(12, LOW);
          }
      contador_tapas_3 = 0;
      }
    if (contador_tapas_4 == 2000) {
      while (digitalRead(10) == LOW) {
          digitalWrite(13, HIGH);
          analogWrite(pinBuzzer, salida);
          delay(200);
          analogWrite(pinBuzzer, 0);
          delay(200);
          digitalWrite(12, LOW);
          }
      contador_tapas_4 = 0;
      }
    if (contador_tapas_5 == 2000) {
      while (digitalRead(10) == LOW) {
          digitalWrite(13, HIGH);
          analogWrite(pinBuzzer, salida);
          delay(200);
          analogWrite(pinBuzzer, 0);
          delay(200);
          digitalWrite(12, LOW);
          }
      contador_tapas_5 = 0;
      }
    if (contador_tapas_6 == 2000) {
      while (digitalRead(10) == LOW) {
          digitalWrite(13, HIGH);
          analogWrite(pinBuzzer, salida);
          delay(200);
          analogWrite(pinBuzzer, 0);
          delay(200);
          digitalWrite(12, LOW);
          }
      contador_tapas_6 = 0;
      }
    if (contador_tapas_7 == 2000) {
      while (digitalRead(10) == LOW) {
          digitalWrite(13, HIGH);
          analogWrite(pinBuzzer, salida);
          delay(200);
          analogWrite(pinBuzzer, 0);
          delay(200);
          digitalWrite(12, LOW);
          }
      contador_tapas_7 = 0;
      }
    if (contador_tapas_8 == 2000) {
      while (digitalRead(10) == LOW) {
          digitalWrite(13, HIGH);
          analogWrite(pinBuzzer, salida);
          delay(200);
          analogWrite(pinBuzzer, 0);
          delay(200);
          digitalWrite(12, LOW);
          }
      contador_tapas_8 = 0;
      }
}
