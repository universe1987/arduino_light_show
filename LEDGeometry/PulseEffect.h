#pragma once
#include <FastLED.h>

#include "DynamicEffect.h"

namespace LEDGeometry {
class LEDInterface;

class PulseEffect : public DynamicEffect {
   public:
    PulseEffect(int period);
    void set_colors(LEDInterface* ledCurve);
    int get_brightness() const;
    void next_state();

   private:
    int clock;
};
}  // namespace LEDGeometry
