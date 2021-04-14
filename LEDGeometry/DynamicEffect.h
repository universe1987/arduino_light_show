#pragma once
#include <FastLED.h>

#include "LightEffect.h"

namespace LEDGeometry {
class LEDCurve;

class DynamicEffect : public LightEffect {
   public:
    /**
     * Set one color per frame and change the color regularly.
     *
     * Within each cycle, the color changes from start_color to end_color with
     * constant speed, starting from the next cycle, the end_color becomes the
     * start_color, and next_color method generates the new end_color.
     *
     * @param cycle Number of frames to completely change to the next color.
     */
    DynamicEffect(int cycle);
    // current color of the frame
    const CRGB& get_current_color() const { return current_color; }
    // progress with respect to the cycle
    int get_progress() const { return progress; }

   protected:
    virtual CRGB next_color() const;
    virtual void next_state();

   private:
    int cycle;
    int progress;
    CRGB start_color;
    CRGB end_color;
    CRGB current_color;
};
}  // namespace LEDGeometry
