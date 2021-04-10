#pragma once
#include <FastLED.h>

#include "DynamicEffect.h"

namespace LEDGeometry {
class LEDInterface;

class SignalTransmissionEffect : public DynamicEffect {
   public:
    SignalTransmissionEffect(int period);
    SignalTransmissionEffect(int period, int fade_delta);
    void next_state();
    void set_colors(LEDInterface* ledCurve);

   private:
    int pos;
    int fade_delta;
};
}  // namespace LEDGeometry
