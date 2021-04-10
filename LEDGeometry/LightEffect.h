#pragma once

namespace LEDGeometry {
class LEDInterface;
class LightEffect {
   public:
    virtual ~LightEffect() {}
    virtual void next_state() = 0;
    virtual void set_colors(LEDInterface* ledCurve) = 0;
    void update_leds(LEDInterface* ledCurve);
};
}  // namespace LEDGeometry
