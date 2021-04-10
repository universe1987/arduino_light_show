#pragma once
#include <FastLED.h>

#include "DynamicEffect.h"

namespace LEDGeometry {
class LEDCurve;

class SignalTransmissionEffect : public DynamicEffect {
   public:
    SignalTransmissionEffect(int period);
    void next_state();
    void set_colors(LEDCurve* ledCurve);

   private:
    int pos;
};
}  // namespace LEDGeometry
