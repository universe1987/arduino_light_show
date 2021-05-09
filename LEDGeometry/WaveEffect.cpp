#include "WaveEffect.h"

#include <FastLED.h>

#include "ColorScheduler.h"
#include "LEDCurve.h"
#include "Shape.h"

namespace LEDGeometry {
WaveEffect::WaveEffect(CRGB* spectrum, uint8_t resolution, uint8_t* projection,
                       uint8_t frequency)
    : spectrum(spectrum),
      resolution(resolution),
      projection(projection),
      frequency(frequency) {
    for (uint8_t i = 0; i < resolution; i++) {
        spectrum[i] = CRGB::Black;
    }
}

void WaveEffect::update(LEDCurve* led_curve) {
    for (uint8_t i = 0; i < led_curve->shape->n_points(); i++) {
        led_curve->leds[i] = spectrum[projection[i]];
    }
    propagate();
    spectrum[0] = led_curve->color_scheduler->next_color();
    uint8_t phase =
        qmul8(frequency, led_curve->color_scheduler->get_progress());
    spectrum[0].fadeLightBy(quadwave8(phase));
}

void WaveEffect::propagate() {
    for (uint8_t i = resolution - 1; i > 0; i--) {
        spectrum[i] = spectrum[i - 1];
    }
}
}  // namespace LEDGeometry
