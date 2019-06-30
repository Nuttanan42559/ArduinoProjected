#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define BLYNK_PRINT Serial
#define DHTPIN D1
#define DHTTYPE DHT22
#define Moisture D2
#define GY302 D3
  

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;


char auth[] = "161a1f66aca443c3856b48747d625d32";
char ssid[] = "SHA256";
char pass[] = "123456789";

void setup()
{
  Serial.begin(9600);    
  Blynk.begin(auth, ssid, pass, "blynk.honey.co.th", 8080);
  dht.begin();
}

void loop()
{
  Blynk.run();
  timer.run();
  contovirtual();
  delay(1000);
}

void contovirtual() {
    int humidity = dht.readHumidity();            
    int temp = dht.readTemperature();  
    Serial.print("Temp : ");
    Serial.println(temp);
    Serial.print("Humidity : ");
    Serial.println(humidity);       
    Blynk.virtualWrite(V2, humidity);               
    Blynk.virtualWrite(V3, temp);              
}


