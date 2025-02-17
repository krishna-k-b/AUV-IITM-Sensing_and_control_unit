#include "sensor_interface.hpp"
const int16_t led_bitmask[9] = {1, 2, 4, 8, 16, 32, 64, 128, 256};

const uint8_t led_pinmap[9] = {PB12, PB13, PB14, PB15, PA5, PA4, PA15, PB4, PB5};

void initializeLED();
void setLED(int16_t led_indicator);