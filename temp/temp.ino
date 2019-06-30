#include <DHT.h>
#include <Wire.h>  
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  
DHT dht;


void setup()
{
  Serial.begin(9600);
  lcd.begin(20, 4);
  lcd.setCursor(0,0);
  lcd.print("Status     :");
  lcd.setCursor(0,1);
  lcd.print("Humidity   :");
  lcd.setCursor(0,2);
  lcd.print("Temperature:");
  lcd.setCursor(0,3);
  lcd.print("Grade Temp :");   
  

  dht.setup(D2); // data pin 2
}

void loop()
{
  delay(dht.getMinimumSamplingPeriod());

  int humidity = dht.getHumidity(); // ดึงค่าความชื้น
  int temperature = dht.getTemperature(); // ดึงค่าอุณหภูมิ
  String grade;

  if(temperature >= 70)
  {
     lcd.setCursor(13,3);
     lcd.print("      ");
     delay(1000);
     grade = "Heat";
  }
  else if(temperature >= 50)
  { 
     lcd.setCursor(13,3);
     lcd.print("      ");
     delay(1000);
     grade = "High";
  }
  else if(temperature >= 40)
  {
     lcd.setCursor(13,3);
     lcd.print("      ");
     delay(1000);
     grade = "Medium";
  }
  else if(temperature >= 1)
  {
     lcd.setCursor(13,3);
     lcd.print("      ");
     delay(1000); 
     grade = "Low";
  }
  

  
  
  lcd.setCursor(13,0);
  lcd.print(dht.getStatusString());
  lcd.setCursor(13,1);
  lcd.print(humidity);
  lcd.setCursor(16,1);
  lcd.print("%");
  lcd.setCursor(13,2);
  lcd.print(temperature);
  lcd.setCursor(16,2);
  lcd.print("C'");
  //lcd.setCursor(13,3);
  //lcd.print(grade);
  Serial.println(temperature);
  

  
}

