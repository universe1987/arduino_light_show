#pragma once
#include <FastLED.h>

namespace LEDGeometry {
class LEDInterface {
   public:
    virtual ~LEDInterface() {}

    virtual CRGB* leds() = 0;
    virtual bool is_folded() = 0;
    virtual int n_points() const = 0;
};
}  // namespace LEDGeometry
