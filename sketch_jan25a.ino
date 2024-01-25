#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
DHT dht(DHTPIN, DHTTYPE);
int M,sensor_analog;
const int sensor_pin =34;

const char* ssid ="DESKTOP-IITC90J 2377";
const char* password ="zielxndaa";
#define CHAT_ID "1444762430"
#define BOTtoken "6398151720:AAEB52JiAzE8WfcVmMSUKxVF5phrguGrAw"

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);
int botRequestDelay = 1000;
unsigned log lastTimeBotRan;

void setup() {
  Serial.begin(115200);

  Serial.print("Connectin Wifi:");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  client.setCACert(TELEGRAM_CERTIFICATE_ROOT);
  Serial.println("");
  Serial.println("WiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIp());

  bot.sendMessage(CHAT_ID, "Tunggu dulu.. Monitoring akan segera dimulai", "");

  delay(2000);
  Serial.print("Workshop Monitoring Tanaman SMKn 7 Baleendah\n");
  dht.begin();

  
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
}


void loop() {
  sensor_analog = analogRead(sensor_pin);
  M = (100 - ((sensor_analog/4095.00)*100));
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if (isnan (h) || isnan (t) || isnan (M)) {
    Serial.println("Sensor Tidak tebaca!");
    return;
  }
  Serial.print("================Monitoring Tanaman================\n");
  Serial.print("kelembapan air tanah : ");
  Serial.print(M);
  Serial.print(" % \n");
  delay(2000); 
  Serial.print("Humiditas Gas Udara: ");
  Serial.print(h);
  Serial.println(" %");
  Serial.print("Suhu Udara sekarang: ");
  Serial.print(t);
  Serial.println(" °C");0
  delay(2000);
}




