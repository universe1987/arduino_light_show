#pragma once
#include <FastLED.h>

#include "LightEffect.h"

namespace LEDGeometry {
class LEDCurve;

class UniformEffect : public LightEffect {
   public:
    UniformEffect(int period);
    int next_hue() const;
    void next_state();
    void set_color(LEDCurve* ledCurve);

   private:
    int period;
    int i_frame;
    int hue;
    CRGB previous_color;
    CRGB current_color;
    CRGB next_color;
};
}  // namespace LEDGeometry
