#include <Wire.h>  
#include <LiquidCrystal_I2C.h>
long numrand;
String state[] = {"=", "==", "===", "====", "=====", "======", "=======", "========", "=========", "=========="};
int i;


LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  
void setup() {
  // put your setup code here, to run once:
  lcd.begin(20,4);   

  for(i=0;i<=9;i++)
  {
    lcd.setCursor(0,3);
    lcd.print(state[i]);
    delay(500);
    lcd.setCursor(0,3);
    lcd.print(state[i]);
    delay(500);
    
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  numrand = random(99999999999);

  
  lcd.setCursor(0,0);
  lcd.print("  ");
  lcd.setCursor(2,0);
  lcd.print("AntMiner ASIC S9");
  lcd.setCursor(0,1);
  lcd.print("--------------------");
  lcd.setCursor(0,2);
  lcd.print("Select to Pool");
  lcd.setCursor(0,3);
  lcd.print("HASH => ");
  lcd.setCursor(8,3);
  lcd.print(numrand);
  
  
              
}
