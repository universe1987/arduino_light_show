#pragma once
#include <FastLED.h>

#include "LightEffect.h"

namespace LEDGeometry {
class LEDCurve;

class BurstEffect : public LightEffect {
   public:
    BurstEffect(float r_min, float r_max, int resolution);
    ~BurstEffect();
    int next_hue() const;
    void next_state();
    void set_color(LEDCurve* ledCurve);

   private:
    float r_min;
    float r_max;
    int resolution;
    int i_frame;
    int pos;
    int hue;
    CRGB current_color;
    CRGB future_color;
    CRGB* spectrum;
};
}  // namespace LEDGeometry