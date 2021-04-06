#include "utils.h"


namespace LEDGeometry {
    CRGB bright_color(int hue) {
        CHSV hsv = CHSV{(uint8_t)hue, 255, 255};
        CRGB rgb(0, 0, 0);
        hsv2rgb_rainbow(hsv, rgb);
        return rgb;
    }

    CRGB interpolate(CRGB lhs, CRGB rhs, float weight_of_rhs) {
        int r = lhs.r * (1 - weight_of_rhs) + rhs.r * weight_of_rhs;
        int g = lhs.g * (1 - weight_of_rhs) + rhs.g * weight_of_rhs;
        int b = lhs.b * (1 - weight_of_rhs) + rhs.b * weight_of_rhs;
        return CRGB{(uint8_t)r, (uint8_t)g, (uint8_t)b};
    }
}
