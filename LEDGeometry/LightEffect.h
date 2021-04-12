#pragma once

namespace LEDGeometry {
class LEDCurve;
class LightEffect {
   public:
    virtual ~LightEffect() {}
    // update internal states in order to create dynamic effects
    virtual void next_state() = 0;
    // logic for setting the LED colors based on the internal states
    virtual void set_colors(LEDCurve* ledCurve) = 0;

    void update_leds(LEDCurve* ledCurve) {
        set_colors(ledCurve);
        next_state();
    };
};
}  // namespace LEDGeometry
