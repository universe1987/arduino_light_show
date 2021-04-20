#pragma once
#include <stdint.h>

#include "LightEffect.h"

namespace LEDGeometry {
class LEDCurve;
typedef int (*projection)(int, float, float);

// Adapted from Fire2012 by Mark Kriegsman, July 2012, as part of "Five
// Elements" shown here: http://youtu.be/knWiGsmgycY
class FlameEffect : public LightEffect {
   public:
    FlameEffect(int resolution, projection p_func);
    FlameEffect(int resolution, int cooling, int sparking, projection p_func);
    ~FlameEffect();

   protected:
    void update(LEDCurve* led_curve);
    void update_heat();

   private:
    uint8_t cooling;
    uint8_t sparking;
    int resolution;
    uint8_t* heat;
    projection p_func;
};
}  // namespace LEDGeometry
