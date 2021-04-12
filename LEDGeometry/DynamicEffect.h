#pragma once
#include <FastLED.h>

#include "LightEffect.h"

namespace LEDGeometry {
class LEDCurve;

class DynamicEffect : public LightEffect {
   public:
    DynamicEffect(int period, int min_hue_delta, int max_hue_delta);
    int next_hue() const;
    virtual void next_state();
    virtual void set_colors(LEDCurve* ledCurve) = 0;
    const CRGB& get_current_color() const { return current_color; }
    int get_progress() const { return progress; }

   private:
    int period;
    int progress;
    int hue;
    int min_hue_delta;
    int max_hue_delta;
    CRGB previous_color;
    CRGB current_color;
    CRGB next_color;
};
}  // namespace LEDGeometry
