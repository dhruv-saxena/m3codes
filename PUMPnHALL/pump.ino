
void pumpA() {
  xoldA = xA;
  xA =  average(A1);
  dirA = xA - xoldA;

  if (dirA > 1) {
    distanceA += xA - xoldA;
    //Serial.print(xold);
    //Serial.print(" ");
    //Serial.println(distance);
  }

  F = -100 - distanceA / 20;
  
  Fa = F;
  //motorPos = map(Fa,-600,-100,160,115);
  motorPosA = map(Fa,-300,-100,130,40);
  Serial.print(Fa);
  Serial.print(" ");
  Serial.println(motorPosA);
  motorTrigger2();
  
  if (F <= -350) {
    while (breakCount1 < 10000) {
      F = +500;
      distanceA = 0;
      MotorA.torque(F);
      breakCount1++;
    }
    while (breakCount2 < 10000) {
      F = -500;
      distanceA = 0;
      MotorA.torque(F);
      breakCount2++; 
    }

    F = -100;
    MotorA.torque(F);
    motorTrigger2();
  }

  //Serial.println(F);
  MotorA.torque(F);
  breakCount1 = 0;
  breakCount2 = 0;
}


void pumpB() {
  xoldB = xB;
  xB =  average(A9);
  dirB = xB - xoldB;

  if (dirB > 1) {
    distanceB += xB - xoldB;
    //Serial.print(xold);
    //Serial.print(" ");
    //Serial.println(distance);
  }

  F = -100 - distanceB / 20;
  Fb = F;
  
  motorPosB = map(Fb,-300,-100,110,20);
  Serial.print(Fb);
  Serial.print(" ");
  Serial.println(motorPosB);
  motorTrigger2();

  if (F <= -350) {
    while (breakCount1 < 10000) {
      F = +500;
      distanceB = 0;
      MotorB.torque(F);
      breakCount1++;
    }
    while (breakCount2 < 10000) {
      F = -500;
      distanceB = 0;
      MotorB.torque(F);
      breakCount2++;
    }

    F = -100;
    MotorB.torque(F);
    motorTrigger2();
  }

  //Serial.println(F);
  MotorB.torque(F);
  breakCount1 = 0;
  breakCount2 = 0;
}


