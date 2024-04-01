#include<Servo.h>
volatile int i=0;
char tagOk[] ="0D0077099BE8"; // Replace with your wanted Tag ID 
char inputTag[12];        // A variable to store the Tag ID being presented
Servo servo;

void setup() 
{ 
pinMode(3,OUTPUT);
Serial.begin(9600);    //begin serial communication at baud 9600 
Serial.println("RFIDDDDDDDD");
servo.attach(3);
}

void loop() 
{ 
  
  if (Serial.available()){ 
//  servo.write(90);
  int count = 0; 
      while(Serial.available() && count < 12) { 
         inputTag[count] = Serial.read(); 
         count++; 
         delay(10); 
         } 
      Serial.println(inputTag); 
      int compare = 1; 
      compare = (strncmp(tagOk, inputTag,12)) ; // if both tags are equal strncmp returns a 0 
      if (compare == 0){ 
         Serial.println( "Sahil Verified");
         Serial.println( "PROCESSING");
         servo.write(0);//set servo potion ‘i’ degrees
         Serial.println(".........door opened.......");
         delay(5000);
        servo.write(90);
         Serial.println(".........Welcome Home Sahil.......");
          } 
      else
      {
        Serial.println ("Unknown Person Sending your Photos to Police"); }
       }
       }

