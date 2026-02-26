#include <Arduino.h>
#include <max6675.h>

int pinSO = 19;
int pinCS = 5;
int pinSCK = 18;

MAX6675 cambien(pinSCK, pinCS, pinSO);

void setup() {
  Serial.begin(115200);
  delay(500);
}

void loop() {
  float temperature = cambien.readCelsius();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  delay(1000);
}
