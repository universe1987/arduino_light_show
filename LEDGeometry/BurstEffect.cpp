#include "BurstEffect.h"

#include "LEDCurve.h"
#include "utils.h"

namespace LEDGeometry {
BurstEffect::BurstEffect(float r_min, float r_max, int resolution)
    : r_min(r_min), r_max(r_max), resolution(resolution), i_frame(0), pos(0) {
    spectrum = new CRGB[resolution];
    hue = random8();
    current_color = bright_color(hue);
    hue = next_hue();
    future_color = bright_color(hue);
    for (int i = 0; i < resolution; i++) {
        spectrum[i] = CRGB::Black;
    }
}

BurstEffect::~BurstEffect() { delete[] spectrum; }

int BurstEffect::next_hue() const { return (hue + random8(32, 224)) % 256; }

void BurstEffect::next_state() {
    ++i_frame;
    if (i_frame == 128) {
        i_frame = 0;
        hue = next_hue();
        current_color = future_color;
        future_color = bright_color(hue);
    }
    float weight = (float)i_frame / 128;
    CRGB color = interpolate(current_color, future_color, weight);
    uint8_t scale = quadwave8(8 * (i_frame % 32));
    color.fadeToBlackBy(scale);
    spectrum[pos] = color;
    pos = (pos + 1) % resolution;
}

void BurstEffect::set_color(LEDCurve *ledCurve) {
    for (int i = 0; i < ledCurve->n_leds(); i++) {
        float r = ledCurve->r(i);
        int projection =
            (int)((resolution - 1) * (r - r_min) / (r_max - r_min));
        ledCurve->leds()[i] = spectrum[projection];
    }
}
}  // namespace LEDGeometry
