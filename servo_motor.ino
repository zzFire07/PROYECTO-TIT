#include <Servo.h>

Servo servo_varilla;

int pinservo_varilla = 10;
int cerogrados = 400;
int cientochentagrados = 2400;

int pos = 0;

void setup() {
  servo_varilla.attach(pinservo_varilla, cerogrados, cientochentagrados);
}

void loop() {
       for (pos = 0; pos <= grados_canasto_1; pos += 1) {
    servo_varilla.write(pos);    
    delay(10);
       }
}
