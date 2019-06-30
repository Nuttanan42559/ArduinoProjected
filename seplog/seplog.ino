//-----------------------------------------------
//This sketch is combined from Adafruit DHT sensor and tdicola
//for dht.h library
//Along with some  esp8266 NodeMCU specifics from teos009    
// https://learn.adafruit.com/dht/overview
// https://gist.github.com/teos0009/acad7d1e54b97f4b2a88
//other Authors Arduino and associated Google Script:
//Aditya Riska Putra
//Ahmed Reza Rafsanzani
//Ryan Eko Saputro
//See Also
//http://jarkomdityaz.appspot.com/
//
//ELINS UGM
//
//Modified for Hackster.io project to the ESP8266 from
//a Ethernet Sheild project
//by Stephen Borsay
//Since Arduino can't handle https, we need to use Pushingbox API
//(uses http)to run 
//the Google Script (uses https).


#include "ESP8266WiFi.h"
#include "DHT.h"
#include <Wire.h>  
#include <LiquidCrystal_I2C.h>
#define DHTPIN 2    // what digital pin we're connected to
                    //pin2 to D4 on esp board

// Uncomment whatever DHT sensor type you're using!
#define DHTTYPE DHT11  // DHT 11
//#define DHTTYPE DHT21  // DHT 21
//#define DHTTYPE DHT22  // DHT 22


LiquidCrystal_I2C lcd(0x27, 20, 4);
DHT dht(DHTPIN,DHTTYPE);


const char WEBSITE[] = "api.pushingbox.com"; //pushingbox API server
const String devid = "v8F0DAEBB19AEABC"; //device ID from Pushingbox 

const char* MY_SSID = "SHA256";
const char* MY_PWD =  "123456789";


void setup()
{
  Serial.begin(115200);
  lcd.begin();
  Serial.print("Connecting to "+*MY_SSID);
  WiFi.begin(MY_SSID, MY_PWD);
  Serial.println("going into wl connect");

  while (WiFi.status() != WL_CONNECTED) //not connected,..waiting to connect
    {
      delay(1000);
      Serial.print(".");
    }
  Serial.println("wl connected");
  Serial.println("");
  Serial.println("Credentials accepted! Connected to wifi\n ");
  Serial.println("");

  //--------LCD-----------

  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Humidity :");
  lcd.setCursor(0,1);
  lcd.print("Cel      :");
  lcd.setCursor(0,2);
  lcd.print("Fehr     :");
  lcd.setCursor(0,3);
  lcd.print("Heat cel :");  

  dht.begin();
}


void loop()
{
  
  //Wait between measurements longer then normal to slow donwn
  //google sheet populate, as We dont want to exceed free service quota
  delay(600000); //10 seconds, (sampling rate vs. service call quota)

  float humidityData = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float celData = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float fehrData = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidityData) || isnan(celData) || isnan(fehrData))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Celsius (isFahreheit = false)
  float hicData = dht.computeHeatIndex(celData, humidityData, false);
  // Compute heat index in Fahrenheit (the default)
  float hifData = dht.computeHeatIndex(fehrData, humidityData);

  //Print to Serial monitor or Terminal of your chocice at 115200 Baud
  Serial.print("Humidity: ");
  Serial.print(humidityData);
  Serial.print(" %\t");
  Serial.print("Temperature in Cel: ");
  Serial.print(celData);
  Serial.print(" *C ");
  Serial.print("Temperature in Fehr: ");
  Serial.print(fehrData);
  Serial.print(" *F\t");
  Serial.print("Heat index in Cel: ");
  Serial.print(hicData);
  Serial.print(" *C ");
  Serial.print("Heat index in Fehr: ");
  Serial.print(hifData);
  Serial.print(" *F\n");

  //print screen lcd
  lcd.setCursor(12, 0); lcd.print(humidityData);
  lcd.setCursor(12, 1); lcd.print(celData);
  lcd.setCursor(12, 2); lcd.print(fehrData);
  lcd.setCursor(12, 3); lcd.print(hicData);
 
  WiFiClient client;  //Instantiate WiFi object

    //Start or API service using our WiFi Client through PushingBox
    if (client.connect(WEBSITE, 80))
      { 
         client.print("GET /pushingbox?devid=" + devid
       + "&humidityData=" + (String) humidityData
       + "&celData="      + (String) celData
       + "&fehrData="     + (String) fehrData
       + "&hicData="      + (String) hicData
       + "&hifData="      + (String) hifData
         );

      client.println(" HTTP/1.1"); 
      client.print("Host: ");
      client.println(WEBSITE);
      client.println("User-Agent: ESP8266/1.0");
      client.println("Connection: close");
      client.println();
      }
}
