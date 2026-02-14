#include <Arduino.h>
#include <max6675.h>

// Khai báo chân
int thermoSO = 19;
int thermoCS = 5;
int thermoSCK = 18;

// Khởi tạo đối tượng
MAX6675 thermocouple(thermoSCK, thermoCS, thermoSO);

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("MAX6675 test");
}

void loop() {
  float temperature = thermocouple.readCelsius();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  delay(1000);
}
