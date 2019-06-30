#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int SW_pin = 7; //digital pin connected to switch output
int X_pin = 2; //analog pin connected to x output
int Y_pin = 3; //analog pin connected to y output

void setup()
{
  lcd.begin(20,4);
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  //Serial.begin(115200);
}

void loop()
{
  int X = 0;
  int Y = 0;
  if(analogRead(X_pin) == 0)
  {
    lcd.setCursor(X+1,0);
    lcd.print(".");
  }
  else if(analogRead(X_pin) == 1016)
  {
    lcd.setCursor(X-1,0);
    lcd.print(".");
  }
  else if(analogRead(Y_pin) == 0)
  {
    lcd.setCursor(0,Y+1);
    lcd.print(".");
  }
  else if(analogRead(Y_pin) == 1016)
  {
    lcd.setCursor(0,Y-1);
    lcd.print(".");
  }
 
  
}
