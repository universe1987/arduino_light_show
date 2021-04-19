#include "ColorScheduler.h"

#include <math.h>

namespace LEDGeometry {
ColorScheduler::ColorScheduler(int cycle, uint8_t hue, uint8_t min_hue_delta,
                               uint8_t max_hue_delta)
    : cycle(cycle),
      hue(hue),
      min_hue_delta(min_hue_delta),
      max_hue_delta(max_hue_delta) {
    end_color.setHue(hue);
    change_theme();
    current_color = start_color;
}

ColorScheduler::ColorScheduler(int cycle)
    : ColorScheduler(cycle, random8(), 32, 224) {}

void ColorScheduler::set_cycle(int new_cycle) {
    progress = (int)round(progress * new_cycle / cycle);
    if (progress >= new_cycle) {
        progress = new_cycle - 1;
    }
    cycle = new_cycle;
}

uint8_t ColorScheduler::get_progress() const {
    return (uint8_t)(progress * 255 / cycle);
}

void ColorScheduler::change_theme() {
    start_color = end_color;
    hue += random8(min_hue_delta, max_hue_delta);
    end_color.setHue(hue);
}

CRGB ColorScheduler::next_color() {
    ++progress;
    if (progress >= cycle) {
        progress = 0;
        change_theme();
    }
    uint8_t frac = (uint8_t)(255 * progress / cycle);
    current_color = blend(start_color, end_color, frac);
    return current_color;
}
}  // namespace LEDGeometry
