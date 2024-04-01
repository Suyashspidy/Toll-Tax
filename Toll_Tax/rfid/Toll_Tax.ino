char tagOk[] ="0D0077099BE8"; // Replace with your wanted Tag ID 
char inputTag[12];        // A variable to store the Tag ID being presented


void setup() 
{ 
Serial.begin(9600);    //begin serial communication at baud 9600 
Serial.println("This is Jarvis Please shoe your RFID Tag");
}

void loop() 
{ 
  if (Serial.available()){ 
    
  int count = 0; 
      while(Serial.available() && count < 12) { 
         inputTag[count] = Serial.read(); 
         count++; 
         delay(10); 
         } 
      //Serial.print(inputTag); 
      int compare = 1; 
      compare = (strncmp(tagOk, inputTag,12)) ; // if both tags are equal strncmp returns a 0 
      if (compare == 0){ 
         Serial.println( "Ashish Verified");
         Serial.println( "Opening the door for you");
         delay(5000);
         Serial.println(".........door opened.......");
         Serial.println(".........Welcome Home Sahil.......");
          } 
      else
      {
        delay(3000);
        Serial.println ("Unknown Person Sending your Photos to Police"); }
       } 
       
}
