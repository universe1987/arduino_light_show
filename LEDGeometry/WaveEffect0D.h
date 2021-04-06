#pragma once
#include <FastLED.h>

#include "GradualChangingColorEffect.h"

namespace LEDGeometry {
class LEDCurve;

class WaveEffect0D : public GradualChangingColorEffect {
   public:
    WaveEffect0D(int period);
    void update_leds(LEDCurve* ledCurve);
};
}  // namespace LEDGeometry
