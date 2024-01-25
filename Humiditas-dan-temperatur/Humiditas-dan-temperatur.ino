#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  delay(2000);
  Serial.print("Monitoring Tanaman:");
  dht.begin();
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if(isnan(h) || isnan(t)) {
    Serial.println("Sensor Tidak Terbaca!");
    return;
  }
  Serial.print("Humiditas gas udara: ");
  Serial.print(h);
  Serial.print(" %\n");
  Serial.print("Temperatur Linkungan: ");
  Serial.print(t);
  Serial.print(" C\n");
  delay(2000);
}
