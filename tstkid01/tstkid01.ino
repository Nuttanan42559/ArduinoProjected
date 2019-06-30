#define bt1 16
#define bt2 14
void setup() {
  Serial.begin(9600);
  pinMode(bt1, INPUT);
  pinMode(bt2, INPUT);

}

void loop() {
  int vale = digitalRead(bt1);
  if (vale == HIGH)
  {
    Serial.print("Touching..");
  }
  else if (vale == LOW)
  {
    Serial.print("No Touching..");
  }
  

}
