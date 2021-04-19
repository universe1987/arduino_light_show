#pragma once
#include "LightEffect.h"

namespace LEDGeometry {
class LEDCurve;

class PulseEffect : public LightEffect {
   public:
    PulseEffect();
    PulseEffect(int beats_per_minute);

   protected:
    void update(LEDCurve* led_curve);

   private:
    int beats_per_minute;
};
}  // namespace LEDGeometry
