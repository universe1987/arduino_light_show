#include "DynamicEffect.h"

#include "utils.h"

namespace LEDGeometry {

DynamicEffect::DynamicEffect(int cycle) : cycle(cycle), progress(0) {
    start_color = next_color();
    end_color = next_color();
    current_color = start_color;
}

int DynamicEffect::next_color() const {
    CRGB color;
    color.setHue(random8());
    return color;
}

void DynamicEffect::next_state() {
    ++progress;
    if (progress == cycle) {
        progress = 0;
        start_color = end_color;
        end_color = next_color();
    }
    uint8_t frac = (uint8_t)(256 * progress / cycle);
    current_color = start_color.lerp8(end_color, frac);
}
}  // namespace LEDGeometry
