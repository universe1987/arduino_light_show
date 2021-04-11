#include "PulseEffect.h"

#include <FastLED.h>

#include "LEDInterface.h"
#include "utils.h"

namespace LEDGeometry {

PulseEffect::PulseEffect(int period) : DynamicEffect(period), clock(0) {}

int PulseEffect::get_brightness() const {
    int input_signal;
    int output_signal;
    if (clock < 32) {
        input_signal = clock * 8;
    } else {
        input_signal = ((clock - 32) * 16) % 256;
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
