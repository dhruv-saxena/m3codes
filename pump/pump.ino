#include <spi4teensy3.h>
#include <EEPROM.h>
#include <M3T3.h>

int x, xold, xt, F; // input position x, output force F
int K = 30; // slope constant
byte count; //for print count-down

long returnCount = 0;
long distance = 0;
int dir = 0;
long breakCount1 = 0;
long breakCount2 = 0;

void setup() {
  Music.init();
  Music.setFrequency1(200);
  Music.setFrequency2(250);
  Music.setFrequency3(300);

  MotorA.init();

  Serial.begin(9600);
  x = average(A1); // initialize x

}
void loop() {
  xold = x;
  x =  average(A1);

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

  dir = x - xold;

  if (dir > 0) {
    distance += x - xold;
    Serial.print(xold);
    Serial.print(" ");
    Serial.println(distance);
  }

  F = -100 - distance / 20;

  /*
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

  */


  if (F <= -800) {
    while (breakCount1 < 10000) {
      F = +500;
      distance = 0;
      MotorA.torque(F);
      breakCount1++;
    }
    while (breakCount2 < 10000) {
      F = -500;
      distance = 0;
      MotorA.torque(F);
      breakCount2++;
    }

    F = -100;
    MotorA.torque(F);
  }

  Serial.println(F);
  MotorA.torque(F);
  breakCount1 = 0;
  breakCount2 = 0;
}

int average(int x) {
  int a = 0;
  for (int i = 0; i < 1000; i++) {
    a += analogRead(x);
  }
  a = a / 1000;
  return a;
}

