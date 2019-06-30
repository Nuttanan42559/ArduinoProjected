#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
int xPin = 2;
int yPin = 6;
int swPin = 8;
int buzzerPin = 12;


void setup() {
  // put your setup code here, to run once:
  lcd.begin(20,4);
  pinMode(yPin, INPUT);
  pinMode(xPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(buzzerPin, HIGH);
  if(digitalRead(yPin) == HIGH)
  {
    digitalWrite(buzzerPin, HIGH);
  }
  else
  {
    digitalWrite(buzzerPin, LOW);
  }

  //============================
  if(digitalRead(xPin) == HIGH)
  {
    digitalWrite(buzzerPin, HIGH);
  }
  else
  {
    digitalWrite(buzzerPin, LOW);
  }
  
  
  
  
}
