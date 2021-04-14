#include "UniformDynamicEffect.h"

#include "LEDCurve.h"

namespace LEDGeometry {

UniformDynamicEffect::UniformDynamicEffect(int cycle) : DynamicEffect(cycle) {}

void UniformDynamicEffect::set_colors(LEDCurve* ledCurve) {
    CRGB color = get_current_color();
    for (int i = 0; i < ledCurve->n_points(); i++) {
        ledCurve->leds()[i] = color;
    }
}
}  // namespace LEDGeometry
