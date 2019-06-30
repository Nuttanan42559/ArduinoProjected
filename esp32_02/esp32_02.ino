#define Butt 16
int Btom;
void setup() {
  Serial.begin(9600);
  pinMode(18, OUTPUT);
}

void loop() {
  digitalWrite(18, HIGH);
  delay(1000);
  digitalWrite(18, LOW);
  delay(1000);
}
