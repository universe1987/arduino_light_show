#pragma once

namespace LEDGeometry {
class LEDCurve;

class SpiralEffect {
   public:
    SpiralEffect(int cycle, int n_segments);

   protected:
    void next_state();
    void set_color(LEDCurve* led_curve);

   private:
    int pos;
    int cycle;
    int n_segments;
    CRGB current_color;
};
}  // namespace LEDGeometry
