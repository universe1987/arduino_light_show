#pragma once
#include <FastLED.h>

#include "LightEffect.h"
namespace LEDGeometry {
class LEDCurve;

class SpiralEffect : public LightEffect {
   public:
    SpiralEffect(int cycle, int n_segments);

   protected:
    void next_state();
    void set_colors(LEDCurve* led_curve);

   private:
    int pos;
    int cycle;
    int n_segments;
    CRGB current_color;
};
}  // namespace LEDGeometry
