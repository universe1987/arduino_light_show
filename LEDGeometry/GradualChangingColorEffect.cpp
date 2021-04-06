#include "GradualChangingColorEffect.h"

#include "LEDCurve.h"
#include "utils.h"

namespace LEDGeometry {

GradualChangingColorEffect::GradualChangingColorEffect(int period) : period(period), progress(0) {
    hue = random8();
    previous_color = bright_color(hue);
    color = previous_color;
    hue = next_hue();
    next_color = bright_color(hue);
}

int GradualChangingColorEffect::next_hue() const { return (hue + random8(32, 224)) % 256; }

void GradualChangingColorEffect::next_state() {
    ++progress;
    if (progress == 0) {
        previous_color = next_color;
        hue = next_hue();
        next_color = bright_color(hue);
    }
    float weight = (float) progress / period;
    color = interpolate(previous_color, next_color, weight);
}
}  // namespace LEDGeometry
