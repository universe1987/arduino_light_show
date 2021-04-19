#include "UniformDynamicEffect.h"

#include <FastLED.h>

#include "LEDCurve.h"
namespace LEDGeometry {
void UniformDynamicEffect::update(LEDCurve* led_curve) {
    CRGB color = led_curve->next_color();
    for (int i = 0; i < led_curve->n_points(); i++) {
        led_curve->led(i) = color;
    }
}
}  // namespace LEDGeometry
