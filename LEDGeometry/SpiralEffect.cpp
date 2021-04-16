#include "SpiralEffect.h"

#include "LEDCurve.h"

namespace LEDGeometry {
SpiralEffect::SpiralEffect(int cycle, int n_segments)
    : pos(0), cycle(cycle), n_segments(n_segments) {
    current_color.setHue(random8());
}

void SpiralEffect::next_state() {
    ++pos;
    if (pos == cycle) {
        pos = 0;
        current_color.setHue(random8());
    }
}

void SpiralEffect::set_colors(LEDCurve* led_curve) {
    for (int i = 0; i < n_segments; i++) {
        led_curve->leds()[pos + i * cycle] = current_color;
    }
}
}  // namespace LEDGeometry