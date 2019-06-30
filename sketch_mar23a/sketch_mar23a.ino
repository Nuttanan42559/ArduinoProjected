void setup() {
  Serial.begin(57600);
}

void loop() {
  Serial.print(analogRead(A0));
  Serial.print("\n"); 
  delay(500);
}
