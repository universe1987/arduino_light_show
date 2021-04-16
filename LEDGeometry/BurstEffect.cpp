#include "BurstEffect.h"

#include <math.h>

#include "LEDCurve.h"

namespace LEDGeometry {

BurstEffect::BurstEffect(int cycle, float min_radius, float max_radius,
                         int resolution, int frequency)
    : DynamicEffect(cycle),
      min_radius(min_radius),
      max_radius(max_radius),
      resolution(resolution),
      frequency(frequency) {
    spectrum = new CRGB[resolution];
    for (int i = 0; i < resolution; i++) {
        spectrum[i] = CRGB::Black;
    }
}

BurstEffect::BurstEffect(int cycle) : BurstEffect(cycle, 0.0, 1.0, 64, 32) {}

BurstEffect::~BurstEffect() { delete[] spectrum; }

void BurstEffect::next_state() {
    DynamicEffect::next_state();
    for (int i = resolution - 1; i > 0; i--) {
        spectrum[i] = spectrum[i - 1];
    }
    spectrum[0] = get_current_color();
    spectrum[0].fadeLightBy(quadwave8(frequency * get_progress()));
}

void BurstEffect::set_color(LEDCurve *led_curve) {
    float scale = (resolution - 1) / (max_radius - min_radius);
    for (int i = 0; i < led_curve->n_points(); i++) {
        float r = led_curve->r(i);
        int projection = (int)round((r - min_radius) * scale);
        led_curve->leds()[i] = spectrum[projection];
    }
}
}  // namespace LEDGeometry
