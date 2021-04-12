#pragma once
#include <FastLED.h>

#include "DynamicEffect.h"

namespace LEDGeometry {
class LEDCurve;

class SignalTransmissionEffect : public DynamicEffect {
   public:
    SignalTransmissionEffect(int period);
    SignalTransmissionEffect(int period, int min_hue_delta, int max_hue_delta, int fade_delta);
    void next_state();
    void set_colors(LEDCurve* ledCurve);

   private:
    int fade_delta;
    int pos;
};
}  // namespace LEDGeometry
