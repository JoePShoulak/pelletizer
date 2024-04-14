#define ANALOG_MAX 1023

#include <Arduino.h>

class Potentiometer
{
public:
  Potentiometer(int pin, int min, int max);
  Potentiometer(int pin, int max);

  void begin();
  int read();

private:
  int _pin;
  int _min;
  int _max;
};

Potentiometer::Potentiometer(int pin, int max) : _pin(pin), _min(0), _max(max) {}
Potentiometer::Potentiometer(int pin, int min, int max) : _pin(pin), _min(min), _max(max) {}

void Potentiometer::begin()
{
  pinMode(_pin, INPUT);
}

int Potentiometer::read()
{
  int raw = analogRead(_pin);
  return map(raw, 0, ANALOG_MAX, _min, _max);
}
