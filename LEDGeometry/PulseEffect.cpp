#include "PulseEffect.h"

#include <FastLED.h>

#include "LEDInterface.h"
#include "utils.h"

namespace LEDGeometry {

PulseEffect::PulseEffect(int period) : DynamicEffect(period), clock(0) {}

int PulseEffect::get_brightness() const {
    int input_signal = 0;
    int output_signal;
    // 1 slow pulse followed by 2 fast pulses
    // TODO: adjust the frequency based on the period
    if (clock < 32) {
        if (clock >= 8 && clock <= 24) {
            input_signal = (clock - 8) * 16;
        }
    } else {
        int t = (clock - 32) % 16;
        if (clock >= 4 && clock <= 12) {
            input_signal = (clock - 4) * 32;
        }
    }
    return quadwave8((uint8_t) input_signal);
}

void PulseEffect::set_colors(LEDInterface* ledCurve) {
    CRGB color = get_current_color();
    color.fadeLightBy(256 - get_brightness());
    for (int i = 0; i < ledCurve->n_points(); i++) {
        ledCurve->leds()[i] = color;
    }
}

void PulseEffect::next_state() {
    DynamicEffect::next_state();
    clock = (clock + 1) % 64;
}
}  // namespace LEDGeometry
