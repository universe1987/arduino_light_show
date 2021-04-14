#pragma once
#include <FastLED.h>

#include "DynamicEffect.h"

namespace LEDGeometry {
class LEDCurve;

class PulseEffect : public DynamicEffect {
   public:
    PulseEffect(int cycle);
    PulseEffect(int cycle, int beats_per_minute);

   private:
    int beats_per_minute;
    void set_colors(LEDCurve* ledCurve);
};
}  // namespace LEDGeometry
