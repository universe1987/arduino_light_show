#pragma once
#include "LightEffect.h"

class CRGB;
namespace LEDGeometry {
class LEDCurve;

class BurstEffect : public LightEffect {
   public:
    BurstEffect(CRGB* spectrum, int resolution);
    BurstEffect(CRGB* spectrum, int resolution, float min_radius,
                float max_radius, int frequency);

   protected:
    void update(LEDCurve* led_curve);

   private:
    CRGB* spectrum;
    int resolution;
    float min_radius;
    float max_radius;
    int frequency;
};
}  // namespace LEDGeometry
