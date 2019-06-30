int buzzer = 6;
int light = 9;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(light, OUTPUT);

}

void loop() {
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
  delay(1000);
  digitalWrite(light, HIGH);
  

}
