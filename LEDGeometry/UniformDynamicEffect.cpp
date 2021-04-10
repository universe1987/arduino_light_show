#include "UniformDynamicEffect.h"
#include "LEDCurve.h"
#include "utils.h"

namespace LEDGeometry {

UniformDynamicEffect::UniformDynamicEffect(int period) : DynamicEffect(period) {
}

void UniformDynamicEffect::set_colors(LEDCurve* ledCurve) {
    CRGB current_color = get_color();
    for (int i = 0; i < ledCurve->n_points(); i++) {
        ledCurve->leds()[i] = current_color;
    }
}
}  // namespace LEDGeometry
