#include "DynamicEffect.h"

#include "utils.h"

namespace LEDGeometry {

DynamicEffect::DynamicEffect(int period) : period(period), progress(0) {
    hue = random8();
    previous_color = bright_color(hue);
    current_color = previous_color;
    hue = next_hue();
    next_color = bright_color(hue);
}

int DynamicEffect::next_hue() const { return (hue + random8(32, 224)) % 256; }

void DynamicEffect::next_state() {
    ++progress;
    if (progress == period) {
        progress = 0;
        previous_color = next_color;
        hue = next_hue();
        next_color = bright_color(hue);
    }
    float weight = (float)progress / period;
    current_color = interpolate(previous_color, next_color, weight);
}
}  // namespace LEDGeometry
