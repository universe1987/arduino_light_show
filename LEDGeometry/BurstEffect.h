#pragma once
#include <FastLED.h>

#include "LightEffect.h"

namespace LEDGeometry {
class LEDCurve;

class BurstEffect : public LightEffect {
   public:
    BurstEffect();
    BurstEffect(float min_radius, float max_radius, int resolution,
                int frequency);
    ~BurstEffect();

   protected:
    void update(LEDCurve* led_curve);

   private:
    float min_radius;
    float max_radius;
    int resolution;
    int frequency;
    CRGB* spectrum;
};
}  // namespace LEDGeometry
