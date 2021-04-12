#include "DynamicEffect.h"

#include "utils.h"

namespace LEDGeometry {

DynamicEffect::DynamicEffect(int period, int min_hue_delta, int max_hue_delta)
    : period(period),
      min_hue_delta(min_hue_delta),
      max_hue_delta(max_hue_delta),
      progress(0) {
    hue = random8();
    previous_color = bright_color(hue);
    current_color = previous_color;
    hue = next_hue();
    next_color = bright_color(hue);
}

int DynamicEffect::next_hue() const {
    return (hue + random8(min_hue_delta, max_hue_delta)) % 256;
}

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
