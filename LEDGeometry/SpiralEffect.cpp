#include "SpiralEffect.h"

#include <FastLED.h>

#include "LEDCurve.h"

namespace LEDGeometry {
SpiralEffect::SpiralEffect(int n_segments, int segment_length)
    : pos(0), n_segments(n_segments), segment_length(segment_length) {}

void SpiralEffect::update(LEDCurve* led_curve) {
    CRGB color = led_curve->next_color();
    for (int i = 0; i < n_segments; i++) {
        led_curve->led(pos + i * segment_length) = color;
    }
    ++pos;
    if (pos >= segment_length) {
        pos = 0;
    }
}
}  // namespace LEDGeometry
