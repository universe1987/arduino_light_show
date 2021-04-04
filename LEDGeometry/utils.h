#pragma once
#include <FastLED.h>


namespace LEDGeometry {
    // get a bright color with the given hue (sat = 255, val = 255)
    CRGB bright_color(int hue);

    // lhs * (1 - weight_of_rhs) + rhs * weight_of_rhs
    CRGB interpolate(CRGB lhs, CRGB rhs, float weight_of_rhs);
}
