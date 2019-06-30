#include <Wire.h>  
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  

void setup()  
{
  lcd.begin(20,4);   
  lcd.setCursor(0,0);
  lcd.print("NUTTANAN JUNTAWONG");
  lcd.setCursor(0,1);
  lcd.print("M.4/2");
  lcd.setCursor(0,2);
  lcd.print("ST. NUM : 42559");
  lcd.setCursor(0,3);
  lcd.print("CL. NUM : 6");

}


void loop()   
{ 

}


