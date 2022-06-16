#include <Servo.h>

Servo servo_tolva;
Servo servo_varilla;
Servo servo_contenedor;

int pos = 0;  
int open = 0;
int close = 180;
float grupo1 = 1; // "rojo"
float grupo2 = 2; // "amarillo"
float grupo3 = 3; // "azul"
float grupo4 = 4; // "verde"
float grupo5 = 5; // "blanco"
float grupo6 = 6; // "gris"
float grupo7 = 7; // "negro"
int sensor = 0;
int grados_canasto_1 = 11;
int grados_canasto_2 = 33;
int grados_canasto_3 = 55;
int grados_canasto_4 = 77;
int grados_canasto_5 = 99;
int grados_canasto_6 = 121;
int grados_canasto_7 = 143;
int grados_canasto_8 = 165;
int contador_tapas_1 = 0;
int contador_tapas_2 = 0;
int contador_tapas_3 = 0;
int contador_tapas_4 = 0;
int contador_tapas_5 = 0;
int contador_tapas_6 = 0;
int contador_tapas_7 = 0;
int contador_tapas_8 = 0;

void setup() {
  pinMode(13, OUTPUT); // LED ROJO
  pinMode(12, OUTPUT); // LED VERDE
  pinMode(11, OUTPUT); // ALARMA
  pinMode(10, OUTPUT); // BOTON
  servo_tolva.attach(1);
  servo_varilla.attach(2);
  servo_contenedor.attach(3);
}

void loop() {
digitalWrite(12, HIGH);
if (sensor == 0) {
    servo_tolva.write(open);
    delay(500);
    servo_tolva.write(close);
    delay(3000);
  }
    while (sensor == 0) {
        digitalWrite(13, HIGH);
        digitalWrite(12, LOW);
        analogWrite(11, 180);
        delay(90);
        analogWrite(pinBuzzer, 0);
        delay(90);
  }
  
  if (sensor = grupo1) {
     for (pos = 0; pos <= grados_canasto_1; pos += 1) {
         servo_varilla.write(pos);    
         servo_contenedor.write(180-pos);
         delay(8);
      }
      servo_contenedor.write(90-grados_canasto_1);
      delay(200);
      servo_contenedor.write(180);
      servo_varilla.write(0);
      contador_tapas_1 +=1;
  }
  if (sensor = grupo2) {
     for (pos = 0; pos <= grados_canasto_2; pos += 1) {
         servo_varilla.write(pos);    
         servo_contenedor.write(180-pos);
         delay(8);
      }
      servo_contenedor.write(90-grados_canasto_2);
      delay(200);
      servo_contenedor.write(180);
      servo_varilla.write(0);
      contador_tapas_2 +=1;
  }
  if (sensor = grupo3) {
     for (pos = 0; pos <= grados_canasto_3; pos += 1) {
         servo_varilla.write(pos);    
         servo_contenedor.write(180-pos);
         delay(8);
      }
      servo_contenedor.write(90-grados_canasto_3);
      delay(200);
      servo_contenedor.write(180);
      servo_varilla.write(0);
      contador_tapas_3 +=1;
  }
  if (sensor = grupo4) {
     for (pos = 0; pos <= grados_canasto_4; pos += 1) {
         servo_varilla.write(pos);    
         servo_contenedor.write(180-pos);
         delay(8);
      }
      servo_contenedor.write(90-grados_canasto_4);
      delay(200);
      servo_contenedor.write(180);
      servo_varilla.write(0);
      contador_tapas_4 +=1;
  }
  if (sensor = grupo5) {
     for (pos = 0; pos <= grados_canasto_5; pos += 1) {
         servo_varilla.write(pos);    
         servo_contenedor.write(180-pos);
         delay(8);
      }
      servo_contenedor.write(90-grados_canasto_5);
      delay(200);
      servo_contenedor.write(180);
      servo_varilla.write(0);
      contador_tapas_5 +=1;
  }
  if (sensor = grupo6) {
     for (pos = 0; pos <= grados_canasto_6; pos += 1) {
         servo_varilla.write(pos);    
         servo_contenedor.write(180-pos);
         delay(8);
      }
      servo_contenedor.write(90-grados_canasto_6);
      delay(200);
      servo_contenedor.write(180);
      servo_varilla.write(0);
      contador_tapas_6 +=1;
  }
  if (sensor = grupo7) {
     for (pos = 0; pos <= grados_canasto_7; pos += 1) {
         servo_varilla.write(pos);    
         servo_contenedor.write(180-pos);
         delay(8);
      }
      servo_contenedor.write(90-grados_canasto_7);
      delay(200);
      servo_contenedor.write(180);
      servo_varilla.write(0);
      contador_tapas_7 +=1;
  }
  else {
     for (pos = 0; pos <= grados_canasto_8; pos += 1) {
         servo_varilla.write(pos);    
         servo_contenedor.write(180-pos);
         delay(8);
      }
      servo_contenedor.write(90-grados_canasto_8);
      delay(200);
      servo_contenedor.write(180);
      servo_varilla.write(0);
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
