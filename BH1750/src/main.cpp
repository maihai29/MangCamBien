#include <Wire.h>
#include <BH1750.h>

BH1750 bh;

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);   
  bh.begin();
}

void loop() {
  Serial.print("Lux: ");
  Serial.println(bh.readLightLevel());
  delay(1000);
}
