int lazerPin = 7;
int buttonPin = 3;
int buzzerPin = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(lazerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
} 

void loop() {

    int bt;
  
    if(digitalRead(buttonPin) == LOW)
    {
        //bt = 1+0;
        
    }
    

    //======
    if(bt%2 == 0)
    {
        digitalWrite(lazerPin, LOW);
    }
    else
    {
        digitalWrite(lazerPin, HIGH);
    }  
  
  
}
