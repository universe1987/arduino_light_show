#pragma once
#include <FastLED.h>

#include "GradualChangingColorEffect.h"

namespace LEDGeometry {
class LEDCurve;

class WaveEffect1D : public GradualChangingColorEffect {
   public:
    WaveEffect1D(int period);
    void next_state();
    void update_leds(LEDCurve* ledCurve);

   private:
    int pos;
};
}  // namespace LEDGeometry
