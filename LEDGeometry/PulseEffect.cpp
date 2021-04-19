#include "PulseEffect.h"

#include <FastLED.h>

#include "LEDCurve.h"

namespace LEDGeometry {

PulseEffect::PulseEffect() : PulseEffect(30) {}

PulseEffect::PulseEffect(int beats_per_minute)
    : beats_per_minute(beats_per_minute) {}

void PulseEffect::update(LEDCurve* led_curve) {
    CRGB color = led_curve->next_color();
    color.fadeLightBy(beatsin8((uint8_t)beats_per_minute));
    for (int i = 0; i < led_curve->n_points(); i++) {
        led_curve->led(i) = color;
    }
}
}  // namespace LEDGeometry
