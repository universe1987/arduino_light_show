#pragma once
#include <FastLED.h>

namespace LEDGeometry {
/**
 * Continuously changing color.
 *
 * Within each cycle, the color changes from start_color to end_color with
 * constant speed, starting from the next cycle, the end_color becomes the
 * start_color, and change_theme method generates the new end_color.
 *
 * @param cycle Number of frames to completely change to the next color.
 */
class ColorScheduler {
   public:
    ColorScheduler(int cycle, uint8_t hue, uint8_t min_hue_delta,
                   uint8_t max_hue_delta);
    ColorScheduler(int cycle);
    // Returns a color and increment the state.
    CRGB next_color();
    // Set a new cycle and scale the progress accordingly.
    void set_cycle(int new_cycle);
    // Returns the progress with respect to the cycle, scaled to 0 ~ 255.
    uint8_t get_progress() const;

   protected:
    // Change to a new theme at the end of a cycle.
    virtual void change_theme();

   private:
    int cycle;
    uint8_t hue;
    uint8_t min_hue_delta;
    uint8_t max_hue_delta;
    int progress;
    CRGB start_color;
    CRGB end_color;
    CRGB current_color;
};
}  // namespace LEDGeometry
