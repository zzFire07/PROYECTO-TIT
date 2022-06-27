#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 100
int giro_completo = 2048;

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 6, 7, 8, 9);

// the previous reading from the analog input
int previous = 0;

void setup() {
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(300);
}

void loop() {
  stepper.step(giro_completo);
  delay(100);
}
