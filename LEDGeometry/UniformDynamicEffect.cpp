#include "UniformDynamicEffect.h"

#include "LEDCurve.h"

namespace LEDGeometry {

UniformDynamicEffect::UniformDynamicEffect(int cycle) : DynamicEffect(cycle) {}

void UniformDynamicEffect::set_colors(LEDCurve* led_curve) {
    CRGB color = get_current_color();
    for (int i = 0; i < led_curve->n_points(); i++) {
        led_curve->leds()[i] = color;
    }
}
}  // namespace LEDGeometry
