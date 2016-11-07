#include <AFMotor.h>
AF_DCMotor myMotor(3, MOTOR34_1KHZ); // create motor #2, 64KHz pwm
AF_DCMotor myMotor2(4, MOTOR34_1KHZ);

String inputString = "";         // a string to hold incoming data

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.setTimeout(500);
myMotor.setSpeed(255);
myMotor2.setSpeed(255);
myMotor.run(RELEASE);  
myMotor2.run(RELEASE); 

}




void loop() {
  //decode the commands sent
  decodeCommands();
  //
}




void serialEvent() {

inputString = Serial.readStringUntil('x');  

}

void decodeCommands() {
  
  switch (inputString.charAt(0)) {
   case '1':  
      
    switch (inputString.charAt(1)) {
     case '3': 
      //Serial.println("case 1");
      myMotor.run(FORWARD);
      myMotor2.run(FORWARD);
      myMotor.setSpeed(255);
      myMotor2.setSpeed(255);
      break;
            
     case '2': 
      myMotor.run(FORWARD);
      myMotor2.run(FORWARD);
      myMotor.setSpeed(125);
      myMotor2.setSpeed(255);
      break;
    
     case '1': 
      myMotor.run(FORWARD);
      myMotor2.run(FORWARD);
      myMotor.setSpeed(255);
      myMotor2.setSpeed(125);
      break;
    
    }
    break;
  
  case '2': 
    switch (inputString.charAt(1)) {
     case '3': 
      myMotor.run(BACKWARD);
      myMotor2.run(BACKWARD);
      myMotor.setSpeed(255);
      myMotor2.setSpeed(255);
      break;
     case '2': 
      myMotor.run(BACKWARD);
      myMotor2.run(BACKWARD);
      myMotor.setSpeed(125);
      myMotor2.setSpeed(255);
      break;
     case '1': 
      myMotor.run(BACKWARD);
      myMotor2.run(BACKWARD);
      myMotor.setSpeed(255);
      myMotor2.setSpeed(125);
      break;
    }
  
    break;
  case '3': 
    //myMotor.run(RELEASE);
    //myMotor2.run(RELEASE);
    switch (inputString.charAt(1)) {
      case '1': 
       myMotor.run(FORWARD);
       myMotor2.run(BACKWARD);
       break;
      case '2': 
       myMotor2.run(FORWARD);
       myMotor.run(BACKWARD);
       break;
      case '3':
       myMotor.run(RELEASE);
       myMotor2.run(RELEASE);
       break;
      default: 
       myMotor.run(RELEASE);
       myMotor2.run(RELEASE);
       break;
      }
    }
}


