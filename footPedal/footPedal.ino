#include <spi4teensy3.h>
#include <EEPROM.h>
#include <M3T3.h>

int x, xold, xt, F; // input position x, output force F
int K = 30; // slope constant
byte count; //for print count-down

long returnCount = 0;

void setup() {
  Music.init();
  Music.setFrequency1(200);
  Music.setFrequency2(250);
  Music.setFrequency3(300);

  MotorA.init();

  Serial.begin(9600);
  x = analogRead(A1); // initialize x

}
void loop() {
  xold = x;
  x =  analogRead(A1);

  if (((xold <= 125) && (x > 125)) || ((xold >= 125) && (x < 125))) {
    Music.setGain1(1.0f);
    Music.setFrequency1(200);
  }
  if (((xold <= 375) && (x > 375)) || ((xold >= 375) && (x < 375))) {
    Music.setGain2(1.0f);
    Music.setFrequency2(250);
  }
  if (((xold <= 625) && (x > 625)) || ((xold >= 625) && (x < 625))) {
    Music.setGain3(1.0f);
    Music.setFrequency3(300);
  }
  if (((xold <= 875) && (x > 875)) || ((xold >= 875) && (x < 875))) {
    Music.setGain1(1.0f);
    Music.setFrequency1(400);
  }
  else {
    Music.setGain1(0.9995f * Music.getGain1());
    Music.setGain2(0.9995f * Music.getGain2());
    Music.setGain3(0.9995f * Music.getGain3());
  }
  
  
  if(x>1000){
      returnCount = 0;
  }
  F = -3*x;
  returnCount++;
  if(returnCount>10000){
    
  
    //same force for each 250 ranage
  xt = x % 250;
  F = -300;
  //if (xt > 60) F = - K * (xt - 60);
  //if (xt > 80) F = - K * (100 - xt);
  if (xt > 120) F = -300 - K * 50;
  if (xt > 140) F = -300 - K*10;
  if(xt>160) F = -300;
  }
  MotorA.torque(F);
 
}

