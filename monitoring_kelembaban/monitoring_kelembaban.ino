int moister, sensor_analog;
const int sensor_pin = 34;

void setup() {
  Serial.begin(9600);
  delay(2000);
  Serial.print("Monitoring Tanaman\n");
}

void loop() {
  sensor_analog = analogRead(sensor_pin);
  moister = ( 100 - ( (sensor_analog/4095.00) * 100 ) );
  if (isnan(moister)) {
    Serial.print("Sensor tidak terbaca");
    return;
  }
  Serial.print("Kelembaban air tanah: ");
  Serial.print(moister);
  Serial.print(" %\n");
  delay(2000);
}