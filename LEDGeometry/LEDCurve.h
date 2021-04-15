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
        // not free the array, LEDCurve does not own it
        delete leds_;
        delete shape_;
    }
    // array of the LED colors
    CRGB* leds() { return leds_; }
    // shape of the curve
    Shape* shape() { return shape_; }
    // number of points on the shape, this can be different from the actual number of points on the
    // LED light if it is folded.
    int n_points() const { return shape_->n_points(); };
    // x coordinate, -1 <= x <= 1
    float x(int i) const { return shape_->x(i); }
    // y coordinate, -1 <= y <= 1
    float y(int i) const { return shape_->y(i); }
    // Euclidean distance to the origin
    float r(int i) const { return shape_->r(i); }
    // display the assigned color of the LEDs
    void display(int sleep_ms);
    // pass control to the light effect
    void set_effect(LightEffect* effect, int n_seconds, int fps);

   private:
    CRGB* leds_;
    Shape* shape_;
    bool folded;
};
}  // namespace LEDGeometry
