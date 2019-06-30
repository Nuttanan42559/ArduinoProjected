#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(20,4);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,1);
  lcd.print("TEXT");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("                    ");
  delay(100);
  lcd.setCursor(0,1);
  lcd.print(" TEXT");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("                    ");
  delay(100);
  lcd.setCursor(0,1);
  lcd.print("  TEXT");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("                    ");
  delay(100);
  lcd.setCursor(0,1);
  lcd.print("   TEXT");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("                    ");
  delay(100);
  lcd.setCursor(0,1);
  lcd.print("    TEXT");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("                    ");
  delay(100);
 
  
}
