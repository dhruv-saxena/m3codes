#include <Servo.h>;

Servo myservo;
int motorPos = 0; 
int pot = 0;
void setup() {
  
  Serial.begin(9600);
  
  myservo.attach(10);
  
  pot = analogRead(A1);
  
  delay(2000);
  
  // put your setup code here, to run once:

}

void loop() {
//motorTrigger();
pot = analogRead(A1);
pot = map(pot,0,1023,10,170);
myservo.write(pot);

}


void motorPot(){

}

void motorTrigger() 
{ 
  
    for(motorPos = 170; motorPos>=60; motorPos-=10)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(motorPos);              // tell servo to go to position in variable 'pos' 
    delay(5);
    //Serial.println(motorPos);    // waits 15ms for the servo to reach the position  
} 
  
  for(motorPos = 60; motorPos < 170; motorPos += 10)  // goes from 10 degrees to 170 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(motorPos);     // tell servo to go to position in variable 'pos' 
    delay(5);              // waits 15ms for the servo to reach the position 
    //Serial.println(motorPos);  
} 



} 
