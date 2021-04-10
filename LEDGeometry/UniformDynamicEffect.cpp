#include "UniformDynamicEffect.h"
#include "LEDInterface.h"
#include "utils.h"

namespace LEDGeometry {

UniformDynamicEffect::UniformDynamicEffect(int period) : DynamicEffect(period) {
}

void UniformDynamicEffect::set_colors(LEDInterface* ledCurve) {
    CRGB color = get_current_color();
    for (int i = 0; i < ledCurve->n_points(); i++) {
        ledCurve->leds()[i] = color;
    }
}
}  // namespace LEDGeometry
