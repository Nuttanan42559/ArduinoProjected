int pinred = 7;
void setup() {
  // put your setup code here, to run once:
  pinMode(pinred, OUTPUT);
  //digitalWrite(pinred, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
   digitalWrite(pinred, LOW);
   delay(1000);
    digitalWrite(pinred, HIGH);
}
