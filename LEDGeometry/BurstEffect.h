#pragma once
#include <FastLED.h>

#include "DynamicEffect.h"

namespace LEDGeometry {
class LEDCurve;

class BurstEffect : public DynamicEffect {
   public:
    BurstEffect(int period);
    BurstEffect(int period, int min_hue_delta, int max_hue_delta,
                float min_radius, float max_radius, int resolution,
                int wave_period);
    ~BurstEffect();
    int next_hue() const;
    void next_state();
    void set_color(LEDCurve* ledCurve);

   private:
    float min_radius;
    float max_radius;
    int resolution;
    int wave_period;
    CRGB* spectrum;
};
}  // namespace LEDGeometry
