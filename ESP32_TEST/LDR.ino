#include <Adafruit_LEDBackpack.h>

Adafruit_8x16minimatrix matrix = Adafruit_8x16minimatrix();

int LDRPin = 36;    // select the input pin for the potentiometer
int LDRValue = 0;  // variable to store the value coming from the sensor

void setup() {
  //Serial Port begin
  Serial.begin (9600);
  Wire.begin(21, 22, 100000);
  matrix.begin(0x70);
}

void loop() {
  // read the value from the sensor:
  LDRValue = analogRead(LDRPin);
  Serial.print(LDRValue,HEX);
  Serial.print(":");
  LDRValue = 99 - LDRValue * 0.0976;
  Serial.println(LDRValue,DEC);
  
  matrix.setRotation(1);
  matrix.clear();
  matrix.setCursor(0,0);
  matrix.print(LDRValue,DEC);
  matrix.writeDisplay();
  delay(100);
}
