#include <SoftwareSerial.h>

SoftwareSerial chat(D5, D6); // RX, TX

String a;

void setup() {

  Serial.begin(9600);

  chat.begin(57600);

 

  delay(10);

}

void loop() {

Serial.println("Please wait Serial..");

  while (a == "") {

    chat.write("Question1"); // ส่งหัวข้อคำถาม ว่า Question1 ไปยัง Arduino

    a = chat.readString();  // อ่าน Serial และนำไปเก็บในตัวแปร A
    chat.print(a);    
    delay(1000);

    Serial.print(".");

 

  }

}
