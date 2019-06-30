int dta;
void setup() {
  Serial.begin(57600);
  pinMode(7, OUTPUT);

}

void loop() {
  if(Serial.available())
  { 
    dta = Serial.read();
  }
  else if(dta == '1')
  {
    digitalWrite(7, HIGH);
  }
  else if(dta == '0')
  {
    digitalWrite(7, LOW);
  }
  

}
