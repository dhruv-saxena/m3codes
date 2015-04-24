#define MIDI_CHANNEL 1

#include <spi4teensy3.h>
#include <EEPROM.h>
#include <M3T3.h>


int he[6] = {A2, A3, A4, A5, A6, A7};
int prev[6];
int current[6];
int diff[6];
boolean hitNote[6] = {false, false, false, false, false, false};
long time = 0;
unsigned int period = 300;

void setup() {
  // declare the ledPin as an OUTPUT:
  //pinMode(ledPin, OUTPUT);
  Music.init();
  Serial.begin(9600);
  delay(2000);
  for (int i = 0; i < 6; i++) {
    current[i] = average(he[i]);
  }

}

void loop() {

  change();

}

int average(int pin) {
  int value = 0;
  for (int i = 0; i < 256; i++) {
    value += analogRead(pin);
  }
  value = value / 256;
  return value;
}

void change() {
  for (int i = 0; i < 6; i++) {
    prev[i] = current[i];
  }

  delay(10);

  for (int i = 0; i < 6; i++) {
    current[i] = average(he[i]);
    diff[i] = abs(prev[i] - current[i]);
    if (diff[i] > 10) {
      hitNote[i] = true;
      time = millis();
    }
  }

  if ((millis() - time > period) && (millis() - time <= period + 50)) {
    for (int i = 0; i < 6; i++) {
      if (hitNote[i]) {
        usbMIDI.sendNoteOn(62, 127, (i + 1));
        //delay(1000);
        Serial.println(i + 1);
      }
      hitNote[i] = false;
    }
  }
}




