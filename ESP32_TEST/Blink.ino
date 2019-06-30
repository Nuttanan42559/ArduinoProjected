#define BT    17
#define WIFI  2
#define NTP   15
#define IoT   12
void setup() {
  pinMode(BT,  OUTPUT); // Bluetooth
  pinMode(WIFI,OUTPUT); // Wifi
  pinMode(NTP, OUTPUT); // NTP
  pinMode(IoT, OUTPUT);    // IoT
}

void loop() {
  // เปิด LED
  digitalWrite(BT,HIGH);    delay(100);
  digitalWrite(WIFI,HIGH);  delay(100);
  digitalWrite(NTP,HIGH);   delay(100);
  digitalWrite(IoT,HIGH);   delay(300);
  // ปิด LED
  digitalWrite(BT,LOW);     delay(100);
  digitalWrite(WIFI,LOW);   delay(100);
  digitalWrite(NTP,LOW);    delay(100);
  digitalWrite(IoT,LOW);    delay(300);
}
