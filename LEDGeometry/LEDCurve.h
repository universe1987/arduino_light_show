#pragma once
#include <FastLED.h>

namespace LEDGeometry {
class Shape;
class ColorScheduler;
class LightEffect;

class LEDCurve {
   public:
    LEDCurve(CRGB* leds, Shape* shape, ColorScheduler* color_scheduler,
             bool folded);

    ~LEDCurve();
    /* This is the only method you need in Arduino IDE. */
    // Pass control to the light effect.
    void set_effect(LightEffect* effect, int n_seconds, int fps);

    // Handle folded curve and display the assigned color of the LEDs.
    void display(int sleep_ms);

    /* The following methods are helpful when implementing new light effects.*/
    // Get and set color for each individual LED light.
    CRGB& led(int i) { return leds[i]; }

    // Shape related methods:
    // Number of points on the shape, this can be different from the actual
    // number of points on the LED light if it is folded.
    int n_points() const;
    // x coordinate, -1 <= x <= 1
    float x(int i) const;
    // y coordinate, -1 <= y <= 1
    float y(int i) const;
    // Euclidean distance to the origin, -1 <= r <= 1
    float r(int i) const;

    // Color related methods:
    // Returns a color and increment the state.
    CRGB next_color();
    // Set a new cycle and scale the progress accordingly.
    void set_cycle(int new_cycle);
    // Returns the progress with respect to the cycle, scaled to 0 ~ 255.
    uint8_t get_progress() const;

   private:
    CRGB* leds;
    Shape* shape;
    ColorScheduler* color_scheduler;
    bool folded;
};
}  // namespace LEDGeometry
