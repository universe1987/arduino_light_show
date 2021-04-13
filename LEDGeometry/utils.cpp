#include "utils.h"


namespace LEDGeometry {
    CRGB interpolate(CRGB lhs, CRGB rhs, float weight_of_rhs) {
        int r = lhs.r * (1 - weight_of_rhs) + rhs.r * weight_of_rhs;
        int g = lhs.g * (1 - weight_of_rhs) + rhs.g * weight_of_rhs;
        int b = lhs.b * (1 - weight_of_rhs) + rhs.b * weight_of_rhs;
        return CRGB{(uint8_t)r, (uint8_t)g, (uint8_t)b};
    }
}
