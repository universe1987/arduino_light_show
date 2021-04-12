#include "BurstEffect.h"

#include "LEDCurve.h"
#include "utils.h"

namespace LEDGeometry {

BurstEffect::BurstEffect(int period, int min_hue_delta, int max_hue_delta,
                         float min_radius, float max_radius, int resolution,
                         int wave_period)
    : DynamicEffect(period, min_hue_delta, max_hue_delta),
      min_radius(min_radius),
      max_radius(max_radius),
      resolution(resolution),
      wave_period(wave_period) {
    spectrum = new CRGB[resolution];
    for (int i = 0; i < resolution; i++) {
        spectrum[i] = CRGB::Black;
    }
}

BurstEffect::BurstEffect(int period)
    : BurstEffect(period, 32, 224, 0.0, 1.0, 100, 32) {}

BurstEffect::~BurstEffect() { delete[] spectrum; }

void BurstEffect::next_state() {
    DynamicEffect::next_state();
    for (int i = 1; i < resolution; i++) {
        spectrum[i] = spectrum[i-1];
    }
    spectrum[0] = get_current_color();
    spectrum[0].fadeLightBy(quadwave8(wave_period * get_progress()));
}

void BurstEffect::set_color(LEDCurve *ledCurve) {
    int width = max_radius - min_radius;
    for (int i = 0; i < ledCurve->n_points(); i++) {
        float r = ledCurve->r(i);
        int projection = (int)((resolution - 1) * (r - min_radius) / width);
        ledCurve->leds()[i] = spectrum[projection];
    }
}
}  // namespace LEDGeometry
