#pragma once
#include <FastLED.h>

#include "LightEffect.h"

namespace LEDGeometry {
class LEDInterface;

class DynamicEffect : public LightEffect {
   public:
    DynamicEffect(int period);
    int next_hue() const;
    virtual void next_state();
    virtual void set_colors(LEDInterface* ledCurve) = 0;
    const CRGB& get_current_color() const { return current_color; }

   private:
    int period;
    int progress;
    int hue;
    CRGB previous_color;
    CRGB current_color;
    CRGB next_color;
};
}  // namespace LEDGeometry
