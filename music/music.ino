#include <spi4teensy3.h>
#include <EEPROM.h>
#include <M3T3.h>

byte waveFormArray[] = { SINE,
                        SQUARE,
                        PULSE,
                        TRIANGLE,
                        SAW,
                        FUZZ,
                        DIGI1,
                        DIGI2,
                        DIGI3,
                        DIGI4,
                        NOISE,
                        DIGI6,
                        TAN1,
                        TAN2,
                        TAN3,
                        TAN4
                       };

void setup() {

  Music.init();
  Music.setWaveform1(TRIANGLE);
  Music.setWaveform2(SAW);

}

void loop() {
 int posA= analogRead(A1);
 int fsr = analogRead(A9);
 Serial.println(fsr);
 int freq = map(posA,0,1023,200,2000);
 int bump = map(fsr,0,1023,200,2000);
  Music.setFrequency1(freq);
  Music.setFrequency2(bump);
 
  
}
