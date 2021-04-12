#pragma once
#include <FastLED.h>

#include "DynamicEffect.h"

namespace LEDGeometry {
class LEDCurve;

class PulseEffect : public DynamicEffect {
   public:
    PulseEffect(int period);
    PulseEffect(int period, int min_hue_delta, int max_hue_delta);
    void set_colors(LEDCurve* ledCurve);
    int get_brightness() const;
    void next_state();

   private:
    int clock;
};
}  // namespace LEDGeometry
