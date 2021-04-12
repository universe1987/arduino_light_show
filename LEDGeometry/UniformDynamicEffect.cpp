#include "UniformDynamicEffect.h"

#include "LEDCurve.h"
#include "utils.h"

namespace LEDGeometry {

UniformDynamicEffect::UniformDynamicEffect(int period, int min_hue_delta,
                                           int max_hue_delta)
    : DynamicEffect(period, min_hue_delta, max_hue_delta) {}

UniformDynamicEffect::UniformDynamicEffect(int period)
    : DynamicEffect(period, 32, 224) {}

void UniformDynamicEffect::set_colors(LEDCurve* ledCurve) {
    CRGB color = get_current_color();
    for (int i = 0; i < ledCurve->n_points(); i++) {
        ledCurve->leds()[i] = color;
    }
}
}  // namespace LEDGeometry
