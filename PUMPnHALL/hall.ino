


int average(int pin) {
  int value = 0;
  for (int i = 0; i < 256; i++) {
    value += analogRead(pin);
  }
  value = value / 256;
  return value;
}

void hall() {
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

