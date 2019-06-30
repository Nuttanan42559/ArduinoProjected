#define outputA 8
#define outputB 9
int counter = 10; 
int aState;
int aLastState;  
int led = 7;

void setup() { 
   pinMode(outputA,INPUT);
   pinMode(outputB,INPUT);
   pinMode(led, OUTPUT);
   
   Serial.begin(57600);
   // Reads the initial state of the outputA
   aLastState = digitalRead(outputA);   
 } 
void loop() { 
   aState = digitalRead(outputA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState != aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != aState) { 
       counter ++;
     } else {
       counter --;
     }
     Serial.print("Position: ");
     Serial.println(counter);

     digitalWrite(led, counter);
   } 
   aLastState = aState; // Updates the previous state of the outputA with the current state
 }
