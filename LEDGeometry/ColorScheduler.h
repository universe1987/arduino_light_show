#pragma once
#include <FastLED.h>
#include <stdint.h>

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
    ColorScheduler(uint16_t cycle, uint8_t hue, uint8_t min_hue_delta,
                   uint8_t max_hue_delta);
    ColorScheduler(uint16_t cycle);
    // Returns a color and increment the state.
    CRGB next_color();
    // Set a new cycle and scale the progress accordingly.
    void set_cycle(uint16_t new_cycle);
    // Returns the progress with respect to the cycle, scaled to 0 ~ 255.
    uint8_t get_progress() const;

    void set_discrete_mode();
    void set_continuous_mode();

   protected:
    // Change to a new theme at the end of a cycle.
    virtual void change_theme();

   private:
    uint16_t cycle;
    uint8_t hue;
    uint8_t min_hue_delta;
    uint8_t max_hue_delta;
    uint16_t progress;
    bool discrete_mode;
    CRGB start_color;
    CRGB end_color;
    CRGB current_color;
};
}  // namespace LEDGeometry
