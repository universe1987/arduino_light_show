#pragma once
#include "LightEffect.h"

namespace LEDGeometry {
class LEDCurve;

class SignalTransmissionEffect : public LightEffect {
   public:
    SignalTransmissionEffect();
    SignalTransmissionEffect(int fade_factor);

   protected:
    void update(LEDCurve* led_curve);

   private:
    int fade_factor;
    int pos;
};
}  // namespace LEDGeometry
