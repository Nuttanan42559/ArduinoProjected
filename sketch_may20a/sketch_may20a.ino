#include <DHT.h>
#include <Wire.h>  
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
// Uncomment one of the lines below for whatever DHT sensor type you're using!
//#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
#define DHTTYPE DHT11   // DHT 22  (AM2302), AM2321

// DHT Sensor
uint8_t DHTPin = D4; 
               
// Initialize DHT sensor.
DHT dht(DHTPin, DHTTYPE);                

int Temperature;
int Humidity;
 
void setup() {
  Serial.begin(115200);
  delay(100);
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  pinMode(DHTPin, INPUT);
  lcd.setCursor(0,0);
  lcd.print("Status     :");
  lcd.setCursor(0,1);
  lcd.print("Humidity   :");
  lcd.setCursor(0,2);
  lcd.print("Temperature:");
  lcd.setCursor(0,3);
  lcd.print("Grade Temp :");   

  dht.begin();            
}
void loop() {
  Temperature = dht.readTemperature(); 
  Humidity = dht.readHumidity();  
  lcd.setCursor(13,1);
  lcd.print(Humidity);
  lcd.setCursor(16,1);
  lcd.print("%");
  lcd.setCursor(13,2);
  lcd.print(Temperature);
  lcd.setCursor(16,2);
  lcd.print("C'");
}


