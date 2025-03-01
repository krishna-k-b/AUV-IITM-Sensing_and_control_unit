#include "diagnostics.hpp"
int led_status[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
void initializeLED() {
  for (int pin_index = 0; pin_index < 9; pin_index++) {
    pinMode(led_pinmap[pin_index], OUTPUT);
    digitalWrite(led_pinmap[pin_index], led_status[pin_index]);
  }
}

void setLED(int16_t led_indicator) {
  for (int pin_index = 0; pin_index < 9; pin_index++) {
    if ((led_indicator & led_bitmask[pin_index]) == led_bitmask[pin_index]){
      for(int i = 0; i < 9; i++){
        digitalWrite(led_pinmap[i], HIGH);
      }
      digitalWrite(led_pinmap[pin_index], LOW);
      nh.loginfo("Led Glowing.");
    }
  }
}

