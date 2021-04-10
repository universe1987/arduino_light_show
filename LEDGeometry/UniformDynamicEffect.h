#pragma once
#include <FastLED.h>

#include "DynamicEffect.h"

namespace LEDGeometry {
class LEDInterface;

class UniformDynamicEffect : public DynamicEffect {
   public:
    UniformDynamicEffect(int period);
    void set_colors(LEDInterface* ledCurve);
};
}  // namespace LEDGeometry
