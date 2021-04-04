#pragma once
#include <FastLED.h>

namespace LEDGeometry {
class LEDCurve {
public:
    LEDCurve(int n_leds, CRGB* leds);
    ~LEDCurve();

    // x_coords, y_coords are normalized between -1 and 1, will be quantized to int16_t in order to save space.
    void set_x(float x_coords[]);
    void set_y(float y_coords[]);

    int n_leds() const {return n_leds_;}
    CRGB* leds() {return leds_;}
    float x(int i) const {return (float)x_coords[i] / 10000;}
    float y(int i) const {return (float)y_coords[i] / 10000;}
    float norm(int i) const;

private:
    int n_leds_;
    CRGB* leds_;
    int16_t* x_coords;
    int16_t* y_coords;
};
}
