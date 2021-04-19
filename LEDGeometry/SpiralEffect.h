#pragma once
#include "LightEffect.h"

namespace LEDGeometry {
class LEDCurve;
class SpiralEffect : public LightEffect {
   public:
    SpiralEffect(int n_segments, int segment_length);

   protected:
    void update(LEDCurve* led_curve);

   private:
    int n_segments;
    int segment_length;
    int pos;
};
}  // namespace LEDGeometry
