#include <Stepper.h>
#include "Potentiometer.h"

#define STEPS_PER_REV 200
#define REV_FRACTION 100
#define PIN_STEPPER_IN1 8
#define PIN_STEPPER_IN2 9
#define PIN_STEPPER_IN3 10
#define PIN_STEPPER_IN4 11

#define PIN_SPEED_POT A0
#define MAX_SPEED 100

Stepper stepper(STEPS_PER_REV, PIN_STEPPER_IN1, PIN_STEPPER_IN2, PIN_STEPPER_IN3, PIN_STEPPER_IN4);
Potentiometer speedPot(PIN_SPEED_POT, MAX_SPEED);

void setup()
{
  speedPot.begin();

  pinMode(PIN_STEPPER_IN1, OUTPUT);
  pinMode(PIN_STEPPER_IN2, OUTPUT);
  pinMode(PIN_STEPPER_IN3, OUTPUT);
  pinMode(PIN_STEPPER_IN4, OUTPUT);
}

void loop()
{
  stepper.setSpeed(speedPot.read());
  stepper.step(STEPS_PER_REV / REV_FRACTION);
}
