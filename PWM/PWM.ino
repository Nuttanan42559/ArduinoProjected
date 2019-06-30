int NbTopsFan; int Calc;
 
//The pin location of the sensor
int hallsensor = 2; typedef struct{
 
//Defines the structure for multiple fans and 
//their dividers 
char fantype;
unsigned int fandiv; }fanspec;
 
//Definitions of the fans
//This is the varible used to select the fan and it's divider,
//set 1 for unipole hall effect sensor
//and 2 for bipole hall effect sensor
fanspec fanspace[3]={{0,1},{1,2},{2,8}}; char fan = 1;
int fanpin = 9;    // LED connected to digital pin 9
String value;

void rpm () { NbTopsFan++; }
//This is the function that the interupt calls
//This is the setup function where the serial port is initialised,
//and the interrupt is attached
void setup() {
  pinMode(hallsensor, INPUT);
  Serial.begin(9600);
  attachInterrupt(0, rpm, RISING);
  //analogWrite(fanpin, 255);
}

void loop() {
    if (Serial.available()) {
      value = Serial.readString();
      int Rvalue = value.toInt();
  
      analogWrite(fanpin, Rvalue);
    }
}

int fanrpm()
{
      //Set NbTops to 0 ready for calculations
      NbTopsFan = 0;
       
//      //Enables interrupts
//      sei();
//       
//      //Wait 1 second
//      delay (1000);
//       
//      //Disable interrupts
//      cli();
       
      //Times NbTopsFan (which is apprioxiamately the fequency the fan 
      //is spinning at) by 60 seconds before dividing by the fan's divider
      Calc = ((NbTopsFan * 60)/fanspace[fan].fandiv);
       
      return Calc;
}
