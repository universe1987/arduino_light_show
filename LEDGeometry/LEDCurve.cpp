#include "LEDCurve.h"
#include <math.h>

using namespace LEDGeometry;

LEDCurve::LEDCurve(int n_leds, CRGB* leds): n_leds_(n_leds), leds_(leds) {
    x_coords = new int16_t[n_leds_];
    y_coords = new int16_t[n_leds_];
}

LEDCurve::~LEDCurve() {
    delete[] x_coords;
    delete[] y_coords;
}

void LEDCurve::set_x(float x_coords[]) {
    for (int i = 0; i < n_leds_; i++) {
      x_coords[i] = (int16_t) round(10000 * x_coords[i]);
    }
}

void LEDCurve::set_y(float y_coords[]) {
    for (int i = 0; i < n_leds_; i++) {
      y_coords[i] = (int16_t) round(10000 * y_coords[i]);
    }
}

float LEDCurve::norm(int i) const {
    float x_ = x(i);
    float y_ = y(i);
    return sqrt(x_*x_ + y_*y_);
};
