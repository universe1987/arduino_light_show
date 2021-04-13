#pragma once
#include <FastLED.h>

#include "DynamicEffect.h"

namespace LEDGeometry {
class LEDCurve;

class BurstEffect : public DynamicEffect {
   public:
    BurstEffect(int cycle);
    BurstEffect(int cycle, float min_radius, float max_radius, int resolution,
                int frequency);
    ~BurstEffect();

   private:
    float min_radius;
    float max_radius;
    int resolution;
    int frequency;
    CRGB* spectrum;

    int next_hue() const;
    void next_state();
    void set_color(LEDCurve* ledCurve);
};
}  // namespace LEDGeometry
