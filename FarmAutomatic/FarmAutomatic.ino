#include <Wire.h>  
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  

//#define soil 2
#define relay 5
void setup() {
  
  pinMode(relay, OUTPUT);
  
}


void loop() {
  int soil = analogRead(A0);
  
  if(soil > 500)
  {
    digitalWrite(relay, HIGH);
  }
  else if(soil < 270)
  {
    digitalWrite(relay, LOW);
  }
  
}
