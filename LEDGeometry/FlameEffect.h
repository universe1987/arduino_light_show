#pragma once
#include <FastLED.h>

#include "LightEffect.h"

namespace LEDGeometry {
class LEDCurve;

class FlameEffect : public LightEffect {
   public:
    FlameEffect(int resolution, int min_y, int max_y);
    FlameEffect(int cooling, int sparking, int resolution, int min_y,
                int max_y);
    ~FlameEffect();

   protected:
    void update(LEDCurve* led_curve);

    void update_heat();

   private:
    int cooling;
    int sparking;
    int resolution;
    int min_y;
    int max_y;
    uint8_t* heat;
};
}  // namespace LEDGeometry
