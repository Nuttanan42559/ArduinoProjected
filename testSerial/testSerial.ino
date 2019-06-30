String incomingByte; // for incoming serial data

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {
  // reply only when you receive data:
  if (Serial.available()) {
    // read the incoming byte:
    incomingByte = Serial.readString();
    int jack = incomingByte.toInt();

    // say what you got:
    Serial.println(jack);
//    Serial.println(incomingByte, DEC);
  }
}
