#include <DHT.h>
#include <Adafruit_Sensor.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("CLEARDATA");
  Serial.println("LABEL,Time,Lum,Humid,Temp");
}

void loop() {
  int lum = analogRead(A0);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Serial.print("DATA,TIME");
  Serial.print(",");
  Serial.print(lum);
  Serial.print(",");
  Serial.print(h);
  Serial.print(",");
  Serial.println(t);
  
  delay(5000);
}
