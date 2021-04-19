#pragma once

class CRGB;
namespace LEDGeometry {
class Shape;
class ColorScheduler;
class LightEffect;

class LEDCurve {
   public:
    CRGB* leds;
    Shape* shape;
    ColorScheduler* color_scheduler;
    LEDCurve(CRGB* leds, Shape* shape, ColorScheduler* color_scheduler,
             bool folded);

    ~LEDCurve();
    /* This is the only method you need in Arduino IDE. */
    // Pass control to the light effect.
    void set_effect(LightEffect* effect, int n_seconds, int fps);

    // Handle folded curve and display the assigned color of the LEDs.
    void display(int sleep_ms);

   private:
    bool folded;
};
}  // namespace LEDGeometry
