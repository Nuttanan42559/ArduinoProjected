#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "161a1f66aca443c3856b48747d625d32";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, "SHA256", "123456789");

}

void loop()
{
  Blynk.run();
  
}
