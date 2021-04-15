#include "PulseEffect.h"

#include <FastLED.h>

#include "LEDCurve.h"

namespace LEDGeometry {

PulseEffect::PulseEffect(int cycle) : PulseEffect(cycle, 30) {}

PulseEffect::PulseEffect(int cycle, int beats_per_minute)
    : DynamicEffect(cycle), beats_per_minute(beats_per_minute) {}

void PulseEffect::set_colors(LEDCurve* ledCurve) {
    CRGB color = get_current_color();
    color.fadeLightBy(beatsin8((uint8_t)beats_per_minute));
    for (int i = 0; i < ledCurve->n_points(); i++) {
        ledCurve->leds()[i] = color;
    }
}
}  // namespace LEDGeometry
