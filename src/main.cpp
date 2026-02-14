#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 15        // GPIO nối DATA
#define DHTTYPE DHT22   // Chọn DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("ESP32 + DHT22 start...");
  dht.begin();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // °C

  // Kiểm tra lỗi đọc
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println(" Không đọc được DHT22!");
  } else {
    Serial.print(" Nhiệt độ: ");
    Serial.print(temperature);
    Serial.print(" °C  |  Độ ẩm: ");
    Serial.print(humidity);
    Serial.println(" %");
  }

  delay(1000); // DHT22 đọc mỗi ≥2s
}
