#include "LEDCurve.h"

#include <FastLED.h>

#include "ColorScheduler.h"
#include "LightEffect.h"
#include "Shape.h"

namespace LEDGeometry {
LEDCurve::LEDCurve(CRGB* leds, Shape* shape, ColorScheduler* color_scheduler,
                   bool folded)
    : leds(leds),
      shape(shape),
      color_scheduler(color_scheduler),
      folded(folded){};

LEDCurve::~LEDCurve() {
    // not free the array, LEDCurve does not own it
    delete leds;
    delete shape;
}

void LEDCurve::display(int sleep_ms) {
    if (folded) {
        int n = n_points();
        for (int i = 0; i < n; i++) {
            led(n + i) = led(n - i - 1);
        }
    }
    FastLED.show();
    FastLED.delay(sleep_ms);
}

void LEDCurve::set_effect(LightEffect* effect, int n_seconds, int fps) {
    int sleep_ms = 1000 / fps;
    int n_iters = n_seconds * fps;
    for (int i = 0; i < n_iters; i++) {
        effect->update(this);
        display(sleep_ms);
    }
}

int LEDCurve::n_points() const { return shape->n_points(); };

float LEDCurve::x(int i) const { return shape->x(i); }

float LEDCurve::y(int i) const { return shape->y(i); }

float LEDCurve::r(int i) const { return shape->r(i); }

CRGB LEDCurve::next_color() { return color_scheduler->next_color(); }

void LEDCurve::set_cycle(int new_cycle) {
    color_scheduler->set_cycle(new_cycle);
}

uint8_t LEDCurve::get_progress() const {
    return color_scheduler->get_progress();
}
}  // namespace LEDGeometry
