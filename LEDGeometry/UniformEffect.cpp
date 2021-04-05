#include "UniformEffect.h"

#include "LEDCurve.h"
#include "utils.h"

namespace LEDGeometry {

UniformEffect::UniformEffect(int period) : period(period), i_frame(0) {
    hue = random8();
    previous_color = bright_color(hue);
    current_color = previous_color;
    hue = next_hue();
    next_color = bright_color(hue);
}

int UniformEffect::next_hue() const { return (hue + random8(32, 224)) % 256; }

void UniformEffect::next_state() {
    if (i_frame == period) {
        i_frame = 0;
        previous_color = next_color;
        hue = next_hue();
        next_color = bright_color(hue);
    }
    float weight = (float)i_frame / period;
    current_color = interpolate(previous_color, next_color, weight);
}

void UniformEffect::set_color(LEDCurve *ledCurve) {
    for (int i = 0; i < ledCurve->n_leds(); i++) {
        ledCurve->leds()[i] = current_color;
    }
}
}  // namespace LEDGeometry
