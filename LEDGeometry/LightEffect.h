#pragma once

namespace LEDGeometry {
class LEDCurve;
class LightEffect {
   public:
    virtual ~LightEffect() {}

    void update_leds(LEDCurve* ledCurve) {
        set_colors(ledCurve);
        next_state();
    };

   protected:
    // update the internal states used to control the colors
    virtual void next_state() = 0;
    // assign color to each point on the curve based on the internal states
    virtual void set_colors(LEDCurve* ledCurve) = 0;
};
}  // namespace LEDGeometry
