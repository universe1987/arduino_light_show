#include "UniformDynamicEffect.h"

#include <FastLED.h>

#include "ColorScheduler.h"
#include "LEDCurve.h"
#include "Shape.h"

namespace LEDGeometry {
void UniformDynamicEffect::update(LEDCurve* led_curve) {
    CRGB color = led_curve->color_scheduler->next_color();
    for (int i = 0; i < led_curve->shape->n_points(); i++) {
        led_curve->leds[i] = color;
    }
}
}  // namespace LEDGeometry
