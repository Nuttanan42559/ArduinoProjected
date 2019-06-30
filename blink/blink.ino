int Led = 8;
 
void setup ()
{
  pinMode (Led, OUTPUT); // Initialization of the LED output pin
}
 
void loop () // main program loop
{
  digitalWrite (Led, HIGH); // LED will be switched on
  delay (4000); // waitmode for 4 seconds
  digitalWrite (Led, LOW); // LED will be switched off
  delay (2000); // waitmode for another 2 seconds
}
