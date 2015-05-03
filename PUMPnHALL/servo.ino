void motorTrigger() 
{ 
  
    for(motorPos = 170; motorPos>=60; motorPos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(motorPos);              // tell servo to go to position in variable 'pos' 
    delay(5);                       // waits 15ms for the servo to reach the position 
     
} 
  
  for(motorPos = 60; motorPos < 170; motorPos += 1)  // goes from 10 degrees to 170 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(motorPos);     // tell servo to go to position in variable 'pos' 
    delay(5);              // waits 15ms for the servo to reach the position 
      
} 



} 

void motorTrigger2(){
    myservo.write(motorPos);              // tell servo to go to position in variable 'pos' 
    //delay();                       // waits 15ms for the servo to reach the position 
}
