#include "BurstEffect.h"

#include <math.h>
#include <FastLED.h>

#include "ColorScheduler.h"
#include "LEDCurve.h"
#include "Shape.h"

namespace LEDGeometry {

BurstEffect::BurstEffect(float min_radius, float max_radius, int resolution,
                         int frequency)
    : min_radius(min_radius),
      max_radius(max_radius),
      resolution(resolution),
      frequency(frequency) {
    CRGB* spectrum = new CRGB[resolution];
    for (int i = 0; i < resolution; i++) {
        spectrum[i] = CRGB::Black;
    }
}

BurstEffect::BurstEffect() : BurstEffect(0.0, 1.0, 64, 32) {}

BurstEffect::~BurstEffect() { delete[] spectrum; }

void BurstEffect::update(LEDCurve* led_curve) {
    for (int i = resolution - 1; i > 0; i--) {
        spectrum[i] = spectrum[i - 1];
    }
    spectrum[0] = led_curve->color_scheduler->next_color();
    spectrum[0].fadeLightBy(
        quadwave8(frequency * led_curve->color_scheduler->get_progress()));
    float scale = (resolution - 1) / (max_radius - min_radius);
    for (int i = 0; i < led_curve->shape->n_points(); i++) {
        float r = led_curve->shape->r(i);
        int projection = (int)round((r - min_radius) * scale);
        led_curve->leds[i] = spectrum[projection];
    }
}
}  // namespace LEDGeometry
