#include <spi4teensy3.h>
#include <EEPROM.h>
#include <M3T3.h>

long tick = 0;
int c = 0;
int last_pos = 0;
float vel;
void setup() {
  Music.init();
  tick = millis();
  last_pos = analogRead(A1);
}

void loop() {

  long tick_now = millis();
  long dt = tick_now - tick;


  if (dt >= 20) {

    int current_pos = analogRead(A1);
    int dx = last_pos - current_pos;
    vel = (float)dx / (float)dt;


    tick = tick_now;
    last_pos = current_pos;
    Serial.println(vel);
  }

  if (abs(vel) > 0.5) {
    Music.setGain(1);
    set_freq(vel);
  }
  else
    Music.setGain(0);

}

void set_freq(float vel) {
  float vel_amp = abs(vel);
  float freq = map(vel_amp, 1, 10, 100, 1500);
  Music.setFrequency(freq);
}
