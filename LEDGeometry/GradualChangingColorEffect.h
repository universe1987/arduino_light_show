#pragma once
#include <FastLED.h>

#include "LightEffect.h"

namespace LEDGeometry {
class LEDCurve;

class GradualChangingColorEffect : public LightEffect {
   public:
    GradualChangingColorEffect(int period);
    int next_hue() const;
    virtual void next_state();
    virtual void update_leds(LEDCurve* ledCurve) = 0;
    const CRGB& get_color() const { return color; }

   private:
    int period;
    int progress;
    int hue;
    CRGB previous_color;
    CRGB color;
    CRGB next_color;
};
}  // namespace LEDGeometry
