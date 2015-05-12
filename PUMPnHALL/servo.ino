void motorTrigger() 
{ 
  
    for(motorPosA = 170; motorPosA>=60; motorPosA-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myServoA.write(motorPosA);              // tell servo to go to position in variable 'pos' 
    delay(5);                       // waits 15ms for the servo to reach the position 
     
} 
  
  for(motorPosA = 60; motorPosA < 170; motorPosA += 1)  // goes from 10 degrees to 170 degrees 
  {                                  // in steps of 1 degree 
    myServoA.write(motorPosA);     // tell servo to go to position in variable 'pos' 
    delay(5);              // waits 15ms for the servo to reach the position 
      
} 



} 

void motorTrigger2(){
    myServoA.write(motorPosA); 
    myServoB.write(motorPosB); 
}
