#pragma once
#include <FastLED.h>

#include "DynamicEffect.h"

namespace LEDGeometry {
class LEDCurve;

class UniformDynamicEffect : public DynamicEffect {
   public:
    UniformDynamicEffect(int cycle);

   protected:
    void set_colors(LEDCurve* led_curve);
};
}  // namespace LEDGeometry
