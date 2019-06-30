#define bt 8
#define li 11
void setup() {
   pinMode(bt, INPUT);
   pinMode(li, OUTPUT);

}

void loop() {
  if(digitalRead(bt) == HIGH)
  {
    if(digitalRead(bt) == LOW)
    {
      digitalWrite(li, LOW);
    }
  }
  if(digitalRead(bt) == HIGH)
  {
    if(digitalRead(bt) == LOW)
    {
      if(digitalRead(bt) == HIGH)
      {
        digitalWrite(li, HIGH);
      }
    }
    
  }

}
