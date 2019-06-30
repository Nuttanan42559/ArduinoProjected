int sensor = 8;
void setup() {
  // put your setup code here, to run once:
  pinMode(sensor,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(sensor,HIGH);
  delay(1000);
  digitalWrite(sensor,LOW);
  
}
