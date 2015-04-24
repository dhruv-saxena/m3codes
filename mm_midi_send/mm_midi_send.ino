#define MIDI_CHANNEL 1

#include <spi4teensy3.h>
#include <EEPROM.h>
#include <M3T3.h>

boolean done = false;
void setup() {
  
  Music.init();
}

void loop() {
  if(millis() % 3000 == 0 && !done){
  
    usbMIDI.sendNoteOn(62, 127, 3);
    done = true;
  }
  else {
//    usbMIDI.sendNoteOn(62,0,00); //velocity zero means off
    
  }
}
