#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 15
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  float t = dht.readTemperature();  
  float h = dht.readHumidity();     

  if (isnan(t) || isnan(h)) {
    Serial.println("Loi cam bien!");
  } else {
    Serial.print("Nhiet do: ");
    Serial.print(t);
    Serial.print(" C | Do am: ");
    Serial.print(h);
    Serial.println(" %");
  }

  delay(1000);
}
