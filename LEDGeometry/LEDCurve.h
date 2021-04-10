#pragma once
#include <FastLED.h>

#include "Shape.h"
#include "LightEffect.h"
#include "LEDInterface.h"

namespace LEDGeometry {
class LEDCurve : public LEDInterface {
   public:
    LEDCurve(CRGB* leds, Shape* shape, bool folded) : leds_(leds), shape_(shape), folded(folded) {};
    ~LEDCurve() {
        delete leds_;
        delete shape_;
    }

    CRGB* leds() { return leds_; }
    Shape* shape() { return shape_; }
    bool is_folded() { return folded; }
    int n_points() const { return shape_->n_points(); };
    float x(int i) const { return shape_->x(i); }
    float y(int i) const { return shape_->y(i); }
    float r(int i) const { return shape_->r(i); }
    void set_effect(LightEffect* effect, int n_seconds, int fps) {
        int sleep_ms = 1000 / fps;
        LEDInterface* led_ptr = this;
        for (int i = 0; i < n_seconds * fps; i++) {
            effect->update_leds(led_ptr);
            effect->next_state();
            FastLED.show();
            FastLED.delay(sleep_ms);
        }
    }

   private:
    CRGB* leds_;
    Shape* shape_;
    bool folded;
};
}  // namespace LEDGeometry
