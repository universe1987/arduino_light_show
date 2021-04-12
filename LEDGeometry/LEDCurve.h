#pragma once
#include <FastLED.h>

#include "LightEffect.h"
#include "Shape.h"

namespace LEDGeometry {
class LEDCurve {
   public:
    LEDCurve(CRGB* leds, Shape* shape, bool folded)
        : leds_(leds), shape_(shape), folded(folded){};
    ~LEDCurve() {
        delete[] leds_;
        delete shape_;
    }
    // colors of the LEDs
    CRGB* leds() { return leds_; }
    Shape* shape() { return shape_; }
    // number of points to control
    // can be different from the actual number of points on the LED light if it is folded
    int n_points() const { return shape_->n_points(); };
    float x(int i) const { return shape_->x(i); }
    float y(int i) const { return shape_->y(i); }
    float r(int i) const { return shape_->r(i); }
    void display(int sleep_ms);
    void set_effect(LightEffect* effect, int n_seconds, int fps);

   private:
    CRGB* leds_;
    Shape* shape_;
    bool folded;
};
}  // namespace LEDGeometry
