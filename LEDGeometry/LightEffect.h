#pragma once

namespace LEDGeometry {
class LEDCurve;

class LightEffect {
public:
    virtual ~LightEffect() {}
    virtual void next_state() = 0;
    virtual void set_colors(LEDCurve* ledCurve) = 0;

    void update_leds(LEDCurve* ledCurve) {
        set_colors(ledCurve);
        if (ledCurve->is_folded()) {
            int n_points = ledCurve->n_points();
            int n_leds = n_points * 2;
            for (int i = 0; i < n_points; i++) {
                ledCurve->leds()[n_leds - i - 1] = ledCurve->leds()[i];
            }
        }
    }
};
}
