int redpin = 11; // select the pin for the red LED
int bluepin = 10; // select the pin for the blue LED
int greenpin = 9; // select the pin for the green LED
int val=0;

void setup () {
  pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  Serial.begin(57600);
}
 
void loop () {
  for (val=255; val>0; val--)
  {
    analogWrite (redpin, val);
    delay(5);
    analogWrite (bluepin, 255-val);
    delay(5);
    analogWrite (greenpin, 128-val);
    delay(5);
  }
  delay(5);
  for (val = 0; val <255; val++)
  {
    analogWrite (redpin, val);
    delay(5);
    analogWrite (bluepin, 255-val);
    delay(5);
    analogWrite (greenpin, 128-val);
    delay(5);
  }
  Serial.println(val, DEC);
}
