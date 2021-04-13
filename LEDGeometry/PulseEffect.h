#pragma once
#include <FastLED.h>

#include "DynamicEffect.h"

namespace LEDGeometry {
class LEDCurve;

class PulseEffect : public DynamicEffect {
   public:
    PulseEffect(int cycle);

   private:
    int clock;
    int get_brightness() const;
    void set_colors(LEDCurve* ledCurve);
    void next_state();
};
}  // namespace LEDGeometry
