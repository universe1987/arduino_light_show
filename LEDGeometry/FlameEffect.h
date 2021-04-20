#pragma once
#include <stdint.h>

#include "LightEffect.h"

namespace LEDGeometry {
class LEDCurve;

// Adapted from Fire2012 by Mark Kriegsman, July 2012, as part of "Five
// Elements" shown here: http://youtu.be/knWiGsmgycY
class FlameEffect : public LightEffect {
   public:
    FlameEffect(int resolution, float min_y, float max_y);
    FlameEffect(int cooling, int sparking, int resolution, float min_y,
                float max_y);
    ~FlameEffect();

   protected:
    void update(LEDCurve* led_curve);

    void update_heat();

   private:
    uint8_t cooling;
    uint8_t sparking;
    int resolution;
    float min_y;
    float max_y;
    uint8_t* heat;
};
}  // namespace LEDGeometry
