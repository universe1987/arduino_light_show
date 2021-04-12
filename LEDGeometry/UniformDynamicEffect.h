#pragma once
#include <FastLED.h>

#include "DynamicEffect.h"

namespace LEDGeometry {
class LEDCurve;

class UniformDynamicEffect : public DynamicEffect {
   public:
    UniformDynamicEffect(int period);
    UniformDynamicEffect(int period, int min_hue_delta, int max_hue_delta);
    void set_colors(LEDCurve* ledCurve);
};
}  // namespace LEDGeometry
