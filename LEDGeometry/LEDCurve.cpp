#include "LEDCurve.h"

namespace LEDGeometry {
void LEDCurve::display(int sleep_ms) {
    if (folded) {
        int n = n_points();
        CRGB* led_array = leds();
        for (int i = 0; i < n; i++) {
            led_array[n + i] = led_array[n - i - 1];
        }
    }
    FastLED.show();
    FastLED.delay(sleep_ms);
}

void LEDCurve::set_effect(LightEffect* effect, int n_seconds, int fps) {
    int sleep_ms = 1000 / fps;
    int n_iters = n_seconds * fps;
    for (int i = 0; i < n_iters; i++) {
        effect->update_leds(this);
        display(sleep_ms);
    }
}
}  // namespace LEDGeometry
