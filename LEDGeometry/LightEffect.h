#pragma once

namespace LEDGeometry {
class LEDCurve;

class LightEffect {
public:
    virtual ~LightEffect() {}
    virtual void next_state() = 0;
    virtual void set_color(LEDCurve* ledCurve) = 0;
};
}
