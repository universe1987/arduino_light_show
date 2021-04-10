#pragma once

namespace LEDGeometry {
class LEDCurve;

class LightEffect {
public:
    virtual ~LightEffect() {}
    virtual void next_state() = 0;
    virtual void set_colors(LEDCurve* ledCurve) = 0;
    void update_leds(LEDCurve* ledCurve);
};
}
