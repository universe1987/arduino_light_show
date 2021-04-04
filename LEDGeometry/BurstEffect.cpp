#include "BurstEffect.h"
#include "LEDCurve.h"
#include "utils.h"


namespace LEDGeometry {
    BurstEffect::BurstEffect(): i_frame(0) {
        spectrum = new CRGB[32];
        hue = random8();
        current_color = bright_color(hue);
        hue = next_hue();
        future_color = bright_color(hue);
        for (int i = 0; i < 32; i++) {
            spectrum[i] = CRGB::Black;
        }
    }

    BurstEffect::~BurstEffect() {
        delete[] spectrum;
    }

    int BurstEffect::next_hue() const {
        return (hue + random8(32, 224)) % 256;
    }

    void BurstEffect::next_state() {
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
        for(int i = 31; i > 0; i--) {
            spectrum[i] = spectrum[i-1];
        }
        spectrum[0] = color;
    }

    void BurstEffect::set_color(LEDCurve* ledCurve) {
        for (int i = 0; i < ledCurve->n_leds(); i++) {
            float r = ledCurve->norm(i);
            int projection = (int)round(31 * r);
            ledCurve->leds()[i] = spectrum[projection];
        }
    }
}
