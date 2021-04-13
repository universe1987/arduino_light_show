#pragma once
#include <FastLED.h>

#include "DynamicEffect.h"

namespace LEDGeometry {
class LEDCurve;

class SignalTransmissionEffect : public DynamicEffect {
   public:
    SignalTransmissionEffect(int cycle);
    SignalTransmissionEffect(int cycle, int fade_factor);

   private:
    int fade_factor;
    int pos;
    void next_state();
    void set_colors(LEDCurve* ledCurve);
};
}  // namespace LEDGeometry
