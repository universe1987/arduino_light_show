#pragma once
#include <FastLED.h>


namespace LEDGeometry {
    // lhs * (1 - weight_of_rhs) + rhs * weight_of_rhs
    CRGB interpolate(CRGB lhs, CRGB rhs, float weight_of_rhs);
}
