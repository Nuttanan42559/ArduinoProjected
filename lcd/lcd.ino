#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
void setup() {
  lcd.begin(20,4);
  lcd.setCursor(0,0);
  lcd.print("TEST");

}

void loop() {
  // put your main code here, to run repeatedly:

}
