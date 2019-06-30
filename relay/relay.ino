 #define R 11
#define LS 7
#define L 12
char test ; 



void setup() 
{
    // Open serial communications and wait for port to open:
    Serial.begin(57600);
    pinMode(L, OUTPUT);
    pinMode(R, OUTPUT); // ก
    pinMode(LS, INPUT);
}
    
void loop() // run over and over
{
    if (Serial.available()) // ตรวจสอบว่ามีข้อมูลเข้ามาหรือไม่
    test = Serial.read();
    else if (test == '1') // ถ้าข้อมูลที่เข้ามาคือ 1, 2, 3 ให้ทำงานตามที่กำหนด
{
    digitalWrite(R, LOW);
    
    
}   
else if(test == '2')
{
    digitalWrite(R, HIGH);
    
}
else if (test == '3')
{
    digitalWrite(R, LOW);
    
    delay(1000);
    
    delay(1000);
    digitalWrite(R, HIGH);
    
    delay(1000);
    
    delay(1000);
    
}
else if (test == '4')
{
    if(digitalRead(LS) == HIGH)
    {
      digitalWrite(R, LOW);
    }
    else if(digitalRead(LS) == LOW)
    {
      digitalWrite(R, HIGH);
    }
}
}

