#include <Servo.h>

Servo servo_tolva;
Servo servo_varilla;
Servo servo_contenedor;

int pos = 0;  
int open = 0;
int close = 180;

void setup() {
  servo_tolva.attach(1);
  servo_varilla.attach(2);
  servo_contenedor.attach(3);
}

void loop() {
  if sensor == nule {
    servo_tolva.write(open);
    delay(500)
    servo_tolva.write(close);
  }
  for (pos = 0; pos <= 180; pos += 1) {
    servo_varilla.write(pos);
    pos_invertida = pos * -1
    delay(8);     
    servo_contenedor.write(180-pos)
  }
}
