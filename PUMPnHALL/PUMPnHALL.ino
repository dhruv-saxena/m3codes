
#include <Servo.h>;
#include <spi4teensy3.h>
#include <EEPROM.h>
#include <M3T3.h>

Servo myServoA;
int motorPosA = 0; 

Servo myServoB;
int motorPosB= 0; 

//Hall Variables
#define MIDI_CHANNEL 1
int he[6] = {A2, A3, A4, A5, A6, A7};
int prev[6];
int current[6];
int diff[6];
boolean hitNote[6] = {false, false, false, false, false, false};
long time = 0;
unsigned int period = 300;
int num =6;

//Pump Variables
int xA, xoldA, xB, xoldB, xt, F; // input position x, output force F
int K = 30; // slope constant
byte count; //for print count-down

long returnCount = 0;
long distanceA = 0;
int dirA = 0;
long distanceB = 0;
int dirB = 0;
long breakCount1 = 0;
long breakCount2 = 0;
int Fa = 0;
int Fb = 0;

void setup() {
  Serial.begin(9600);
  
  myServoA.attach(9);
  myServoB.attach(10);
  
  //Motor Setup
  MotorA.init();
  xA = average(A1); // initialize xA

  MotorB.init();
  xB = average(A9); // initialize xB

  delay(2000);

  //Pump Setup
  for (int i = 0; i < 6; i++) {
    current[i] = average(he[i]);
  }

}

void loop() {
  pumpA();
  pumpB();
  //hall();
}

